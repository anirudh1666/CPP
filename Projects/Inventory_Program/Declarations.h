/* This program is an inventory program for a small business.
 * Made by Anirudh Lakra, 26/05/2020.
 */

#ifndef GUARD_DECLARATIONS_H
#define GUARD_DECLARATIONS_H

#include <iostream>
#include <stdexcept>
#include <map>

// Handle class designed to manage memory.
class Ptr;
Ptr::Ptr();
Ptr::Ptr(Item::Item);
Ptr::Ptr(const Ptr::Ptr&);

Ptr::~Ptr();

Ptr& Ptr::operator=(const Ptr::Ptr&);
Item& Ptr::operator*() const;
Item* Ptr::operator->() const;


// Class designed to represent each object.
class Item;
Item::Item();
Item::Item(std::string, std::string, double, int);

inline string Item::name() const;
inline string Item::barcode() const;
inline double Item::price() const;
inline int Item::stock() const;

inline void Item::set_name(const std::string&)
inline void Item::set_barcode(const std::string&);
inline void Item::set_price(const double);
inline void Item::update_stock(const int);


// Holds Map<Key, Ptr>. Also contains all functionality members
// such as searching, adding and more.
class Inventory;
Inventory::Inventory();
Item Inventory::search(const std::string&) const;

void Inventory::add(const Item::Item&);
void Inventory::delete(const std::string&);
void Inventory::display(std::ostream&) const;


// Functions in tests.
void test_display(const Inventory::Inventory&);


// Functions in main.



#endif
