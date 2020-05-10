#include "TempConv.h"


double celsius(double num) {
	
	return (num - 32) * 5/9;
}

double abs_value(double num) {
	
	return celsius(num) + 273.15;
}
