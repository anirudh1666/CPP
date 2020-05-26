#include "Declarations.h"

using std::map;              using std::string;
using std::make_pair;        using std::ostream;

/* Needs to hold a data structure with pointers to item objects.
 * TODO: maybe add more constructors.
 */
class Inventory {
public:
	// Constructors.
	Inventory(): inventory(new map<string, Ptr>);


	// Destructor not needed as Ptr destroys Items for us.


	// Utility members.
	Item search(const string& name) const;

	void add(const Item& name);
	void delete(const string& name);
	void display(ostream&) const;


private:
	map<string, Ptr> inventory;
};


void Inventory::add(const Item& item) {

	Ptr p (item);
	inventory.insert(make_pair(item.name(), p));
}

void Inventory::display(ostream& os) {

	for (std::map<string, Ptr>::iterator it = inventory.begin();
		 it != inventory.end(); ++it) {
		os << it->first << ": " << print_item(it->second, os) << endl;
	}
}


