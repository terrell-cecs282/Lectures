#include "ModernLinkedStack.h"
#include <iostream>
using namespace std;
void ModernLinkedStack::Push(int value) {
	// Construct a new unique_ptr that is temporarily owned by this method.
	auto newNode = std::make_unique<Node>(value);

	// This Node needs to assume ownership of the head Node, which will link the newNode's mNext
	// to what used to be the head. Doing so temporarily sets mHead to null, but that's OK.
	newNode->mNext = std::move(mHead);

	// We don't want the Node to be destroyed when this method ends, so we 
	// must transfer ownership to the stack's mHead variable.
	mHead = std::move(newNode);

	// Now mHead owns the new node with the requested value. That node links to what used
	// to be the head, but is now the second node. That second node continues to own a link
	// to whatever node came next, etc.
}

int ModernLinkedStack::Pop() {
	// Make a backup of the data to return.
	int temp = mHead->mData;

	// We want mHead to point to mHead's current mNext. We no longer want to own the 
	// current "head" Node; we instead want to own its mNext. By taking ownership of
	// mHead->mNext, we will cause the old mHead to be deleted and retain the second Node
	// as the new mHead.
	mHead = std::move(mHead->mNext);


	return temp;
}

int ModernLinkedStack::Peek() const {
	return mHead->mData;
}
