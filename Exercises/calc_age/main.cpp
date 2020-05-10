#include "ageCalc.h"

using std::cin;                      using std::cout;
using std::endl;                     using std::vector;   
using std::string;            

int main() {
	
	vector<int> b_date = read_b_date(cin);
	vector<int> f_date = read_f_date(cin);
	
	string age = calc_age(b_date, f_date);
	
	if (age.compare("\0") == 0) 
		return 0;
	
	
	cout << "Your age in " << f_date[1] << "/"
		 << f_date[0] << ": " << age << endl;
		
	return 0;
}
