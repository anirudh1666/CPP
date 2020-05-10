#include "Pyramid.h"


using std::cin;           using std::istream;
using std::cout;          using std::ostream_iterator;
using std::string;


// Reads input from user until it gets valid input.
// @params = in : input stream being read.
// @returns = height of pyramid.
int read(istream& in) {
	
	int height;
	bool valid = false;
	while (!valid) {
		cout << "Enter height here between 0 - 30: ";
		in >> height;
		in.clear();
		
		if (height < 0 || height > 30) {
			cout << "Invalid height. Try again.\n\n";
			continue;
		}
		else {
			valid = true;
		}
	}
	
	return height;
}


// Prints formatted pyramid.
// @params = height : height of pyramid.
void print(int height) {
	
	// Output stream iterator (prints to terminal).
	ostream_iterator<string> outstr (cout, "\n");
	
	// No. of blanks in a line.
	int spaces = height - 1;
	
	// No. of asterisks in a line.
	int asterisks = 1;
	
	// Current line.
	int line = 0;

	cout << "\n\n"; 
	while (line != height) {
		
		// Format first half of line. 
		string first = string(spaces, ' ').append(string(asterisks, '*'));
		
		// Format second half of line.
		string second = string(asterisks, '*').append(string(spaces, ' '));
		
		// Print line.
		*outstr++ = first.append(second);
		
		++asterisks;
		++line;
		--spaces;
	}
}




















