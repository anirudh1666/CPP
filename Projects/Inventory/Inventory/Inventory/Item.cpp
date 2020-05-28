#include "Item.h"

using std::string;

Item::Item(string name, string barcode, double price,
	int stock) : name(name), barcode(barcode),
	price(price), stock(stock) { }


inline string Item::get_name() const {

	return name;
}

inline string Item::get_barcode() const {

	return barcode;
}

inline double Item::get_price() const {

	return price;
}

inline int Item::get_stock() const {

	return stock;
}

inline void Item::set_name(const string& s) {

	name = s;
}

inline void Item::set_barcode(const string& s) {

	barcode = s;
}

inline void Item::set_price(const double p) {

	price = p;
}

inline void Item::update_stock(const int stock_no) {

	stock = stock_no;
}

void print_item(const Ptr& p, std::ostream& os) {

	os << p->get_name() << ", " << p->get_barcode() << ", "
		<< p->get_price() << ", " << p->get_stock();
}
