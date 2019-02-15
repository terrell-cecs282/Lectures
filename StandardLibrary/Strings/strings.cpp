#include <iostream>
#include <string> // for the string type.

using namespace std;

void passStringByValue(string a);
void passStringByPointer(string *p);

int main(int argc, char* argv[]) {
	// strings work very similarly as in Java, with notable exceptions.
	string name = "Neal";

	// First exception: like ALL C++ values, strings are copy-by-value.
	string second = name;
	// second is a full duplicate of "name" with its own value, NOT a reference
	// to the same string as would happen in Java.

	// Second exception: can index strings like arrays.
	cout << name[0] << endl;

	// Third: C++ strings are MUTABLE.
	string third = name;
	second[0] = 'D'; // assign an individual character at index 0.
	third[0] = 'S';
	cout << name << " made a " << second << " with a " << third << endl;

	// The copy-by-value thing is important, especially for long strings.
	string big = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
	cout << "This string is " << big.size() << " bytes in size" << endl;

	passStringByValue(big); // makes a DUPLICATE of the string :(
	passStringByPointer(&big); // no duplicate!
}

void passStringByValue(string a) {
	cout << "Received " << a << " by value." << endl;
}

void passStringByPointer(string *p) {
	cout << "Received " << *p << " by value." << endl;
}