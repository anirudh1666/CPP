#include "Str.h"

void Str::create(size_type size, const char c) {
	
	start = alloc.allocate(size + 1);
	length = size;
	uninitialized_fill(start, start + size, c);
	alloc.construct(start + size, '\0');
}

void Str::uncreate() {
	
	if (start) {
		iterator it = start + length;
		while (it != start)
			alloc.destroy(--it);
		
		alloc.deallocate(start, 1 + length);
	}
}

// increase space.
// then concat.
Str& Str::operator+=(const Str& s) {
	
	size_type str_size = s.size();
	iterator new_start = alloc.allocate(length + str_size + 1);
	iterator end_of_first = new_start + length - 1;

	uninitialized_copy(start, start + length - 1, new_start);
	uninitialized_copy(s.begin(), s.end(), end_of_first);
	
	uncreate();
	
	start = new_start;
	length = str_size + length;
}
	
Str& Str::operator=(const Str& str) {
	
	if (&str != this) {
		uncreate();
		create(str.begin(), str.end());
	}
	
	return *this;
}

