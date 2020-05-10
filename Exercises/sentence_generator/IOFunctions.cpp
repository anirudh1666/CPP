#include "SentenceGen.h"


// Returns true is c is space.
bool space(char c) {
	
	return isspace(c);
}


// Returns true if c is not a space.
bool notSpace(char c) {
	
	return !isspace(c);
}

// @params = str : string that you want to split into words.
// @returns = vector<string> with all words in str.
vector<string> split(const string& str) {
	
	typedef string::const_iterator iter;
	vector<string> ret;
	
	iter i = str.begin();
	while (i != str.end()) {
		i = find_if(i, str.end(), notSpace);
		
		iter j = find_if(i, str.end(), space);
		
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}
		
		i = j;
	}
	
	return ret;
}


Grammar read(istream& in) {
	
	Grammar grammar;
	string line;
	
	while (getline(in, line)) {
		vector<string> entry = split(line);
		if (!entry.empty())
			grammar[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}
	
	in.clear();
	return grammar;
}










