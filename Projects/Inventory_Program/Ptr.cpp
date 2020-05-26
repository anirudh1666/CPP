/* This is a handle class designed to manage the underlying
 * memory.
 */

#include "Declarations.h"

class Ptr {
public:
	// Constructors.
	// Empty constructor. p points to 0.
	Ptr(): refptr(new size_t(1)), p(0) { }

	// Makes p point to item given.
	Ptr(Item item): refptr(new size_t(1)), p(item) { }

	Ptr(const Ptr& h): refptr(h.refptr), p(h.p) { ++*refptr; }


	// Destructor.
	~Ptr();


	// Operators.
	Ptr& operator=(const Ptr&);

	// Check if p points to valid object.
	// Returns 0 if not.
	operator bool() const { return p; }

	Item& operator*() const {

		if (p) {
			return *p;
		}
		throw std::runtime_error("Unbound pointer.");
	}

	Item* operator->() const {

		if (p) {
			return p;
		}
		throw std::runtime_error("Unbound pointer.");
	}

private:
	Item* p;
	size_t* refptr;
};

Ptr& Ptr::operator=(const Ptr& rhs) {

	// Increment since 1 more p will reference it.
	++*rhs.refptr;

	// If no refptr = 0, then lhs can be deleted safely.
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}

	refptr = rhs.refptr;
	p = rhs.p;

	return *this;
}


Ptr::~Ptr() {

	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}
}
