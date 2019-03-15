#pragma once
#include <memory>
#include <iostream>
// A modern C++ approach to a linked stack, if we had to write the class ourselves instead of
// using the standard library.

class ModernLinkedStack {
private:
	class Node {
		// A Node contains a piece of data, and *owns* a link to the next Node.
		int mData;
		std::unique_ptr<Node> mNext;
		friend class ModernLinkedStack;

	public:
		Node(int data) : mData(data) { }

		// For proof that Nodes are being destroyed without us "deleting" them.
		~Node() { std::cout << "Deleting Node of data " << mData << std::endl; }
	};

	// The stack owns a pointer to its head. That Node owns the next Node, which owns the next, etc.
	// When the stack is destroyed, its mHead will be destructed. If the mHead is not null, 
	// it will destroy the Node object it owns, which will destroy all of its instance variables
	// (especially the pointer to the next Node), down the chain until all the Nodes are deleted!
	std::unique_ptr<Node> mHead;
	int mSize;
public:
	ModernLinkedStack() : mSize(0) {}

	void Push(int value);
	int Pop();
	int Peek() const;

	inline int Size() const { return mSize; }

	
	// Normally C++ would automatically provide a copy constructor and copy assignment operator
	// that do shallow copies. (Remember how this was a problem with SuperiorLinkedStack?)
	// But ModernLinkedStack has an instance variable of type unique_ptr, and unique_ptr doesn't
	// support shallow copies (no copy constructor). So C++ won't give us a copy constructor here,
	// nor copy assignment. We could write them if we wanted to, but I'm being lazy.

	// C++ will also automatically create a move constructor and move assignment operator for us.
	// Those operators will automatically std::move each of our instance variables. That means we
	// don't need to write those ourselves, because to "move" a ModernLinkedStack we would just move
	// our mHead to the other stack's head... which is what C++ will do for us anyways.

	// Finally, we don't need to write a destructor. When a ModernLinkedStack is destroyed, it will
	// run destructors on all its member variables. Destructing mHead will free its Node from the heap,
	// and then run the destructor on its mNext unique_ptr... which will destroy the next Node, and then
	// the next Node, etc., until the entire stack is freed. NOICE.
};