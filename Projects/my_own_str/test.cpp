#include "Str.h"


using std::cout;                         using std::endl;
using std::cin;


int main() {
	
	cout << "Testing constructor.\n";
	Str my_str("Anirudh");
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		cout << my_str[i];
	}
	cout << endl << endl;
	
	cout << "Testing =.\n";
	my_str = "Lakra";
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		cout << my_str[i];
	}
	cout << endl << endl;;
	
	cout << "Testing +=.\n";
	my_str += ", Anirudh";
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		cout << my_str[i];
	}
	cout << endl << endl;	
	
	cout << "Testing copy.\n";
	Str copied = my_str.copy(my_str.begin(), my_str.end());
	for (Str::size_type i = 0; i != copied.size(); ++i) {
		cout << copied[i];
	}
	cout << endl << endl;
	
	cout << "Testing <.\n";
	Str test = "Anirudh";
	if (test < my_str)
		cout << "Test successful.";
	else 
		cout << "Test unsuccessful.";
	cout << endl << endl;
		
	cout << "Testing <=.\n";
	Str test1 = "Anirudh123455";
	if (test1 < my_str)
		cout << "Test successful.";
	else 
		cout << "Test unsuccessful.";
	cout << endl << endl;
	
	test = "ipsum dshudhudjnpsdifh023poedemlsd";
	cout << "Testing >.\n";
	if (test > my_str)
		cout << "Test successful.";
	else 
		cout << "Test unsuccessful.";
	cout << endl << endl;	
	
	test = "Lakra, Anirudh";
	cout << "Testing >=.\n";
	if (test >= my_str)
		cout << "Test successful.";
	else 
		cout << "Test unsuccessful.";
	cout << endl << endl;

	cout << "Testing getline.\nEnter input: ";
	Str in;
	getline(cin, in);
	for (Str::size_type i = 0; i != in.size(); ++i) {
		cout << in[i];
	}
	cout << endl << endl;
	
	cout << "Testing << operator.\n";
	Str my_str_2 = "yeet dab skrr";
	cout << my_str_2;
	
	return 0;
}
