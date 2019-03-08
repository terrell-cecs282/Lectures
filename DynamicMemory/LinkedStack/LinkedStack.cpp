#include "LinkedStack.h"
#include <iostream>
using namespace std;


// Reminder: this class may have memory management issues. 

LinkedStack::LinkedStack() : mHead(nullptr), mSize(0) {
}

void LinkedStack::Push(int value) {
	cout << "Allocating node for " << value << endl;
	Node *temp = new Node{};
	temp->mData = value;
	temp->mNext = mHead;
	mHead = temp;
	mSize++;
}

int LinkedStack::Pop() {
	int temp = mHead->mData;
	mHead = mHead->mNext;
	mSize--;
	return temp;
}

int LinkedStack::Peek() const{
	return mHead->mData;
}
