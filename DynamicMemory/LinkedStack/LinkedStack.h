#pragma once
// A stack of integers, implemented using a singly linked list.

// This is a JAVA-STYLE implementation of this type. It may have many errors in its
// memory management.
class LinkedStack {
private:
	class Node {
		int mData;
		Node *mNext;
		friend class LinkedStack;
	};

	Node *mHead;
	int mSize;

public:
	LinkedStack();
	void Push(int value);
	int Pop();
	int Peek() const;
	inline int Size() const { return mSize; }
};