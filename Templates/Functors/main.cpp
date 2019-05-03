#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#include "DemoFunctions.h"

using namespace std;


int main() {
	vector<int> values = { 1, 6, 3, -4, 10 };

	// Suppose I want to see if values contains the number 3.
	auto itr = std::find(values.begin(), values.end(), 3);
	cout << "Found " << *itr << endl;
	// Piece of cake!

	// But suppose I want to see if values contains a multiple of 3?
	// I have to write a function :(.
	itr = FindMultipleOfThree(values.begin(), values.end());
	cout << "Found " << *itr << endl;

	// How about if there's a negative value?
	itr = FindNegative(values.begin(), values.end());
	cout << "Found " << *itr << endl;
	// Or any other potential condition? Ugh. Let's head to DemoFunctions.h




	// To call our FindIf, we need to supply a condition to use to identify the value
	// we're looking for. From the template, we see that the condition parameter will ONLY
	// be used with the () as a function call. This is operator() taking a parameter of 
	// whatever *itr returns -- that is, the type of data in the iterator.
	// SO we just need to invent a class that has operator() taking an int parameter.
	// Back to DemoFunctions.h!

	// Now we can use FindIf, where the last parameter is a value of type NegativeCondition.
	itr = FindIf(values.begin(), values.end(), NegativeCondition{});
	cout << "Found " << *itr << endl;
	// Amazing. If we want multiple of three, just make a new class!

	itr = FindIf(values.begin(), values.end(), MultipleOfThreeCondition{});
	cout << "Found " << *itr << endl;

	// Classes like this that only have operator() and are used as a "function" are historically
	// called "functors".
	// Thankfully, C++11 has this function already: std::find_if

	itr = std::find_if(values.begin(), values.end(), MultipleOfThreeCondition{});
	cout << "Found " << *itr << endl;


	// Having saved ourselves from writing all our "FindX" functions, let's now be motivated
	// to avoid a potential future full of "MultipleOfFourCondition", "MultipleOfFiveCondition", etc.
	// by creating a functor class that is constructed with a divisor parameter.
	itr = std::find_if(values.begin(), values.end(), MultipleOfX{ 5 });
	cout << "Found " << *itr << endl;


	
}


