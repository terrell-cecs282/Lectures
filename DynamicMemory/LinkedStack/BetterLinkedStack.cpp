#include "BetterLinkedStack.h"
#include <iostream>
using namespace std;

BetterLinkedStack::BetterLinkedStack() : mHead(nullptr), mSize(0) {
}

void BetterLinkedStack::Push(int value) {
	cout << "Allocating node for " << value << endl;
	Node *temp = new Node{};
	temp->mData = value;
	temp->mNext = mHead;
	mHead = temp;
	mSize++;
}

// The stack is responsible for the dynamic objects that it owns, which includes
// any Node object in the chain. Popping a value from the stack should free the Node
// that used to store it.
int BetterLinkedStack::Pop() {
	cout << "Deleting node for " << mHead->mData << endl;

	int temp = mHead->mData;

	Node *tempNode = mHead->mNext;
	delete mHead; // free the Node pointed to by mHead.
	mHead = tempNode;
	mSize--;

	return temp;
}

// Looks much better!
// But still not good enough!!!

int BetterLinkedStack::Peek() const {
	return mHead->mData;
}
