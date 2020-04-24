#pragma once

class BetterLinkedStack {
private:
	class Node {
		int mData;
		Node *mNext;
		friend class BetterLinkedStack;
	};

	Node *mHead;
	int mSize;
	// member-wise shallow copy
public:
	BetterLinkedStack();
	void Push(int value);
	int Pop();
	int Peek() const;
	inline int Size() const { return mSize; }
};