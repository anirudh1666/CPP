// Practice exercises to help get better with pointers.

#include <iostream>
#include <limits>

using std::cout;                  using std::cin;
using std::endl;                  using std::string;

char* string_copy(char *s) {
	
	char *copied = new char[20];
	int count = 0;

	while (*s != '\0') {
		*copied++ = *s++;
		count++;
	}
	count++;
	*copied++;
	*copied = '\0';
	
	copied = copied - count;
	return copied;
}


void test_string_copy() {
	
	string test_string = "Anirudh Lakra";
	char *ptr = &test_string[0];
	char *copied = string_copy(ptr);
	
	cout << "\nTesting String copy.\nString: Anirudh Lakra.\nResult: ";
	while (*copied != '\0')
		cout << *copied++;
	cout << endl;
	copied = copied - 13;
	delete[] copied;
}


// Returns true if t is at end of s.
// Define end if t occurs past midpoint of s.
bool str_end(char *s, char *t) {
	
	int cur_index = 0;
	int start_index = -1;
	int size = 1;
	
	while (*s != '\0') {
		if (*s == *t) {
			start_index = size;
			cur_index++;
			t++;
		}
		else {
			start_index = -1;
			t = t - cur_index;
			cur_index = 0;
		}
	
		s++;
		size++;
	}
	
	if (start_index == -1 || *t != '\0' || start_index < size / 2)
		return false;
	return true;
}


void test_str_end() {
	
	string my_string = "Anirudh Lakra";
	string target_string = "Lakra";
	char *s = &my_string[0];
	char *t = &target_string[0];
	
	cout << "\nTesting String end.\nString: Anirudh Lakra, Target string: Lakra. 1 = found, 0 = not found.\n";
	cout << "Result: " << str_end(s, t) << endl;
}


void merge(int array[], int left[], int right[], int l_mid, int r_mid) {
	
	int left_index = 0;
	int right_index = 0;
	int array_index = 0;
	
	while (left_index != l_mid && right_index != r_mid) {
		if (left[left_index] <= right[right_index]) {
			array[array_index] = left[left_index];
			left_index++;
		}
		else {
			array[array_index] = right[right_index];
			right_index++;
		}
		array_index++;
	}
	
	while (right_index != r_mid) {
		array[array_index] = right[right_index];
		array_index++;
		right_index++;
	}
	
	while (left_index != l_mid) {
		array[array_index] = left[left_index];
		array_index++;
		left_index++;
	}
	
}


void merge_sort(int array[], int size) {
	
	if (size < 2)
		return;
	else {
		if (size % 2 == 0) {
			int mid = size / 2;
			int left[mid];
			int right[mid];
			
			for (int i = 0; i != mid; ++i) {
				left[i] = array[i];
				right[i] = array[i+mid];
			}
			
			merge_sort(left, mid);
			merge_sort(right, mid);
			merge(array, left, right, mid, mid);
		}
		
		else {
			int l_mid = size / 2;
			int r_mid = size / 2 + 1;
			int left[l_mid];
			int right[r_mid];
			
			
			right[0] = array[r_mid-1];
			for (int i = 0; i != l_mid; ++i) {
				left[i] = array[i];
			}
			for (int i = 0; i != l_mid; ++i) {
				right[i+1] = array[i + r_mid];
			}
			merge_sort(left, l_mid);
			merge_sort(right, r_mid);
			merge(array, left, right, l_mid, r_mid);
		}
	}
}


void test_merge_sort() {
	
	int my_array[] = {10,21,5,32,6,0,12,14,9,2};
	int my_array_size = 10;
	merge_sort(my_array, my_array_size);
	
	cout << "\nTesting merge sort.\nMergeSort: ";
	for (int index = 0; index != my_array_size; ++index) {
		cout << my_array[index] << " ";
	}
	cout << endl;
	
	cout << "Sorted: 0 2 5 6 9 10 12 14 21 32\n";
}


int* sort(int* n, int size) {
	
	int* save = n;
	int ret[size];
	int* ptr = ret;
	bool visited[size] = {0};
	
	for (int i = 0; i != size; ++i) {
		int lowest = std::numeric_limits<int>::max();      // set to inf so all would be less.
		int lowest_index = 0;
	
		for (int j = 0; j != size; ++j) {
			if (!visited[j] && *n <= lowest) {
				lowest = *n;
				lowest_index = j;
			}
			n++;
		}
	
		visited[lowest_index] = true;
		*ptr = lowest;
		ptr++;
		n = save;
	}
	
	int* ptr2 = ret;
	return ptr2;           
}


void test_sort() {
	
	int array[] = {10,12,4,2,56,1,32};
	int* sorted = sort(array, 7);             // doesnt work for some FUCKING reason
	 
	cout << "\nTesting sort.\nSorted: 1 2 4 10 12 32 56\nSort: ";
	for (int i = 0; i != 7; ++i) {
		cout << *sorted++ << " ";
	}
	cout << endl;
}


int main() {
	
	test_string_copy();
	test_str_end();
	test_merge_sort();
	test_sort();
	return 0;
}
