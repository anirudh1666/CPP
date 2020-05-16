/* My own implementation of string class using array of chars.
   Done as an exercise from Chapter 12 of Accelerated C++.
*/

#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>


using std::allocator;               using std::uninitialized_fill;
using std::uninitialized_copy;      using std::strlen;

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
		
		// Operators.
		Str& operator=(const Str&);
	
		char& operator[](size_type i) { return start[i]; }
		const char& operator[](size_type i) const { return start[i]; }
		
		Str& operator+=(const Str&);
		
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


template <class In>
void Str::create(In begin, In end) {
	
	length = end - begin;
	start = alloc.allocate(length + 1);
	uninitialized_copy(begin, end, start);
	alloc.construct(start + length, '\0');
}


#endif
