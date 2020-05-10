/* This file contains searching algorithms, made by Anirudh Lakra. */

#include "Searching.h"

using std::vector;


template <class Ran, class T>
Ran binary_search(Ran start, Ran end, const T value) {
	
	Ran save_end = end;
	
	while (start <= end) {
		Ran mid = (start + end) / 2;
		
		if (*mid == value) 
			return mid;
		
		else if (*mid > value) 
			end = mid - 1;
		
		else 
			start = mid + 1;
	}
	
	return save_end;
}
