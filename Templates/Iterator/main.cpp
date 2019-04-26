#include <iostream>
#include "TemplateLinkedStack.h"
using namespace std;

template<typename TItr, typename TData>
int Count(TItr, TItr, const TData &);

int main() {
	TemplateLinkedStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(2);

	// Because we wrote the ::iterator typedef, begin(), end(), operator*, and operator++, 
	// we can use the C++ enhanced for loop.
	for (int i : stack) {
		cout << i << endl;
	}
	cout << endl;
	// Recall that it compiles to this exact set of statements:
	TemplateLinkedStack<int>::iterator itr = stack.begin();
	TemplateLinkedStack<int>::iterator end = stack.end();
	while (itr != end) {
		cout << *itr << endl;
		++itr;
	}
	cout << endl;

	// Look back at our "Count" function... can we now use a TemplateLinkedStack with that template?
	cout << "2 occurs " << Count(stack.begin(), stack.end(), 2) << " times in the stack" << endl;
	// and with operator+, we can narrow the range of search:
	cout << "2 occurs " << Count(stack.begin(), stack.begin() + 3, 2) << " times among the top 3 elements" << endl;
}

template<typename TItr, typename TData>
int Count(TItr begin, TItr end, const TData& value) {
	int count = 0;
	for (TItr itr = begin; itr != end; itr++) {
		if (*itr == value) {
			count++;
		}
	}
	return count;
}