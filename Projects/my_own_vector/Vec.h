/* This project is an implementation of the class vector
   in the standard library. The code mainly comes from 
   Accelerated C++, Chapter 11.
*/

#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <iostream>
#include <memory>

using std::allocator;            using std::uninitialized_fill;
using std::uninitialized_copy;   using std::max;

template <class T> class Vec {
	public:
		// Some type definitions for our class.
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;
		
		// Constructors.
		Vec() { create(); }
		
		// explicit means you have to use Vec object explicitly.
		// doesnt allow the compiler to implicitly convert other types to
		// class type Vec.
		// If t is not supplied use default constructor for that type.
		explicit Vec(size_type n, const T& t = T()) { create(n, t);}
		Vec(const Vec& v) { create(v.begin(), v.end()); }
		~Vec() { uncreate(); }
		
		// Operator definitions.
		// Left type is lhs and (param) is the rhs.
		// If operator is unary then left type refers to this type.
		Vec& operator=(const Vec&);
		T& operator[](size_type i) { return start[i]; }
		const T& operator[](size_type i) const { return start[i]; }
		
		// Utility members.
		void push_back(const T& t){
		
			if (avail == limit)
				grow();
			unchecked_append(t);
		}
		
		size_type size() const { return avail - start; }
		
		iterator begin() { return start; }
		const_iterator begin() const { return start; }
		iterator end() { return avail; }
		const_iterator end() const { return avail; }
		
	private:
		// class variables.
	
		// First element in Vec.
		iterator start;

		// 1 past the last used element.
		iterator avail;

		// 1 past the last possible element.
		iterator limit;
		
		// Memory management members.
		// alloc deals with memory.
		allocator<T> alloc;
		
		// Allocate memory and initialize array.
		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);
		
		// Destroy array and free memory.
		void uncreate();
		
		// Helper members for push_back.
		void grow();
		void unchecked_append(const T&);
};

template <class T>
void Vec<T>::create() {
	
	start = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
	
	start = alloc.allocate(n);
	limit = avail = start + n;
	uninitialized_fill(start, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
	
	start = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, start);
}

template <class T>
void Vec<T>::uncreate() {
	
	if (start) {
		// Destroy elements in reverse order.
		iterator it = avail;
		while (it != start)
			alloc.destroy(--it);
		
		alloc.deallocate(start, limit - start);
	}
	
	start = limit = avail = 0;
}

template <class T>
void Vec<T>::grow() {
	
	// max takes 2 of same type which is why we use ptrdiff_t.
	// if limit - start = 0 then we just allocate 1.
	size_type new_size = max(2 * (limit - start), ptrdiff_t(1));
	
	// Cant just update start or avail since they point to same object.
	iterator new_start = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(start, avail, new_start);
	
	uncreate();
	
	start = new_start;
	avail = new_avail;
	limit = start + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
	
	alloc.construct(avail++, val);
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	
	return *this;
}

#endif
