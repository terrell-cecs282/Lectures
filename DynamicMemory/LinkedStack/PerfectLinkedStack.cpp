#include "PerfectLinkedStack.h"
#include <iostream>
using namespace std;

PerfectLinkedStack::PerfectLinkedStack() : mHead(nullptr), mSize(0) {
}

PerfectLinkedStack & PerfectLinkedStack::operator=(const PerfectLinkedStack & rhs) {
	if (this == &rhs) {
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

PerfectLinkedStack::~PerfectLinkedStack() {
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

PerfectLinkedStack::PerfectLinkedStack(const PerfectLinkedStack &other) {
	*this = other;
}

// The MOVE ASSIGNMENT OPERATOR. "Steals" the dynamic data from an existing stack.
PerfectLinkedStack& PerfectLinkedStack::operator=(PerfectLinkedStack &&rhs) {
	if (this == &rhs) {
		return *this;
	}

	cout << "Moving stack of size " << rhs.mSize << endl;
	
	// Delete our current mHead, since we are taking over someone else's.
	delete mHead;

	// Copy fields.
	mSize = rhs.mSize;
	mHead = rhs.mHead;

	// Let the other object know they've been taken over.
	rhs.mSize = 0;
	rhs.mHead = nullptr;

	return *this;
}

PerfectLinkedStack::PerfectLinkedStack(PerfectLinkedStack &&other)
	: mSize(other.mSize), mHead(other.mHead) { // this is a shallow copy of the head node
	cout << "Move constructor" << endl;

	// Let the other object know they've been taken over.
	other.mSize = 0;
	other.mHead = nullptr;
}

void PerfectLinkedStack::Push(int value) {
	cout << "Allocating node for " << value << endl;
	Node *temp = new Node{};
	temp->mData = value;
	temp->mNext = mHead;
	mHead = temp;
	mSize++;
}

int PerfectLinkedStack::Pop() {
	cout << "Deleting node for " << mHead->mData << endl;

	int temp = mHead->mData;

	Node *tempNode = mHead->mNext;
	delete mHead; // free the Node pointed to by mHead.
	mHead = tempNode;
	mSize--;

	return temp;
}

int PerfectLinkedStack::Peek() const {
	return mHead->mData;
}
