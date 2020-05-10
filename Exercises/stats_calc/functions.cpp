#include "statistics.h"

using std::vector;                     using std::cout;
using std::endl;                       using std::domain_error;     
using std::streamsize;                 using std::setprecision;

void calc_avg(const vector<double>& vec) {
	
	if (vec.size() == 0) {
		cout << "Average of empty vector. Try again.\n";
		return;
	}

	double sum = 0;
	for (vector<double>::const_iterator it = vec.begin(); it != vec.end(); ++it) 
		sum += *it;
	
	streamsize prec = cout.precision();
	cout << setprecision(4) << "\nAverage: " << sum / vec.size() << setprecision(prec) << endl;
}

double calc_median(vector<double>& vec) {
	
	typedef vector<double>::size_type vec_size;
	vec_size size = vec.size();
	
	if (size == 0) {
		cout << "Median of empty vector. Try again.\n";
	}
	
	sort(vec.begin(), vec.end());
	vec_size mid = size / 2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2
						 : vec[mid];
}


// Uses method 1 from Wikipedia "Quartiles".
void calc_quartiles(vector<double>& vec) {
	
	typedef vector<double>::size_type vec_size;
	vec_size size = vec.size();
	if (size == 0) {
		cout << "Quartiles of empty vector. Try again.\n";
	}
		
	double median = calc_median(vec);
	double lower_quart;
	double upper_quart;
	double inter_quart;
	
	vector<double>::const_iterator first = vec.begin();
	vector<double>::const_iterator last = vec.end();
	vector<double>::const_iterator iter = vec.begin() + size / 2;
	
	if (size % 2 == 0) {
		vector<double> temp_vec (first, iter);
		vector<double> temp_vec2 (iter, last);
		
		upper_quart = calc_median(temp_vec2);
		lower_quart = calc_median(temp_vec);
	}
	else {
		vector<double> temp_vec (first, iter);
		vector<double> temp_vec2 (iter + 1, last);
		
		upper_quart = calc_median(temp_vec2);
		lower_quart = calc_median(temp_vec);
	}
	
	streamsize prec = cout.precision();
	
	inter_quart = upper_quart - lower_quart;
	cout << setprecision(4) << "\nMedian: " << median << endl;
	cout << "Lower Quartile: " << lower_quart << endl;
	cout << "Upper Quartile: " << upper_quart << endl;
	cout << "Interquartile Range: " << inter_quart << setprecision(prec) << endl << endl;
}


