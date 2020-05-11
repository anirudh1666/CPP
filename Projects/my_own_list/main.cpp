#include "MyList.h"

using std::cout;        using std::endl;


int main() {
	
	MyList<double> list = MyList<double>();
	list.push_back(203.0);
	list.push_back(-254.403);
	list.push_back(39.48503);
	list.push_back(2.0);
	list.push_back(-23023);
	
	cout << "list = { 203.0, -254.403, 39.48503, 2.0, -23023 }\n"
	        "Printing list: ";
	for (MyList<double>::const_iterator it = list.get_front(); it != list.get_back(); ++it) 
		cout << *it << " ";
	cout << endl;
	
	return 0; 
}
