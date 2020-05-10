#include "ageCalc.h"

using std::cout;            using std::string;
using std::vector;          using std::istream;
using std::to_string;

vector<int> read_b_date(istream& in){
	
	vector<int> b_date;
	
	int val;
	cout << "Enter the year you were born: ";
	in >> val;
	b_date.push_back(val);
	
	cout << "Enter the month you were born (1 - 12): ";
	in >> val;
	b_date.push_back(val);
	
	in.clear();
	
	return b_date;
}

vector<int> read_f_date(istream& in) {
	
	vector<int> f_date;
	
	int val;
	cout << "Enter the year for which you wish to know"
		    " your age: ";
	in >> val;
	f_date.push_back(val);
	
	cout << "Enter the month for which you wish to know your"
		    " age (1- 12): ";
	in >> val;
	f_date.push_back(val);
	
	return f_date;
}


string calc_age(const vector<int>& b_date, const vector<int>& f_date) {
	
	int year_diff = f_date[0] - b_date[0] - 1;
	if (year_diff < 0) {
		cout << "You weren't born then!\n\n";
		return "\0";
	}
	
	int months_diff = 12 - b_date[1] + f_date[1];
	string age = to_string(year_diff) + " and " + to_string(months_diff);
	
	if (months_diff == 0 | months_diff == 1) 
		return age + " month old.";
	
	return age + " months old.";
}
















