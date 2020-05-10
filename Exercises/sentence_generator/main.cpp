// This program takes in rules for sentences
// and chooses a random rule and forms a sentence.

#include "SentenceGen.h"


int main() {
	
	cout << "This program takes in rules in the form of"
	        " <key> rules.\n";
	cout << "It then prints a sentence it made from the rules.\n";
	cout << "Enter the rules here: ";
	genSentence(read(cin));
	
	return 0;
}
