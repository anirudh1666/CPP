// This program is a statistics calculator made by Anirudh Lakra.

#include "statistics.h"


using std::cout;                            using std::cin;
using std::endl;                            using std::vector;
using std::domain_error;


// remember to catch errors.
int main() {
	
	cout << "\nThis is a statistics calculator made by Anirudh Lakra.\n\n";
	vector<double> data;
	bool running = true;
	
	while (running) {
		cout << "\nPick one of the options from below: "
			    "\n1) Add data.\n2) Remove data.\n"
			    "3) Calculate average.\n4) Calculate median"
			    ".\n5) Calculate quartiles.\n6) Quit.\n";
		int option;
		cout << "Enter your choice here: ";
		cin >> option;
		cin.clear();
		
		switch (option) {
			case 1 : add_data(cin, data); continue;
			case 2 : remove_data(data); continue;
			case 3 : calc_avg(data); continue;
			case 4 : cout << "Median: " << calc_median(data) << endl; continue;
			case 5 : calc_quartiles(data); continue;
			case 6 : running = false; continue;
			default : cout << "Invalid option. Try again.\n";
		}
	}
	
	return 0;
}



