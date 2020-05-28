#include "Ptr.h"

Ptr::operator bool() const {

	return p;
}

Item& Ptr::operator*() const {

	if (p) {
		return *p;
	}
	throw std::runtime_error("Unbound pointer.");
}

Item* Ptr::operator->() const {

	if (p) {
		return p;
	}
	throw std::runtime_error("Unbound pointer.");
}

Ptr& Ptr::operator=(const Ptr& rhs) {

	// Increment since 1 more p will reference it.
	++* rhs.refptr;

	// If no refptr = 0, then lhs can be deleted safely.
	if (-- * refptr == 0) {
		delete refptr;
		delete p;
	}

	refptr = rhs.refptr;
	p = rhs.p;

	return *this;
}


Ptr::~Ptr() {

	if (-- * refptr == 0) {
		delete refptr;
		delete p;
	}
}
