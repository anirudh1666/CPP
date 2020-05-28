#include "Inventory.h"

using std::string;

// Auxiliary function for Inventory::display and Inventory::search.
void print_item(const Item& item, std::ostream& os) {

	os << item.barcode << ", "
		<< item.price << ", "
		<< item.stock;
}

void Inventory::search(const string& item, std::ostream& os) const {

	std::map<string, Item>::const_iterator it = inventory.find(item);

	if (it == inventory.end()) {
		// Item not found in inventory.
		throw std::runtime_error("Item was not found.");
	}

	os << it->second.name << ": ";
	print_item(it->second, os);
	os << std::endl;
}

void Inventory::add(const Item& it) {
	
	inventory.insert(std::make_pair(it.name, it));
}

void Inventory::remove(const string& item) {
	
	std::map<string, Item>::iterator it = inventory.find(item);

	if (it == inventory.end()) {
		// Item not found in inventory.
		throw std::runtime_error("Item was not found.");
	}

	inventory.erase(it);
	std::cout << item << " was erased succesfully!\n";
}



/* Uses jsoncpp to parse and save inventory into .txt file.
   @params = os : output stream to file that you want to save your
                  data to.
*/
void Inventory::save(std::ofstream& os) const {

	Json::Value obj;

	for (std::map<string, Item>::const_iterator it = inventory.begin();
		it != inventory.end(); ++it) {
		string name = it->first;
		
		/* E.g. Item = Chocolate, 231234, 2.50, 235.
		   Output: {
		               "Chocolate" :
					   {
								    "name" : Chocolate
									"barcode" : 231234
									"price" : 2.50
									"stock" : 235
						}
					}
		*/
		obj[name]["name"] = it->first;
		obj[name]["barcode"] = it->second.barcode;
		obj[name]["price"] = it->second.price;
		obj[name]["stock"] = it->second.stock;

		os << obj << std::endl;
	}

}

void Inventory::display(std::ostream& os) const {
	
	os << std::endl;
	for (std::map<string, Item>::const_iterator it = inventory.begin();
		it != inventory.end(); ++it) {
		// Print name.
		os << it->first << ": ";
		// Print rest of details.
		print_item(it->second, os);
		os << std::endl;
	}
}