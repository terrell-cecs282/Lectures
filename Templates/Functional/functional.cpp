#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> CopyEvens(const vector<int>& values) {
	vector<int> result;
	for (int i : values) {
		if (i % 2 == 0) {
			result.push_back(i);
		}
	}
	return result;
}

vector<int> CopyOdds(const vector<int>& values) {
	vector<int> result;
	for (int i : values) {
		if (i % 2 == 1) {
			result.push_back(i);
		}
	}
	return result;
}

template<typename TData, typename TPred>
vector<TData> CopyIf(const vector<TData>& values, TPred predicate) {
	vector<TData> result;
	for (TData &i : values) {
		if (predicate(i)) {
			result.push_back(i);
		}
	}
	return result;
}

int main() {
	vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> evens = CopyIf(values, [](int v) {return v % 2 == 0; });
	vector<int> threeToFive = CopyIf(values, [](int v) {return 3 <= v && v <= 5; });

}