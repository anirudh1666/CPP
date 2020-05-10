#include "statistics.h"

using std::istream;               using std::vector;
using std::cout;                 

void add_data(istream& in, vector<double>& vec) {
	
	int option;
	cout << "\nEnter 1 to add more data. Enter 2 to clear old data"
		    " and add new data.\n";
	cout << "Enter choice here: ";
	in >> option;
	if (option == 2)
			vec.clear();
	
	cout << "Enter the data here followed by CTRL-Z: ";
	while (in >> option) 
		vec.push_back(option);
	
	
	in.clear();
}


void remove_data(vector<double>& vec) {
	
	// TODO
}
