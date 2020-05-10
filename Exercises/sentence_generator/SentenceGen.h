#ifndef GUARD_SentenceGen_h
#define GUARD_SentenceGen_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <list>
#include <ostream>
#include <iterator>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;


bool space(char);
bool notSpace(char);
vector<string> split(const string& str);
Grammar read(istream&);

int nrand(int);
bool isBracketed(const string&);
void genAux(const Grammar&, const string&, ostream_iterator<string>);
void genSentence(const Grammar&);


#endif
