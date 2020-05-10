// This program counts the number of times each word appears
// in the input.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
using std::map;


bool space(const char c) {
	return isspace(c);
}


bool not_space(const char c) {
	return !isspace(c);
}


vector<string> split(const string& str) {
	
	typedef string::const_iterator iter;
	vector<string> ret;
	
	iter i = str.begin();
	while (i != str.end()) {
		i = find_if(i, str.end(), not_space);
		
		iter j = find_if(i, str.end(), space);
		
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}
		i = j;
	}
	
	return ret;
}


map<string, vector<int> > 
	xref(istream& in,vector<string> find_words(const string&) = split) {
		
		string line;
		int line_number = 0;
		map<string, vector<int> > ret;
		
		while (getline(in, line)) {
			++line_number;
			
			vector<string> words = find_words(line);
			
			for (vector<string>::const_iterator it = words.begin();
				 it != words.end(); ++it) {
				
				map<string, vector<int> >::iterator iter = ret.find(*it);
				if (iter == ret.end()) {
					ret[*it].push_back(line_number);
				}
				else {
					vector<int> lines = iter->second;
					vector<int>::iterator iter2 = find(lines.begin(), lines.end(), line_number);
					if (iter2 != lines.end()) 
						continue;
					ret[*it].push_back(line_number);
				}
			}
		}
		
		return ret;
	}


void print(map<string, vector<int> >& map) {
	
	std::map<int, vector<string> > orderedMap;
	for (std::map<string, vector<int> >::const_iterator it = map.begin();
		 it != map.end(); ++it) {
		string key = it->first;
		int size = it->second.size();
		orderedMap[size].push_back(key);
	}
	
	for (std::map<int, vector<string> >::const_iterator it = orderedMap.begin();
		 it != orderedMap.end(); ++it) {
		
		for (vector<string>::const_iterator iter = it->second.begin(); iter != it->second.end();
			 ++iter) {
			string key = *iter;
		 	std::map<string, vector<int> >::iterator iter2 = map.find(key);
		 	
		 	if (iter2 != map.end()) {
			 	cout << iter2->first << " occurs on line";
				if (iter2->second.size() > 1) 
					cout << "(s): ";
				else
					cout << ": ";
			
				vector<int>::const_iterator lineIt = iter2->second.begin();
				cout << *lineIt;
				int count = 1;
		
				++lineIt;
				while (lineIt != iter2->second.end()) {
					if (count < 5) {
						cout << ", " << *lineIt;
						++lineIt;
						++count;
					}
					else {
						cout << endl << string(' ', iter2->first.size());
						count = 0;
					}
				}
			}
			
			cout << endl;
		}
	}
}


int main() {
	
	map<string, vector<int> > ret = xref(cin);
	
	print(ret);
	
	return 0;
}
