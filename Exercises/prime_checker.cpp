// This program checks if a number is a prime. Also checks type of input.
// Use list for better performance.

#include <iostream>
#include <vector>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;


bool checkInput(string line) {
	
	for (string::const_iterator iter = line.begin(); iter != line.end(); ++iter) {
		if (!isdigit(*iter))
			return false;
	}
	
	return true;
}


long convert(string line) {
	
	stringstream num(line);
	long number = 0;
	num >> number;
	return number;
}


bool prime(long num) {
	
	long root = sqrt(num);
	for (long count = 2; count != root; ++count) {
		if (num % count == 0) 
			return false;
	}
	
	return true;
}


void checkPrimes(vector<long>& v) {
	
	vector<long> primes;
	for (vector<long>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
		if (prime(*iter)) 
			primes.push_back(*iter);
	}
	
	cout << "\nPrinting primes.\n";
	for (vector<long>::const_iterator iter = primes.begin(); iter != primes.end(); ++iter) {
		cout << *iter << endl;
	}
}


int main() {
	
	string line;
	vector<long> numbers;
	cout << "Enter long ints here (type stop when you want to stop): ";
	while (cin >> line) {
		if (checkInput(line)) {
			long num = convert(line);
			numbers.push_back(num);
		}
		else if (line.compare("stop") == 0) {
			cin.clear();
			break;
		}
	}
	
	checkPrimes(numbers);
	
	return 0;
}
