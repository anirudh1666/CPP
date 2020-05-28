#include "Inventory.h"

using std::string;            using std::ostream;

void print_item(const Ptr&, ostream&);

// UPDATE TO RETURN ITEM&
void Inventory::search(const string& name) const {

	// TODO
}

void Inventory::add(Item& item) {

	Ptr p(item);
	inventory.insert(std::make_pair(item.get_name(), p));
}

void Inventory::remove(const string& name) {

	// TODO
}

void Inventory::display(ostream& os) const {

	for (std::map<string, Ptr>::const_iterator it = inventory.begin();
		it != inventory.end(); ++it) {
		os << it->first << ": ";
		print_item(it->second, os);
		os << std::endl;
	}
}

