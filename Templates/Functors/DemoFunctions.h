#pragma once
template<typename TItr>
TItr FindMultipleOfThree(TItr begin, TItr end) {
	for (auto itr = begin; itr != end; itr++) {
		if (*itr % 3 == 0) {
			return itr;
		}
	}
	return end;
}

template<typename TItr>
TItr FindNegative(TItr begin, TItr end) {
	for (auto itr = begin; itr != end; itr++) {
		if (*itr < 0) {
			return itr;
		}
	}
	return end;
}

// Notice how both functions follow the same structure:
//   start at begin; iterate until end; in each iteration, if SOME CONDITION
//   is true, return the current iterator.
// If we could abstract the idea of a "condition" as a data type, we could then
// write a template where the condition itself is a parameter to a generic "FindIf"
// function that could be used in the place of FindMultipleOfThree, FindNegative, etc.

// But how do we do that? We need a way of expressing a condition as a variable, so we
// could then "pass" in a condition as a parameter to a function.

template<typename TItr, typename TCond>
TItr FindIf(TItr begin, TItr end, TCond predicate) {
	// As always, start at begin and go until end.
	for (auto itr = begin; itr != end; itr++) {
		// Here is the tricky part. How do we represent a condition as a type? By imagining
		// what we can do with a condition: we can evaluate it by invoking its logic. That
		// sounds like a function, and indeed! A condition is just a function that returns true or false.
		if (predicate(*itr)) {
			return itr;
		}
	}
	return end;
}
 // Now how do we use this thing? Go back to main.


// Our "Negative Integer" class.
struct NegativeCondition {
	bool operator()(int value) {
		return value < 0;
	}
};

struct MultipleOfThreeCondition {
	bool operator()(int value) {
		return value % 3 == 0;
	}
};

struct MultipleOfFiveCondition{
	bool operator()(int value) {
		return value % 5 == 0;
	}
};



struct BetweenOneAndTenCondition {
	bool operator()(int value) {
		return 1 <= value && value <= 10;
	}
};




















struct MultipleOfX {
	// A class with a public variable automatically gets a constructor that initializes
	// that variable.
	int divisor;
	bool operator()(int value) {
		return value % divisor == 0;
	}
};







