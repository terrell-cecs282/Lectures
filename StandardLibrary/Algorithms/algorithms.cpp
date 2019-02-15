#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	vector<int> values = { 4, 8, 15, 16, 23, 42 };

	// std::find - LINEAR SEARCH over any portion of any data structure.
	//  The range to search is identified by a pair of iterators, with the 
	//  second iterator being exclusive (stop when reaching it). 
	//  An iterator to the located value is returned.
	auto found = std::find(values.begin(), values.end(), 16);
	if (found != values.end()) {
		// If found equaled the end, then we could conclude that the value
		// was not in the range.

		// What can we do with found? We could mutate it:
		*found = 21;

		// We can also infer the integer index (vectors only) by subtracting
		// iterators:
		int index = found - values.begin();
		cout << "Value 16 was found at index " << index << ", but now that "
			<< "index has value " << *found << endl;
	}

	// std::lower_bound: perform a BINARY SEARCH over a range, as long as
	//   the values in that range are ordered. Returns an iterator at the
	//   first value that is greater or equal to the given value.
	int target = 16;
	found = std::lower_bound(values.begin(), values.begin() + 4, target);
	if (found != values.end() && *found == target) {
		cout << "Found " << target << "!" << endl;
	}
	else {
		cout << "Could not find " << target << endl;
	}

	// std::reverse: reverse the values in a range of iterators.
	std::reverse(values.begin(), values.end());

	// std::random_shuffle: randomize the elements of a range.
	std::random_shuffle(values.begin(), values.end());

	for (auto i : values) {
		cout << i << " ";
	}
	cout << endl;

	// std::sort: sort a range of iterators, using the default < comparison.
	std::sort(values.begin(), values.end());

	// you can also provide your own comparison rule.
	std::sort(values.begin(), values.end(), std::greater<int>{}); // use > when sorting.

	/*
	Do you really need to know all these? No, but I do want you to know:
	- std::find, and how to know if the value was not found.
	- the use of iterators to identify ranges
	- using + and - with iterators
	*/
}