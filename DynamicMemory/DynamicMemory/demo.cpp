#include "DemoClass.h"
#include <iostream>
using namespace std;

DemoClass ReturnByValue();
DemoClass& ReturnByReference();
DemoClass* ReturnByPointer();

int main(int argc, char* argv[]) {
	DemoClass d1; // This object takes 40KB of automatic storage, which is quite a lot!
	DemoClass d2 = ReturnByValue();
	DemoClass d3 = ReturnByReference();
	DemoClass *p = ReturnByPointer();
	

	cout << p->front();

	// Unlike Java, dynamic storage in C++ is completely programmer-controlled. We
	// are responsible for "freeing" dynamic objects when we no longer need them.
	delete p;
	// The delete keyword frees the dynamic object pointed to by p.
	// WARNING: p itself still points to that dynamic memory, and nothing stops us
	// from using p.

	cout << p->front();
}

DemoClass ReturnByValue() {
	return DemoClass{};
}

DemoClass& ReturnByReference() {
	DemoClass temp{ };
	return temp;
}

DemoClass* ReturnByPointer() {
	// If we want an object to have a lifetime longer than its scope, we must
	// allocate it somewhere other than automatic storage. The alternative: dynamic 
	// storage.

	DemoClass *d = new DemoClass(); // constructs a DemoClass instance in dyamic storage.
	// LOTS OF QUESTIONS!
	// Why does "new" return a pointer?
	
	
	// Where is d stored?


	// Where is the DemoClass instance stored?


	// Draw a picture!


	return d;
}
