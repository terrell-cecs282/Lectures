#pragma once
// Not "broken" as in "too good", "broken" as in "this doesn't work".
class BrokenLinkedStack {
private:
private:
	class Node {
		int mData;
		Node *mNext;
		friend class BrokenLinkedStack;
	};

	Node *mHead;
	int mSize;

public:
	BrokenLinkedStack();
	void Push(int value);
	int Pop();
	int Peek() const;
	inline int Size() const { return mSize; }
};