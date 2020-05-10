#include "permutedIndex.h"


using std::istream;        using std::string;
using std::vector;         using std::sort;


//@params = in : input stream being used.
//          vec : reference to a vector that strings read should be saved in.
//@returns = in (input stream).
istream& readInput(istream& in, vector<string>& vec) {

	if (in) {
		// Clear all data already in vec.
		vec.clear();
		
		string input;
		while (getline(in, input)) {
			vec.push_back(input);
		}
		
		// Clear input buffer for later input.
		in.clear();
	}
	
	return in;
}


// Finds the longest length string in vector.
// @params = vec : reference to vector that contains the strings.
// @returns = length of longest string in vec.
int length(const vector<string>& vec) {
	
	int maxlen = 0;
	
	for (iterator iter = vec.begin(); iter != vec.end(); ++iter) {
		if (iter->length() > maxlen) {
			maxlen = iter->length();
		}
	}
	
	return maxlen;
}


// Finds the number of words in a string.
// @params = str : string being read in.
// @returns = integer indicating number of words.
int findWords(string str) {
	
	int words = 1;
	
	for (strSize curIndex = 0; curIndex != str.length(); ++curIndex) {
		char curChar = str.at(curIndex);
		if (curChar == ' ') {
			words++;
		}
	}
	
	return words;
}


// Rotates the string so first word is last word in the next
// iteration. Continues until first word is reached again.
// @params = str : string that needs to be shuffled.
// @returns = vector that contains all the shuffled strings.
vector<string> shuffle(string str) {
	
	vector<string> shuffled;
	int words = findWords(str);
	
	// Allows the first word to be appended without it joining to the
	// previous last word. E.g. foxThe instead it gives fox The
	str.push_back(' ');     
	for (int count = 0; count != words; ++count) {
		shuffled.push_back(str);
		
		// Find first word. Take that word and space and append to the end.
		strSize space = str.find_first_of(' ');
		string word = str.substr(0, space + 1);
		str.erase(0, space + 1);
		str.append(word);
	}
	
	return shuffled;
}


// Predicate used in sort function to help sort strings alphabetically.
bool strCompare(const string& s1, const string& s2) {
	return s1 < s2;
}


// Sorts strings alphabetically in vec. A->Z from first element to last.
// @params = vec : reference to vector that needs to be sorted.
void sortVec(vector<string>& vec) {
	sort(vec.begin(), vec.end(), strCompare);
}

// Sorts all the shuffled strings alphabetically into one vector.
// @params = vec : reference to vector being sorted.
// @returns = sorted vector with all strings that should be formatted.
vector<string> permutedIndex(vector<vector<string> >& vec) {
	
	vector<string> result;
	
	// Copy all shuffled vector into one big one and sort it.
	for (vector<vector<string> >::size_type i = 0; i != vec.size(); ++i) {
		for (vecSize j = 0; j != vec[i].size(); ++j) {
			result.push_back(vec[i][j]);
		}
	}
	sortVec(result);
	
	return result;
}


// Format each string and save it in vector<string>.
void format(vector<string>& sorted, vector<string>& phrases, int maxlen) {
	
	for (iterator2 iter = sorted.begin(); iter != sorted.end(); ++iter) {
		strSize index = (*iter).find_first_of(' ');
		string firstWord = (*iter).substr(0, index);
		
		for (iterator iter2 = phrases.begin(); iter2 != phrases.end(); ++iter2) {
			
			// If the current shuffled phrase matches one of the ones in the input.
			if ((*iter).length() == (*iter2).length() + 1) {
				
				// Find the index of the word.
				strSize indexOf = (*iter2).find(firstWord);
				
				// Copy string before the word. Add "  " then rest of sentence.
				string format = (*iter2).substr(0, indexOf);
				string spacing(maxlen-format.length(), ' ');
				spacing.append(format);
				spacing.append("  ");
				spacing.append((*iter2).substr(indexOf, (*iter2).size()));
				
				// Output result.
				std::cout << spacing << std::endl;
			}
		}
	}
}
