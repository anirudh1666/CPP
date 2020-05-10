#ifndef GUARD_Searching_h
#define GUARD_Searching_h

#include <iostream>
#include <vector>

template <class Ran, class T>
Ran binary_search(Ran, Ran, const T);



std::vector<int> init_vector();


void test_binary_search();
void run_tests();

#endif
