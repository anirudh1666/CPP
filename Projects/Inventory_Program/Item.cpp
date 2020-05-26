#include "Declarations.h"

using std::string;

// POSSIBLE SOURCE OF ERROR CHECK IF you can name constructors
// the same as private variables.

class Item {
public:
	// Constructors.
	Item(): name(new string), barcode(new string),
		    price(0.0), no_in_stock(0) { }

	Item(string name, string barcode, double price,
		 int stock): name(name), barcode(barcode),
		price(price), stock(stock) { }


	// Destructor not needed. Synthesised one works.

	// Getter and setters members.
	inline string name() const { return name; }
	inline string barcode() const { return barcode; }
	inline double price() const { return price; }
	inline int stock() const { return stock; }

	inline void set_name(const string& name) { name = name; }
	inline void set_barcode(const string& barcode) { barcode = barcode; }
	inline void set_price(const double price) { price = price; }
	inline void update_stock(const int stock) { stock = stock; }


private:
	string name;
	string barcode;
	double price;
	int stock;
};


void print_item(const Ptr& p, std::ostream& os) {

	os << p->name() << ", " << p->barcode() << ", "
	   << p->price() << ", " << p->stock();
}
