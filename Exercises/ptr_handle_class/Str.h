#ifndef GUARD_STR_H
#define GUARD_STR_H

#include <iostream>
#include <vector>
#include <cstring>
#include "Ptr.h"

using std::vector;

class Str {

	friend std::istream& operator>>(std::istream&, Str&);

public:

	Str& operator+=(const Str& s) {

		data.make_unique();
		std::copy(s.data->begin(), s.data->end(),
				  std::back_inserter(*data));

		return *this;
	}

	typedef vector<char>::size_type size_type;

	// Constructors and destructors.
	Str(): data(new vector<char>) { }

	Str(const char* cp): data(new vector<char>) {

		std::copy(cp, cp + std::strlen(cp),
				  std::back_inserter(*data));
	}

	Str(size_type n, char c): data(new vector<char>(n, c)) { }

	template<class In>
	Str(In i, In j): data(new vector<char>) {

		std::copy(i, j, std::back_inserter(*data));
	}

	// Different from const since it returns copied version.
	// This allows user to modify new obj w/o affecting older one.
	char& operator[](size_type i) {

		data.make_unique();
		return (*data)[i];
	}

	// Doesnt copy since const guarentees we don't modify obj.
	const char& operator[](size_type i) const { return (*data)[i]; }
	size_type size() const { return data-size(); }

private:
	// Ptr to vector that holds characters in string.
	Ptr< vector<char> > data;
};

std::ostream& operator<<(std::ostream& os, const Str& s) {

	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}

	return os;
}

Str operator+(const Str& lhs, const Str& rhs) {

	Str r = lhs;
	r += rhs;
	return r;
}

// Intermediate function to help +=.
// Copies object and returns new object.
template<class T>
T* clone(const T* tp) {

	return tp->clone();
}

// Template specialization. Means it works differently
// for vector<char> than other types.
template<>
vector<char>* clone(const vector<char>* vp) {

	return new vector<char>(*vp);
}

#endif
