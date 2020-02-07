#include <iostream>
#include <string>
using namespace std;
// Pointers help us avoid duplicating large objects, which is great!
// But they impose a tedious syntax, and they open us to potential
// for abuse.

void passStringPointer(string *p) {
	// We can dereference a pointer to get its value. But 
	// we can't seem to call methods on a pointer.

	// Compare:
	string temp = "Neal";
	int size = temp.size();

	// Error: expression must have class type.
	// int pSize = p.size();
	// AKA: can't use "." with pointers... but you HAVE to be able to call
	// methods somehow!

	int size2 = (*p).size();

	// Dereference p to get its actual string value; call size on that.

	// Ugly! Enter the arrow operator:
	int size3 = p->size();
	// Works great for methods!


	// What about operators?
	// Error: no operator + matches operands: string + string*
	// string c = temp + p;
	string c = temp + *p; // Not terrible.

	// WARNING WARNING WARNING:
	// Indexing pointers does NOT do what you think!
	char n = (*p)[0]; // no nice way to do this.
}

// The tedious syntax with pointers -- especially when passing objects --
// gave rise to another C++ variable type: the reference.
// Like pointers, a reference does not have its own value: it stores a memory
// address of another variable. Like pointers, changing the value of a reference
// changes the value of what it refers to.
// Unlike pointers, references cannot be reassigned to a new address after
// they are created. They also use normal syntax for methods and operators.
void passStringByReference(string &r) {
	// When declaring a variable, & means reference.
	// When using an existing variable, & means "address of" and creates a 
	// pointer!!

	int size = r.size(); // normal "." syntax.
	string concat = r + "Hello"; // normal operator syntax.
	char n = r[0]; // normal indexing syntax.

	r[0] = 'X';
}

// So why choose one over the other?

// Finally, the const keyword, which declares a variable that cannot
// be mutated or reassigned.

void passStringByConstReference(const string &r) {
	int size = r.size(); // Allowed; does not mutate.
	cout << r[0]; // Allowed; does not mutate.

	char c = r[0] + 1; // Allowed; does not mutate.

	// r = "Hello"; //Not allowed; reassigns.
	// r[0] = 'X'; // Not allowed; mutates.
	// r.append("Hello"); Not allowed; mutates.

	string copy = r;
	copy[0] = 'X'; // Allowed; copy is not const, is a full duplicate of r.
}
