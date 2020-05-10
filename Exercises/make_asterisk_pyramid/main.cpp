// This program prints out pyramids made up of *.

#include "Pyramid.h"

using std::cout;              using std::cin;
 

int main() {
	
	cout << "Hello! This program prints out pyramids made up "
		    "of '*'.\n\n";
	
	int height = read(cin);
	
	print(height);
	
	return 0;
}
