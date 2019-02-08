
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[]) {
	// Local variables are given memory in AUTOMATIC STORAGE, and store
	// their value at that memory location. 

	int x = 10;
	// x is in automatic storage. When x goes out of scope, its memory will
	// be destroyed (reclaimed).

	// Unlike Java, this is true of ALL TYPES in C++, even "objects".
	random_device rd;
	// We might not be able to "draw" it, but this variable also lives in
	// automatic storage.

	// When a variable is assigned to another, it is copied "by value":
	// the actual value in the variable's memory is copied to the new variable.
	int y = x;

	// If we change the second variable, the first is not affected.
	y++;
	// What does x equal?

	// But sometimes we want a mutation to one variable to affect another
	// variable's value. We achieve this by creating a "pointer": a variable
	// whose value is not an instance of its type, but is a memory address
	// of another variable of that type.

	int *p; // The * declares a pointer.
	p = &x; // The & is the "address of" operator.

	// p is still in automatic storage, because it is a local variable.
	// However, its value is not an integer; its value is a POINTER (address)
	// to another variable of type int.

	// I can do three things with a pointer variable:
	// 1. Read its current value.
	cout << *p << endl; // "Dereferencing"

	// 2. Assign a new address (point to a new target).
	p = &y;

	// 3. Assign a new value to the target.
	*p = 100;

	// Pointers can be used with ANY type.
	double z;
	double *p2 = &z;
	*p2 = 3.14159;
	cout << z << endl; // What gets printed?

	// Assigning a pointer to another pointer makes them point to the same
	// target.
	double *p3 = p2;
	*p2 = 2.781;
	cout << *p3 << endl;

	// If a pointer goes out of scope, only the pointer itself is reclaimed...
	// not necessarily the value it is pointing to.
	if (true) {
		int *scopedPointer = &x;

	} // here, scopedPointer is lost... but x is still alive.
}