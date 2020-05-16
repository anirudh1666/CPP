#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include "Vec.h"

class Str {
	
	friend std::istream& operator>>(std::istream&, Str&);
	
	public:
		typedef Vec<char>::size_type size_type;
		
		// Constructors
		Str() { }
		
		// : is accepted way of initializing constructors.
		// Also allows const values to be initialized.
		Str(size_type n, char c): data(n, c) { }
		
		// String literal = const char*.
		// conversion constructor. Converts string literals to Str.
		Str(const char* cp) {
			
			std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
		}
		
		template<class In> Str(In b, In e) {
			
			std::copy(b, e, std::back_inserter(data));
		}
		
		// Member functions.
		size_type size() const { return data.size(); }
		
		// Overloaded operators.
		char& operator[](size_type i) { return data[i];}
		const char& operator[](size_type i) { return data[i]; }

		Str& operator+=(const Str& s) {
			
			std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
			return *this;
		}
		
			
	private:
		Vec<char> data;
};

// Non-member operators.
std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);



#endif

