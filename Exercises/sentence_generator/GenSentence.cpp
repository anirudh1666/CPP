#include "SentenceGen.h"


bool isBracketed(const string& s) {
	
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

int nrand(int n) {
	if (n <= 0 || n > RAND_MAX) 
		throw domain_error("Argument to nrand is out of range.");
	
	const int bucketSize = RAND_MAX / n;
	int r;
	
	do r = rand() / bucketSize;
	while (r >= n);
	
	return r;
}



void genAux(const Grammar& grammar, const string& str, ostream_iterator<string> os) {
	
	if (!isBracketed(str)) {
		*os++ = str;
	}
	else {
		Grammar::const_iterator it = grammar.find(str);
		if (it == grammar.end()) 
			throw logic_error("empty rule");
			
		const RuleCollection& collection = it->second;
		
		const Rule& rule = collection[nrand(collection.size())];
		
		for (Rule::const_iterator i = rule.begin(); i != rule.end();
			 ++i) {
			genAux(grammar, *i, os); 	
		}
	}
	
}


void genAuxStack(const Grammar& grammar, const string& str, vector<string>& sentence) {
	
	list<string> stack;
	stack.push_back(str);
	while (!stack.empty()) {
		string current = stack.back();
		stack.pop_back();
		if (!isBracketed(current)) {
			sentence.push_back(current);
		}
		else {
			Grammar::const_iterator it = grammar.find(current);
			
			if (it == grammar.end())
				throw logic_error("empty rule");
			
			const RuleCollection& collection = it->second;
			
			const Rule& rule = collection[nrand(collection.size())];
			
			for (Rule::const_iterator i = rule.end() - 1; i != rule.begin() - 1;
				 --i) {
				stack.push_back(*i); 	
			}
		}
	}
}



void genSentence(const Grammar& grammar) {
	
	ostream_iterator<string> i (cout, " ");
	genAux(grammar, "<sentence>", i);
}
