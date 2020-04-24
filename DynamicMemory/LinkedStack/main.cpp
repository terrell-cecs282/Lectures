#include "BrokenLinkedStack.h"
#include "LinkedStack.h"
#include "BetterLinkedStack.h"
#include "SuperiorLinkedStack.h"
#include "PerfectLinkedStack.h"
#include "ModernLinkedStack.h"
#include <iostream>

using namespace std;

// We'll use this to switch between stack implementations quickly during lecture.
typedef ModernLinkedStack MyStack;

// For the end.
MyStack GetNewStack();

int main() {
	MyStack ps;
	// What happens when we push onto BrokenLinkedStack?
	ps.Push(1);
	ps.Push(2);
	ps.Push(3);
	ps.Push(4);
	ps.Push(5);

	// First problem with LinkedStack: what happens when we pop?
	cout << "Popped: " << ps.Pop() << endl;
	cout << "Top of ps: " << ps.Peek() << endl;
	cout << endl;


	// Even with BetterLinkedStack, we aren't out of the woods. Yes, we clean up Nodes
	// when popping... but what happens when we copy a BetterLinkedStack value?
	if (true) {
		/*MyStack p2 = ps;
		p2.Push(5);
		cout << "Popped: " << p2.Pop() << endl;
		cout << "Popped: " << p2.Pop() << endl;
		cout << "Top of ps: " << ps.Peek() << endl;*/

		// Draw a picture of what happens with BetterLinkedStack.



		// Even if we clean that up, there's a second problem: when p2 goes out
		// of scope, it will be removed from automatic storage. But that only frees
		// the memory associated with its members: 4 bytes for mSize, and 4 or 8 bytes
		// for the mHead pointer (but *not* for the Node that mHead points to). 
		// What about all the Nodes that are in dynamic storage?
	}



	// We have a really nice linked stack once we clear all that up... but it's still
	// not perfect.
	cout << endl;
	MyStack p3 = GetNewStack();
	cout << "Back in main!" << endl << endl;

	cout << "EXITING..." << endl;
}

MyStack GetNewStack() {
	cout << "Creating local linked stack" << endl;
	MyStack local;
	local.Push(99);
	local.Push(98);
	local.Push(97);
	cout << "Returning local linked stack" << endl;
	return local; // return a COPY of this stack
	// "move" local back to p3
}