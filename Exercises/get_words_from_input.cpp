#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


using std::cout;            using std::cin;
using std::endl;            using std::vector;
using std::string;          using std::ostream_iterator;


bool isSpace(const char& c) {
	
	return isspace(c);
}


bool notSpace(const char& c) {
	
	return !isspace(c);
}


template <class Out>
void split(const string& str, Out os) {
	
	typedef string::const_iterator iter;
	iter it = str.begin();
	while(it != str.end()) {
		it = find_if(it, str.end(), notSpace);
		
		iter it2 = find_if(it, str.end(), isSpace);
		
		if (it != str.end()) 
			*os++ = string(it, it2);
		
		it = it2;
	}
}


int main() {
	
	string s;
	while (getline(cin, s)) 
		split(s, ostream_iterator<string>(cout, "\n"));
	
	return 0;
}
