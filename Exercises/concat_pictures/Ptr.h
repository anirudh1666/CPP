/* This is a handle class that uses code from
 * Accelerated C++, Chapter 14. Ptr is designed to
 * behave as pointers but avoiding pitfalls of constantly
 * managing memory by delegating it to Ptr.
 * This class is designed to work with Str class but
 * can be extended or changed to work for with other classes.
 */

#ifndef PTR_H_
#define PTR_H_

#include <stdexcept>

template<class T> class Ptr {

public:
	/* Copies object conditionally if needed.
	 * If more than 1 Ptr points to p then make new.
	 */
	void make_unique() {

		if (*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			p = p ? p->clone() : 0;
		}
	}

	// Constructors and destructors.
	// Makes empty object.
	Ptr(): refptr(new size_t(1)), p(0) { }

	// Makes object from new object t.
	// E.g. Ptr<Student_info> ptr (new Student_info);
	Ptr(T* t): refptr(new size_t(1)), p(t) { }

	// Copy constructor. Works by copying members from h.
	Ptr(const Ptr& h): refptr(h.refptr), p(h.p) { ++*refptr; }

	~Ptr();


	// Operators.
	Ptr& operator=(const Ptr&);

	// Used to check if Ptr points to an object or 0.
	operator bool() const { return p; }

	T& operator*() const {

		if (p) {
			// Return value of object.
			return *p;
		}
		throw std::runtime_error("Unbound handle.");
	}

	T* operator->() const {

		if (p) {
			// Return pointer to object.
			return p;
		}
		throw std::runtime_error("Unbound handle.");
	}

private:
	// Pointer to object.
	T* p;

	// Holds count of number of Ptrs pointing to same object.
	size_t* refptr;
};


template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs) {

	// Increment since 1 more object points to rhs.
	++*rhs.refptr;

	// If decrementing refptr = 0 then no Ptrs to object,
	// can delete safely. Even if it isnt = 0, refptr doesn't
	// change since we incremented it.
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}

	// refptr is a ptr to size_t so they point to same size_t.
	// Allows both ptrs to update refptr.
	refptr = rhs.refptr;
	p = rhs.p;

	return *this;
}

template<class T>
Ptr<T>::~Ptr() {

	// Only delete if 0 Ptrs point to object p.
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}
}




#endif
