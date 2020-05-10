/* This file contains tests for searching algorithms, made by Anirudh Lakra.*/

#include "Searching.h"

using std::vector;             using std::cout;
using std::endl;


vector<int> init_vector() {

	vector<int> my_vec = {10,-30,43,5,596,23,21,402,2};
	return my_vec;
}         


void test_binary_search() {
	
	vector<int> my_vec = init_vector();
	vector<int>::iterator start = my_vec.begin();
	vector<int>::iterator end = my_vec.end();
	int val = 21;
	
	cout << "\nTesting Binary Search.\n";
	cout << "Target Value: 21\n";
	
	vector<int>::iterator iter = binary_search(start, end, val);
	if (*iter == *(my_vec.end()))
		cout << "Not found.\n";
	else
		cout << "Found.\n";
}


void run_tests() {
	
	test_binary_search();
}


int main() {
	
	run_tests();
	return 0;
}

