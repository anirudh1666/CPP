#ifndef GUARD_PTR_H
#define GUARD_PTR_H

class Item;
class Inventory;

#include "Item.h"

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <string>

class Ptr {
public:
	// Constructors.
	Ptr() : refptr(new size_t(1)), p(0) { }

	Ptr(Item& it) : refptr(new size_t(1)), p(&it) { }

	Ptr(const Ptr& h) : refptr(h.refptr), p(h.p) { ++*refptr; }

	// Destructor.
	~Ptr();

	// Operators.
	Ptr& operator=(const Ptr&);
	operator bool() const;
	Item& operator*() const;
	Item* operator->() const;

private:
	Item* p;
	size_t* refptr;
};

#endif