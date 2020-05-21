/* My own implementation of string class using array of chars.
   Done as an exercise from Chapter 12 of Accelerated C++.
*/

#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
#include <vector>
#include <iterator>

using std::allocator;               using std::uninitialized_fill;
using std::uninitialized_copy;      using std::strlen;
using std::string;                  using std::strcmp;
using std::istream;                 using std::vector;
using std::ostream;                 using std::ostream_iterator;

class Str {
	
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		typedef size_t size_type;
		
		// Constructors.
		Str() { create(0, '\0'); }
		Str(size_type n, const char c) { create(n, c); }
	
		Str(const char* c) { create(c, c + strlen(c)); }
		Str(const Str& s) { create(s.begin(), s.end()); }
		
		template <class In>
		Str(In begin, In end) { create(begin, end); }
		
		// Destructor.
		~Str() { uncreate(); }
		
		// Members.
		size_type size() const { return length; }
		
		// Same thing as data().
		const char* c_str() const { return start; } 
		
		Str copy(char*, char*) const;
		
		// Operators.
		Str& operator=(const Str&);
		Str& operator+=(const Str&);
	
		char& operator[](size_type i) { return start[i]; }
		const char& operator[](size_type i) const { return start[i]; }
		
		
		
		// Iterators.
		iterator begin() { return start; }
		const_iterator begin() const { return start; }
		
		iterator end() { return start + length + 1; }
		const_iterator end() const { return start + length + 1; }
	
	private:
		iterator start;
		// Length doesn't include null terminator.
		size_type length;
		
		allocator<char> alloc;
		
		void create();
		void create(size_type, const char);
		
		template <class In>
		void create(In, In);
		
		void uncreate();
		
};

ostream& operator<<(ostream& out, const Str& str) {
	
	ostream_iterator<string> iter(out, "\n");
	const char* temp = str.c_str();
	string output(temp);
	*iter++ = output;
}

inline bool operator<(const Str& lhs, const Str& rhs) {
	
	return (strcmp(lhs.c_str(), rhs.c_str()) < 0);
}


inline bool operator<=(const Str& lhs, const Str& rhs) {
	
	return (strcmp(lhs.c_str(), rhs.c_str()) <= 0);
}

inline bool operator>(const Str& lhs, const Str& rhs) {
	
	return (strcmp(lhs.c_str(), rhs.c_str()) > 0);
}

inline bool operator>=(const Str& lhs, const Str& rhs) {
	
	return (strcmp(lhs.c_str(), rhs.c_str()) <= 0); 
}



istream& getline(istream& is, Str& str) {
	
	vector<char> characters;
	char in;
	
	while (is.get(in) && isspace(in))
		;
	
	if (is) {
		do characters.push_back(in);
		while (is.get(in) && in != '\n');
		if (is)
			is.unget();
	}
	
	Str ret(characters.begin(), characters.end());
	str = ret;
	
	is.clear();
	return is;
}


template <class In>
void Str::create(In begin, In end) {
	
	length = end - begin;
	start = alloc.allocate(length + 1);
	uninitialized_copy(begin, end, start);
	alloc.construct(start + length, '\0');
}


#endif
