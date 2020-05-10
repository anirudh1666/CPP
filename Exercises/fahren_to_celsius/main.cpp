#include "TempConv.h"

using std::cout;         using std::endl;
using std::cin;          using std::ios;
using std::streamsize;   using std::setprecision;

int main() {
	
	cout << "This program takes in upper bound and lower bound"
		    " for temperatures and converts them to celsius and"
		    " absolute value.\n";
	
	int upper;
	int lower;
	int step;
	cout << "\nEnter upper bound: ";
	cin >> upper;
	cout << "Enter lower bound: ";
	cin >> lower;
	cout << "Enter the increment between successive temperatures: ";
	cin >> step;
		    
	cout << "\n\n";
	cout.setf(ios::left);
	cout.width(15);
	
	cout << "Fahrenheit";
	cout.width(15);
	cout << "Celsius";
	cout.width(15);
	cout << "Absolute value\n\n";
	
	streamsize prec = cout.precision();
	for (double i = lower; i <= upper; i = i + step) {
		double cels = celsius(i);
		double abs_val = abs_value(i);
		
		cout.width(15);
		cout << setprecision(4) << i;
		cout.width(15);
		cout << cels;
		cout.width(15);
		cout << abs_val << endl;
	}
	cout.precision(prec);
	
	return 0;
}
