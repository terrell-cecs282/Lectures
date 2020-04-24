#include <iostream>
#include <vector>
using namespace std;
// A vector is an array list: a linear data structure where data are given
// indices from left to right.

// For later:
double findMean(vector<int> values);
double findMeanRef(const vector<int> &values);

int main(int argc, char* argv[]) {
	// vectors are a "template type": we must specify what type of data
	// are in the vector.
	vector<int> v; // Initializes an empty vector of integers.
	vector<int> v2 = { 8, 6, 7, 5, 3, 0, 9 }; // "initializer list"

	// We use vectors like array lists: to store data in linear fashion.
	// We just use different names for the core methods:
	v.push_back(5); // "add last"
	v.pop_back();   // "remove last"
	v.size();       // "get count"
	v.front();	    // "get first"
	v.back();       // "get last"
	v[0];			// arbitrary index access.
	
	cout << "Enter a sequence of integers, and 0 to stop: ";
	int value = -1;
	while (value != 0) {
		cin >> value;
		v.push_back(value);
	}

	cout << "You entered:" << endl;
	// We can do an array-like loop to access the elements of a vector:
	// for (int i = 0; i < v.size(); i++) {
	//	   cout << v[i];
	// }
	// But that's short sighted (doesn't work with other data structures).
	// The C++ idiomatic approach is to use "iterators", which are objects
	// that "walk" through the elements of a data structure.

	// the type of an iterator depends on the structure you are iterating 
	// through. A vector iterator is different than a linked list iterator.
	vector<int>::iterator itr; 

	// An iterator is initialized with a starting location. The .begin() function
	// returns an iterator at the beginning of a data structure.
	itr = v.begin();

	// itr is "the iterator", which *refers* to a location in the vector.
	// We can do two things with the iterator: retrieve the *value* that it
	// is referring to, and advance it to the next location in the vector.
	cout << *itr << endl;
	// Using * with an iterator retrieves the value it is referring to...
	// kind of like a pointer!
	// We can even use the iterator to mutate the value it's referring to.
	*itr = 100;
	// We can ++ an iterator to move to the next value.
	itr++;
	// We know that the iterator has reached the end of the vector (no more 
	// elements) when it equals the iterator returned by ".end()".

	// Most commonly, we'll use a loop to go through each element in the vector.
	for (auto itr2 = v.begin(); itr2 != v.end(); itr2++) {
		*itr = *itr * 2;
		cout << *itr2;
	}

	findMean(v2);
	findMeanRef(v2);



	// Iterators are used for almost EVERYTHING involving data structures.

	// insert: insert a value at the position of the given iterator.
	v2.insert(v2.begin(), 100);
	v2.insert(v2.begin() + 1, 100);

	// erase: remove the value at the position of the given iterator.
	v2.erase(v2.begin());

	// or, remove all values between two iterators (excluding the end iterator)
	v2.erase(v2.begin(), v2.begin() + 3);

	


	// Some data structures support reverse iterators.
	for (auto rItr = v2.rbegin(); rItr != v2.rend(); rItr++) {
		// Even though we are going in reverse, we still ++ to go to 
		// move between values.
		cout << *rItr << endl;
	}
}

double findMean(vector<int> values) {
	// WARNING:
	// Like ALL TYPES IN C++, passing a vector to a function copies its
	// ENTIRE VALUE, including copies of all elements inside. This can be
	// EXPENSIVE!!!!


	int sum = 0;
	// Declaring vector<int>::iterator is a pain in the ass. C++ has an "auto"
	// keyword that infers the type of a variable based on the value it is
	// assigned.
	for (auto itr = values.begin(); itr != values.end(); itr++) {
		sum += *itr;
	}
	return (double)sum / values.size();
}

double findMeanRef(const vector<int> &values) {
	// By accepting the vector as const reference, we do not duplicate the entire
	// vector, and we promise to not modify it.

	int sum = 0;
	// C++ also has a Java-like "enhanced for-each loop".
	for (int v : values) {
		// CAREFUL: this makes a COPY of each element in the vector.
		sum += v;
		v *= 2; // this modifies the copy, not the original element.
	}
	return (double)sum / values.size();

	// BTW, we run into issues with getting iterators from const vectors.
	// vector<int>::iterator i = values.begin();
	// because values is const, we can't get a normal iterator from it;
	//    that iterator could be used to mutate a value in the vector.
	//    We need a const_iterator instead.
	vector<int>::const_iterator i = values.begin();
	// We can avoid this pain with auto:
	auto i2 = values.begin();
}