#include <iostream>
#include <vector>

using std::vector;              using std::cout;
using std::endl;      


template <class In>
bool equals(In begin, In end, In pred) {
	
	while (begin != end) {
		if (*begin++ != *pred++) 
			return false;
	}
	
	return true;
}


template <class In, class In2>
In search(In begin1, In end1, In2 begin2, In2 end2) {
	
	In2 holder = begin2;
	In start;
	while (begin1 != end1) {
		if (begin2 == end2)
			return start;
		
		if (*begin1 == *holder)
			start = begin1;
		
		if (*begin1 == *begin2) {
			++begin1;
			++begin2;
		}
		else {
			++begin1;
			begin2 = holder;
		}
	}
	
	return end1;
}


// iter1 iter1.end() predicate(specific value)
// return iter1
template <class In, class T>
In find(In begin, In end, const T& val) {
	
	while (begin != end) {
		if (*begin == val) 
			return begin;
		++begin;
	}
	
	return end;
}

// test func for findIf
bool isOdd(const int& i) {
	
	return i % 2 == 0 ? false : true;
}


template <class In, class Pred>
In findIf(In begin, In end, Pred predicate) {
	
	while (begin != end) {
		if (predicate(*begin))
			return begin;
		++begin;
	}
	
	return end;
}

template <class In, class Out>
Out myCopy(In begin, In end, Out dest) {
	
	while (begin != end) 
		*dest++ = *begin++;
	
	return dest;
}


template <class In, class Out, class T>
Out removeCopy(In begin, In end, Out dest, T val) {
	
	while (begin != end) {
		if (*begin == val) {
			++begin;
		}
		else {
			*dest++ = *begin++;
		}
	}
	
	return dest;
}


template <class In, class Out, class Predicate>
Out removeCopyIf(In begin, In end, Out dest, Predicate pred) {
	
	while (begin != end) {
		if (!pred(*begin)) 
			*dest++ = *begin++;
		else
			++begin;
	}
	
	return dest;
}

template <class In, class T>
In remove(In begin, In end, T val) {
	
	In it = begin;
	while (begin != end) {
		if (*begin != val) 
			*it++ = *begin++;
		else 
			begin++;
	}
	
	return it;
}


int increase(int i) {
	 return i + 1;
}

template <class In, class Out, class Function>
Out transform(In begin, In end, Out dest, Function func) {
	
	while (begin != end) {
		*dest = func(*begin);
		++dest;
		++begin;
	}
	return dest;
}


template <class Bi, class Predicate>
Bi partition(Bi begin, Bi end, Predicate pred) {
	
	while (begin != end) {
		while (pred(*begin)) {
			++begin;
			if (begin == end)
				return begin;
		}
		
		do {
			--end;
			if (begin == end) 
				return begin;
		} while (!pred(*end));
		std::swap(*begin, *end);
		++begin;
	}
	
	return begin;
}

template <class For, class T>
T accumulate(For begin, For end, T init) {
	
	while (begin != end) {
		init += *begin++;
	}
	
	return init;
}

int main() {
	
	vector<int> v2 = {20,30,60,43,50,60,51};
	cout << accumulate(v2.begin(), v2.end(), 0) << endl;
	
	return 0;
}
