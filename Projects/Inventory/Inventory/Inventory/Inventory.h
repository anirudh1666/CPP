#ifndef GUARD_INVENTORY_H
#define GUARD_INVENTORY_H

class Item;
class Ptr;

#include "Ptr.h"

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <string>

class Inventory {
public:
	// Synthesised constructors and destructors suffice.

	// Utility members.
	void search(const std::string&) const;
	void add(Item&);
	void remove(const std::string&);
	void display(std::ostream&) const;

private:
	std::map<std::string, Ptr> inventory;
};

#endif