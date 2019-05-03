#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "DemoFunctions.h"
using namespace std;

int main() {
	// Another motivation, for now: even creating the MultipleOfX class took 4 lines so that I could
	// do something pretty trivial: find a multiple of 5. Do I really need to make a CLASS to do this?
	// Wouldn't it be nice if I could instead just temporarily conjure up a function to test a number
	// as a multiple of 5? And then throw that function away now that it's not needed. This is the idea
	// of a "lambda function" or "anonymous function" that most languages support... including C++.
	vector<int> values = { 1, 6, 3, -4, 10 };

	auto itr = std::find_if(values.begin(), values.end(),
		// Syntax: [](parameters) { body }
		[](int value) { return value % 5 == 0; }
	);
	cout << "Found " << *itr << endl;


	// This gives me an idea.
	vector<unique_ptr<string>> strs; // suppose this is filled.
	
	auto sItr = std::find_if(strs.begin(), strs.end(),
		[](unique_ptr<string>& p) { return p->size() > 5; });
	cout << "Found " << **sItr << endl;
	// What will this find?

	// Does that seem like it might help your Project?



	// What's interesting here is that the lambda function we created is actually an object
	// of some type. What type? std::function, a template type that encapsulates "a function".
	// To use a function, we must know its return type and the types of its parameters; thus,
	// std::function must too.

	std::function<bool(int)> intPred = [](int value) { return value % 5 == 0; };
	// The "type" bool(int) represents a function taking int parameter, returning bool.
	// We can pass this variable to find_if as before:
	itr = std::find_if(values.begin(), values.end(), intPred);

	

	// The compiler can hook an std::function object to any "callable" value, including 
	// functions and functors.
	intPred = NegativeCondition{};
	intPred = IsNegative;

	// This lets us do interesting things, like dynamic dispatch without inheritance.
	int x;
	cin >> x;
	if (x == 0) {
		intPred = IsPositive;
	}

	cout << intPred(100) << endl; // do you know what the output will be right now?
	}
}
