#pragma once

bool IsNegative(int value) {
	return value < 0;
}

bool IsPositive(int value) {
	return value > 0;
}

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

struct MultipleOfX {
	// A class with a public variable automatically gets a constructor that initializes
	// that variable.
	int divisor;
	bool operator()(int value) {
		return value % divisor == 0;
	}
};