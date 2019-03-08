#pragma once
// A linked stack with proper C++98 memory management. Still not the best it can be!
class SuperiorLinkedStack {
private:
	class Node {
		int mData;
		Node *mNext;
		friend class SuperiorLinkedStack;
	};

	Node *mHead;
	int mSize;

public:
	// The "rule of 3": if you use dynamic memory, you MUST define the copy constructor,
	// copy assignment operator, and destructor.
	SuperiorLinkedStack(const SuperiorLinkedStack &other);
	SuperiorLinkedStack& operator=(const SuperiorLinkedStack &rhs);
	~SuperiorLinkedStack();

	SuperiorLinkedStack();

	void Push(int value);
	int Pop();
	int Peek() const;

	inline int Size() const { return mSize; }
};