#pragma once
#include <array>
int max(int a, int b);





// Enter the "template": given a list of "template parameters", we can write a function definition
// in terms of the template parameter types.
template<typename T>
T max2(T a, T b) {
	return a < b ? b : a;
}

// Templates can give us functions that work on arrays of any size. We make the data type AND THE SIZE! of the array
// parameters of the template.
template<typename T, int S>
// then define the parameters in terms of those:
int CountArray(const std::array<T, S> &data, const T& value) {
	int count = 0;
	for (int i = 0; i < S; i++) {
		if (data[i] == value) {
			count++;
		}
	}
	return count;
}

// This lets us do anything with arrays that we can do in Java, like sort them of any length.
template<typename T, int S> 
void SelectionSort(std::array<T, S> &data) {
	for (int i = 0; i < S - 1; i++) {
		int smallest = i;
		for (int j = i + 1; j < S; j++) {
			if (data[j] < data[smallest]) {
				smallest = j;
			}
		}
		std::swap(data[i], data[smallest]);
	}
}

// But shouldn't we be able to run 'Count' on ANY container type, not just arrays? You bet!
// In Java we'd do this by writing code that works on the Collection interface. C++ doesn't have
// an inheritance hierarchy like that.... but through templates and iterators, we can achieve 
// the same effect.
template<typename TItr, typename TData>
int Count(TItr begin, TItr end, const TData& value) {
	int count = 0;
	for (TItr itr = begin; itr != end; itr++) {
		if (*itr == value) {
			count++;
		}
	}
	return count;
}
// We now know enough to write our own versions of many STL functions!
template<typename TItr, typename TData>
TItr Find(TItr begin, TItr end, const TData& value) {
	for (TItr itr = begin; itr != end; itr++) {
		if (*itr == value) {
			return itr;
		}
	}
	return end;
}