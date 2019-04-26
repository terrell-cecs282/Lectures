#pragma once
#include <memory>

template <typename TData>
class TemplateLinkedStack {
private:
	class Node {
		TData mData;
		std::unique_ptr<Node> mNext;
		friend class TemplateLinkedStack<TData>;
		friend class TemplateLinkedStack<TData>::LinkedStackIterator;

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

	// ITERATOR CODE
	// An iterator is an object that tracks a current "position" within a data structure. 
	// It needs to be compatible with templates that create and advance iterators, by supporting:
	// 1. operator*, to retrieve the value at the current position.
	// 2. operator++ (pre- and post-increment), to move to the next position.
	// 3. operator== and !=, to know if the iterator is at the end of a range.
	// And OPTIONALLY:
	// 4. operator+, to advance X positions at a time.
	class LinkedStackIterator {
		typedef TemplateLinkedStack<TData>::Node Node; // for convenience

		// An iterator does not *own* a Node, it merely borrows its data. 
		// mCurrent points to the next Node whose data will be returned by operator*. 
		// If the iterator reaches the end of the stack, its mCurrent will be null.
		Node* mCurrent;

	public:
		// Constructs an iterator at the given starting node.
		LinkedStackIterator(Node* current) : mCurrent(current) {}

		// Retrieve the TData item at the current position.
		TData& operator*() {
			return mCurrent->mData;
		}

		// Compares two iterators to see if they are at the same position.
		bool operator==(LinkedStackIterator rhs) {
			return mCurrent == rhs.mCurrent;
		}

		// Compares two iterators to see if they are not at the same position.
		bool operator!=(LinkedStackIterator rhs) {
			return mCurrent != rhs.mCurrent;
		}

		// Pre-increment advances the iterator to the next position, and returns the new position.
		LinkedStackIterator& operator++() {
			mCurrent = mCurrent->mNext.get();
			return *this;
		}

		// Post-increment advances the iterator to the next position, but returns the old position.
		LinkedStackIterator operator++(int) {
			LinkedStackIterator temp{ mCurrent };
			mCurrent = mCurrent->mNext.get();
			return temp;
		}

		// operator+ returns a new iterator that is advanced forwards from the current position.
		LinkedStackIterator operator+(int steps) {
			LinkedStackIterator temp{ mCurrent };
			for (int i = 0; i < steps; i++) {
				++temp;
			}
			return temp;
		}
	};

	// This typedef allows client code -- especially templates -- to declare a variable of type
	// "T::iterator" without having to know the real class name is "LinkedStackIterator".
	typedef LinkedStackIterator iterator;

	// begin: creates an iterator at the top of the stack.
	iterator begin() {
		return LinkedStackIterator{ mHead.get() };
	}

	// end: creates an iterator that indicates the "end" of the stack -- nullptr.
	iterator end() {
		return LinkedStackIterator{ nullptr };
	}
};

