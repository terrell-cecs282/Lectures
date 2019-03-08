#pragma once
// A linked stack with proper C++11 memory management, including move support.
class PerfectLinkedStack {
private:
	class Node {
		int mData;
		Node *mNext;
		friend class PerfectLinkedStack;
	};

	Node *mHead;
	int mSize;

public:
	// The "rule of 5": take the rule of 3, and add a MOVE CONSTRUCTOR 
	// and MOVE ASSIGNMENT OPERATOR.
	PerfectLinkedStack(const PerfectLinkedStack &other);
	PerfectLinkedStack& operator=(const PerfectLinkedStack &rhs);
	~PerfectLinkedStack();

	// Move constructor
	PerfectLinkedStack(PerfectLinkedStack &&other);
	// Move assignment
	PerfectLinkedStack& operator=(PerfectLinkedStack &&rhs);


	PerfectLinkedStack();

	void Push(int value);
	int Pop();
	int Peek() const;

	inline int Size() const { return mSize; }
};