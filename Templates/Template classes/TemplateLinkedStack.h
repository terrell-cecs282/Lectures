#pragma once
#include <memory>

// A template can apply to a class as well. The template declaration gives type parameters we can use 
// in the entirety of the class.
template <typename TData>
class TemplateLinkedStack {
private:
	class Node {
		TData mData;
		std::unique_ptr<Node> mNext;
		friend class TemplateLinkedStack<TData>;

	public:
		Node(TData data) : mData(data) { }
	};

	std::unique_ptr<Node> mHead;
	int mSize;

public:
	TemplateLinkedStack() : mSize(0) {}

	void Push(TData value) {
		auto newNode = std::make_unique<Node>(value);
		newNode->mNext = std::move(mHead);
		mHead = std::move(newNode);
	}

	TData Pop() {
		TData temp = mHead->mData;
		mHead = std::move(mHead->mNext);
		return temp;
	}

	TData Peek() const {
		return mHead->mData;
	}

	inline int Size() const { return mSize; }
};

