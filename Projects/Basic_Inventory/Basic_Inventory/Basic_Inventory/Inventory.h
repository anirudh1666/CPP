#ifndef GUARD_INVENTORY_H
#define GUARD_INVENTORY_H

/* This file holds definition for our struct item along with
   declaration for class Inventory which holds a map<string, *Item>.
*/

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <fstream>
#include <C:\Users\aniru\OneDrive\Documents\C++\vcpkg\installed\x86-windows\include\json\json.h>

/* Rather than use class, better to use struct since Item only needs to 
   hold information about itself. 
   Syntax = Item a_item = {name, barcode, price, stock};
*/
struct Item {
	std::string name;
	std::string barcode;
	double price;
	int stock;
};


/* This class manages the inventory data and all its member functions
   deal with managing the item data.
*/
class Inventory {
public:
	void search(const std::string&, std::ostream&) const;
	void display(std::ostream&) const;
	void add(const Item&);
	void remove(const std::string&);
	void save(std::ofstream&) const;

private:
	std::map<std::string, Item> inventory;
};

// Auxiliary functions.
void print_item(const Item&, std::ostream&);

#endif
