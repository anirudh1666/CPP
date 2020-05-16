// Contains code to test Vec.h

#include "Vec.h"

using std::cout;
using std::endl;

int main() {
	
	Vec<int> my_vec = Vec<int>();
	my_vec.push_back(30);
	my_vec.push_back(-12);
	my_vec.push_back(321);
	my_vec.push_back(-20302);
	my_vec.push_back(3);
	my_vec.push_back(95);
	
	for (Vec<int>::const_iterator i = my_vec.begin(); i != my_vec.end(); ++i)
		cout << *i << " ";
	cout << endl;
	
	my_vec.erase(my_vec.begin(), my_vec.begin() + 2);
	for (Vec<int>::const_iterator i = my_vec.begin(); i != my_vec.end(); ++i)
		cout << *i << " ";
	cout << endl;
	
	my_vec.clear();
	my_vec.push_back(-3);
	my_vec.push_back(21);
	my_vec.push_back(93);
		for (Vec<int>::const_iterator i = my_vec.begin(); i != my_vec.end(); ++i)
		cout << *i << " ";
	cout << endl;
	
	
	return 0;
}
