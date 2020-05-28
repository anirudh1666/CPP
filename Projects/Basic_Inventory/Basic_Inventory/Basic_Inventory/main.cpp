#include "Inventory.h"

using std::cout;            using std::cin;
using std::endl;            using std::string;

// Displays welcome message when program starts.
void welcome_message() {
	
	cout << "\nWelcome! This program is made by Anirudh Lakra, 28/05/2020\n"
		"This program is designed to manage the inventory for a small\n"
		"business.\n";
}

// Creates inventory that we will use along with 
// sample data to add into inventory.
// @returns = Inventory.
Inventory init_data() {
	
	Inventory ret;
	Item sample_1{ "milk", "210392", 1.50, 32 };
	Item sample_2{ "chocolate", "758604", 1.00, 53 };
	Item sample_3{ "socks", "5781032", 3.00, 12 };

	ret.add(sample_1);
	ret.add(sample_2);
	ret.add(sample_3);
	
	return ret;
}


// Used to display choices to user.
void display_menu() {
	cout << "\n1) Add item.\n"
		"2) Delete an item.\n"
		"3) Display inventory.\n"
		"4) Search for item.\n"
		"5) Save current inventory to file (in JSON format).\n"
		"6) Exit.\n\n";
}


Item create_item() {

	string name;
	string barcode;
	double price;
	int stock;

	cout << "\nEnter the name: ";
	cin >> name;
	cout << "Enter the barcode: ";
	cin >> barcode;
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the number in stock: ";
	cin >> stock;
	cin.clear();

	Item ret{ name, barcode, price, stock };
	return ret;
}

/* Creates an item object and adds it to inven.
   @params = inven : inventory to add item to.
*/
void add_item(Inventory& inven) {

	Item my_item = create_item();
	inven.add(my_item);
}


/* Deletes an item that user specifies by name.
   @params = inven : inventory to delete item from.
*/
void delete_item(Inventory& inven) {

	string name;
	cout << "Enter the name of the item you wish to delete: ";
	cin >> name;

	try {
		inven.remove(name);
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << endl;
	}
}


// Displays current content of inven.
// @params = inven : inventory to display.
inline void display_inventory(Inventory& inven) {

	inven.display(cout);
}

// Looks for an item in inven.
// @params = inven : inventory to search.
void search_for_item(Inventory& inven) {

	string name;
	cout << "Enter the name of the item: ";
	cin >> name;

	try {
		inven.search(name, cout);
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << endl;
	}
}

/* Saves current inventory into a .txt file in JSON format. 
   @params = inven : inventory to save.
*/
void save(Inventory& inven) {
	
	string file;
	cout << "The file should be in the same directory. Or it will"
		" create a new file with given name.\n";
	cout << "Enter the filename: ";
	cin >> file;

	std::ofstream out;
	out.open(file, std::ios::out | std::ios::trunc);
	
	if (out.is_open()) {
		// Check if file opened succesfully.
		inven.save(out);
	}
	else {
		cout << "File was unable to be opened.\n";
	}

	out.close();
}

void run() {

	welcome_message();
	Inventory inventory = init_data();
	int option = -1;
	bool running = true;

	while (running) {
		display_menu();
		cout << "Enter your choice here: ";
		cin >> option;
		cin.clear();

		switch (option) {
		case 1: add_item(inventory); continue;

		case 2: delete_item(inventory); continue;

		case 3: display_inventory(inventory); continue;

		case 4: search_for_item(inventory); continue;

		case 5: save(inventory); continue;

		case 6: running = false; continue;

		default: cout << "Invalid choice. Try again.\n"; continue;
		}
	}
}


int main() {

	run();
	return 0;
}