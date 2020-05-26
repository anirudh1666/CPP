#include "Declarations.h"

using std::cout;          using std::endl;
using std::cin;


void welcome_message() {

	cout << "Hello, this is an inventory managing program meant for"
			" small businesses to use. It was made by Anirudh Lakra,"
			" 26/05/2020.\n\n";
}

void init_data(Inventory& inven) {

	Item sample_1 ("Socks", "20232892", 6.23, 10);
	Item sample_2 ("Chocolate", "93820579", 1.00, 20);
	Item sample_3 ("Milk", "54342092", 1.50, 24);

	inven.add(sample_1);
	inven.add(sample_2);
	inven.add(sample_3);
}

Inventory init_inventory() {

	Inventory ret;
	init_data(ret);

	return ret;
}


void run() {

	welcome_message();
	Inventory inventory = init_inventory();
	bool running = true;
	int option = -1;

	while (running) {
		cout << "Choose an option from below.\n\n"
			    "1) Search for item.\n"
				"2) Add an item.\n"
				"3) Delete an item.\n"
				"4) Display current inventory.\n"
				"5) Exit.\n\n";
		cout << "Enter choice: ";
		cin >> option;
		cin.clear();

		switch (option) {
		case 1: search_for_item(inventory); continue;

		case 2: add_item(inventory); continue;

		case 3: delete_item(inventory); continue;

		case 4: display_inventory(inventory); continue;

		case 5: running = false; continue;

		default: cout << "Invalid option. Try again.\n"; continue;
		}
	}
}

int main() {

	run();
	return 0;
}
