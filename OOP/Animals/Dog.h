#pragma once
#include "Animal.h"
#include <string>
#include <iostream>
// Two forms of inheritance: public and private.
// public inheritance is what you get in Java: everyone knows that you inherit
// from the given base class.
// private inheritance is rarely used: you inherit from the base class but no
// one knows it, and so you can't use polymorphism.
class Dog : public Animal {
private:
	std::string mFavoriteFood;

	// Besides the fields that you see here, Dog also has the fields of Animal,
	// namely "mWeight". But because that variable was declared private,
	// we cannot access it directly in Dog.





public:
	// When writing a derived-class constructor, we MUST use the initializer list
	// to call one of the base-class constructors. Otherwise, the variables
	// we inherited would be unitialized!
	Dog(double weight, std::string favoriteFood)
		: Animal(weight), mFavoriteFood(favoriteFood) {
	}

	inline const std::string& GetFavoriteFood() const {
		return mFavoriteFood;
	}





	void Speak() const override {
		std::cout << "Meow!" << std::endl;
	}
};