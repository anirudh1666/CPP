// Contains code to test Vec.h

#include "Vec.h"

using std::cout;
using std::endl;

int main() {
	
	Vec<int> my_vec = Vec<int>(10);
	my_vec.push_back(30);
	my_vec.push_back(-12);
	my_vec.push_back(321);
	my_vec.push_back(-20302);
	my_vec.push_back(3);
	my_vec.push_back(95);
	
	for (Vec<int>::const_iterator i = my_vec.begin(); i != my_vec.end(); ++i)
		cout << *i << " ";
	cout << endl;
}
