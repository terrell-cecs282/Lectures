#include "Animal.h"
#include "Dog.h"
#include <memory>
using namespace std;

int main(int argc, char* argv[]) {
	// Inheritance
	Dog goodBoye{ 80, "snax" };
	// What methods can we call on this Dog?
	


	// Polymorphism
	Animal &r = goodBoye;
	Animal *p = &goodBoye;
	unique_ptr<Animal> u = std::make_unique<Dog>(30, "cheese");



	// Dynamic dispatch.
	Animal a{ 0 };
	a.Speak();
	u->Speak();
	// Even though the compiler sees a and u as both being Animals, it is
	// Dog's Speak() that gets called on u. Dynamic dispatch (method target is
	// determined at run time)!
}