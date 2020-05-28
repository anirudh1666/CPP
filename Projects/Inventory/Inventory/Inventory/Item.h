#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

class Ptr;
class Inventory;

#include "Ptr.h"

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <string>

class Item {
public:
	// Constructors.
	Item(std::string, std::string, double, int);

	// Getters and setters.
	inline std::string get_name() const;
	inline std::string get_barcode() const;
	inline double get_price() const;
	inline int get_stock() const;

	inline void set_name(const std::string&);
	inline void set_barcode(const std::string&);
	inline void set_price(const double);
	inline void update_stock(const int);

private:
	std::string name;
	std::string barcode;
	double price;
	int stock;
};

#endif