#include "BrokenLinkedStack.h"

BrokenLinkedStack::BrokenLinkedStack() : mHead(nullptr), mSize(0) {
}

// Add a new value on top of the stack, by making a Node to hold the data
// and linking that node in as the head of the existing linked structure.
void BrokenLinkedStack::Push(int value) {
	Node temp{};
	temp.mData = value;
	temp.mNext = mHead;
	mHead = &temp; // WARNING!!!!
	mSize++;
}

// Remove the top value of the stack, which is the node at the head of the linked
// structure. Return its data.
int BrokenLinkedStack::Pop() {
	int temp = mHead->mData;
	mHead = mHead->mNext;
	mSize--;
	return temp;
}

int BrokenLinkedStack::Peek() const {
	return mHead->mData;
}
