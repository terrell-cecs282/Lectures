#include <iostream>
#include <array> // for declaring modern C++-style arrays
using namespace std;

int main(int argc, char* argv[]) {
	// The std::array type declares an array. The syntax is a little funny.
	std::array<int, 5> myArray; // declares an array of 5 integers.

	// Tragically, the size of a C++ array MUST BE KNOWN AT COMPILE TIME. 
	// There are reasons for this that we'll discuss later.

	// The size of an array is considered part of its type, and two arrays
	// are not the same type unless their sizes are the same.

	std::array<int, 6> second; // does NOT have the same type as myArray.

	// The elements of an array are UNINITIALIZED.
	cout << myArray[0] << endl;

	// Unless we initialize them!
	std::array<int, 3> init = { 10, 11, 12 }; // "initializer list"

	// Or:
	std::array<int, 3> init2 = { 0 }; // all values set to 0.

	// We index them the same as in Java.
	init2[1] = 100;
	cout << init2[1] << endl;

	// We can get their size:
	cout << init2.size() << endl; 
	// but that is of somewhat dubious use, since the size is always known
	// at compile time.


	// Awkwardness with C++ arrays:
	// * Can't write functions that operate on any-length array, since different
	//   lengths are different types.
	// * Size must be known at compile time: can't base it on input values or
	//   parameters.
}
