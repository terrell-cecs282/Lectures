#pragma once

// In this lecture, I will put all implementations inside class declarations.
// This is not the preferred C++ style, but it is shorter.
#include <iostream>
class Animal {
private:
	double mWeight;

public:
	Animal(double weight) : mWeight(weight) {
	}

	inline double GetWeight() const {
		return mWeight;
	}

	void SetWeight(double weight) {
		mWeight = weight;
	}







	inline virtual void Speak() const {
		std::cout << "I am an animal!" << std::endl;
	}
};