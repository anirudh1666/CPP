#ifndef GUARD_permutedIndex_h
#define GUARD_permutedIndex_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::string>::size_type vecSize;
typedef std::string::size_type strSize;
typedef std::vector<std::string>::const_iterator iterator;
typedef std::vector<std::string>::iterator iterator2;

std::istream& readInput(std::istream&, std::vector<std::string>&);
int length(const std::vector<std::string>&);
std::vector<std::string> shuffle(std::string);
int findWords(std::string);
std::vector<std::string> permutedIndex(std::vector<std::vector<std::string> >&);
void sortVec(std::vector<std::string>&);
bool strCompare(const std::string&, const std::string&);
void format(std::vector<std::string>&, std::vector<std::string>&, int);

#endif
