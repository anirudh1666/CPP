/* This is my own implementation of the standard library 
   class List. Exercise in chapter 11 of Accelerated C++.
   It is simpler than std::list since it uses an array rather
   than doubly linked list and only implements iterators.
*/

#ifndef GUARD_MyList_h
#define GUARD_MyList_h

#include <iostream>
#include <memory>

using std::allocator;            using std::uninitialized_fill;
using std::uninitialized_copy;   using std::max;


template <class T> class MyList {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
		
		// Empty constructor. Init variables to 0.
		MyList() { create(); }
		
		// Construct list of size n filled with value t.
		explicit MyList(size_type n, T& t = T()) { create(n, t);	}
		
		// Copy values from list into new MyList.
		MyList(const MyList& list) { create(list.get_front(), list.get_back()); }
		
		MyList& operator=(const MyList&);
		
		~MyList() { uncreate(); }
		
		// Iterator members.
		iterator get_front() { return front; }
		const_iterator get_front() const { return front; }
		
		iterator get_back() { return back; }
		
		const_iterator get_back() const { return back; }
		
		size_type size() { return back - front; }
		
		void push_back(const T& val) {
			
			// No space so double size of MyList and copy into new MyList.
			if (front == limit)
				grow();
			unchecked_append(val);
		}
	
	private:
		// Class variables.
		// First element in MyList.
		iterator front;
		
		// 1 past the last used element in MyList.
		iterator back;
		
		// 1 past the last possible element in MyList.
		iterator limit;
		
		// Memory management members.
		allocator<T> alloc;
		
		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);
		
		void uncreate();
		
		// Helper members for push_back.
		void grow();
		void unchecked_append(const T&);		
};

template <class T>
void MyList<T>::create() {
	
	front = back = limit = 0;
}

template <class T>
void MyList<T>::create(size_type n, const T& val) {
	
	front = alloc.allocate(n);
	limit = back = front + n;
	uninitialized_fill(front, limit, val);
}

template <class T>
void MyList<T>::create(const_iterator i, const_iterator j) {
	
	front = alloc.allocate(j - i);
	limit = back = uninitialized_copy(i, j, front);
}

template <class T>
void MyList<T>::uncreate() {
	
	if (front) {
		// Destroy in reverse order.
		iterator it = back;
		while (it != front)
			alloc.destroy(--it);
		
		alloc.deallocate(front, limit - front);
	}
	
	front = limit = back = 0;
}

template <class T>
MyList<T>& MyList<T>::operator=(const MyList& list) {
	
	if (&list != this) {
		uncreate();
		create(list.get_front(), list.get_back());
	}
	
	return *this;
}

template <class T>
void MyList<T>::grow() {
	
	size_type new_size = max(2 * (limit - front), ptrdiff_t(1));
	iterator new_front = alloc.allocate(new_size);
	iterator new_back = uninitialized_copy(front, back, new_front);
	
	uncreate();
	front = new_front;
	back = new_back;
	limit = front + new_size;
}

template <class T>
void MyList<T>::unchecked_append(const T& val) {
	
	alloc.construct(back++, val);
}

#endif
