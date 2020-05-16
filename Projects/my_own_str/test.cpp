#include "Str.h"


int main() {
	
	Str my_str("Anirudh");
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		std::cout << my_str[i];
	}
	std::cout << std::endl;
	
	my_str = "Lakra";
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		std::cout << my_str[i];
	}
	std::cout << std::endl;
	
	my_str += ", Anirudh";
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		std::cout << my_str[i];
	}
	std::cout << std::endl;	
	
	my_str += " lives in uk";
	for (Str::size_type i = 0; i != my_str.size(); ++i) {
		std::cout << my_str[i];
	}
	std::cout << std::endl;	
	
	return 0;
}
