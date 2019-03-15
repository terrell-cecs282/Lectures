#pragma once
#include <memory>
#include <iostream>
class ModernLinkedList {
private:
	class Node {
		// A Node contains a piece of data, and *owns* a link to the next Node.
		int mData;
		std::unique_ptr<Node> mNext;
		friend class ModernLinkedList;

	public:
		Node(int data) : mData(data) { }

		// For proof that Nodes are being destroyed without us "deleting" them.
		~Node() { std::cout << "Deleting Node of data " << mData << std::endl; }
	};

	std::unique_ptr<Node> mHead;
	int mSize;

public:
	ModernLinkedList() : mSize(0) {}
	inline int Size() const { return mSize; }

	// Methods to insert new data.
	// Adds a new "last" item.
	void PushBack(int value);
	// Adds a new "first" item.
	void PushFront(int value);
	// Adds a new item at the given index, so that the given value can be retrieved at that index.
	// All values that that index or larger are "moved back" by 1.
	void Insert(int index, int value);

	// Methods to remove data.
	// Remove the "last" item.
	void PopBack();
	// Remove the "first" item.
	void PopFront();
	// Remove the item at the given index.
	void RemoveAt(int index);
	// Removes ALL data from the list, resetting it to be empty.
	void Clear();


	// Retrieves the data item at the given index, by walking the list to that position
	// and returning the data in the Node at that index. Can also be used to "set" the value
	// at the given index, if that index exists.
	int& operator[](int index);


	// Prints the entire list for debugging.
	void PrintList() const;

};
