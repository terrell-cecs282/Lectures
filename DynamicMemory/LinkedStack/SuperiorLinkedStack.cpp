#include "SuperiorLinkedStack.h"
#include <iostream>
using namespace std;

SuperiorLinkedStack::SuperiorLinkedStack() : mHead(nullptr), mSize(0) {
}

SuperiorLinkedStack & SuperiorLinkedStack::operator=(const SuperiorLinkedStack & rhs) {
	if (this == &rhs) {
		// Self-assignment. Someone wrote x=x. We don't want to do this code!! Abort!
		return *this;
	}
	cout << "Cloning stack of size " << rhs.mSize << endl;

	mSize = rhs.mSize;
	// "Clone" / "deep copy" other, allocating our own Node for each in other.
	Node* walker = rhs.mHead;

	Node *prev = nullptr;

	while (walker != nullptr) {
		cout << "Cloning node of " << walker->mData << endl;
		Node *mine = new Node{};
		mine->mData = walker->mData;

		if (prev == nullptr) {
			mHead = mine;
		}
		else {
			prev->mNext = mine;
		}
		prev = mine;
		walker = walker->mNext;
	}
	return *this;
}

SuperiorLinkedStack::~SuperiorLinkedStack() {
	// A destructor is called when an instance of this class is destroyed.
	// Instances are destroyed depending on where they are allocated:
	// 1. Automatic storage: when going out of scope.
	// 2. Dynamic storage: when deleted.
	// 3. As a member of a class: when the instance that contains the object is destroyed.

	cout << "Destroying stack of size " << mSize << endl;
	// Clean up the dynamic instances owned by this stack.
	Node *walker = mHead;
	while (walker != nullptr) {
		cout << "Destroying node of " << walker->mData << endl;
		Node *next = walker->mNext;
		delete walker;
		walker = next;
	}
	// For safety, we'll also "reset" the stack.
	mHead = nullptr;
	mSize = 0;
}

SuperiorLinkedStack::SuperiorLinkedStack(const SuperiorLinkedStack &other) {
	*this = other;
}

void SuperiorLinkedStack::Push(int value) {
	cout << "Allocating node for " << value << endl;
	Node *temp = new Node{};
	temp->mData = value;
	temp->mNext = mHead;
	mHead = temp;
	mSize++;
}

int SuperiorLinkedStack::Pop() {
	cout << "Deleting node for " << mHead->mData << endl;

	int temp = mHead->mData;

	Node *tempNode = mHead->mNext;
	delete mHead; // free the Node pointed to by mHead.
	mHead = tempNode;
	mSize--;

	return temp;
}

int SuperiorLinkedStack::Peek() const {
	return mHead->mData;
}
