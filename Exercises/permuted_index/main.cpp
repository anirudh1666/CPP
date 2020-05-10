// See page 133 Accelerated C++ for problem.

#include "permutedIndex.h"

using std::cout;         using std::cin;
using std::string;       using std::vector;
using std::endl;


int main() {
	
	vector<string> phrases;
	vector<vector<string> > shuffledPhrases;
	
	cout << "This program takes in phrases in the form "
	        "of lines. It then outputs a permuted index form."
	     << endl << "Make sure all phrases are lower case."
	     << endl << "Enter the phrases below: " << endl;
	
	// Read in lines from cin and store each line as a phrase.
	readInput(cin, phrases);
	int maxlen = length(phrases);
	
	vector<string> foo = shuffle(phrases[0]);
	
	// Shuffle each phrase and sort them alphabetically.
	for (iterator iter = phrases.begin(); iter != phrases.end(); ++iter) {
		vector<string> shuffled = shuffle(*iter);
		shuffledPhrases.push_back(shuffled);
	}
	
	// Sort all shuffled phrases and then format and output.
	vector<string> permuted = permutedIndex(shuffledPhrases);
	cout << endl << "OUTPUTTING PERMUTED INDEX: " << endl << endl;
	format(permuted, phrases, maxlen);
	
	return 0;
}
