#include <iostream>
#include <array>
using namespace std;
void changeOne(int *);
void getCannon(double *, double *);

int main(int argc, char* argv[]) {
	// What can pointers do for us? Why bother?
	int x = 0, y = 0;

	// By passing a pointer to a local variable to another function, that
	// function can change OUR local values!
	changeOne(&x);
	cout << x << endl;
	// That's not a GREAT justification... we could have just returned 100
	// from that function and assigned it here.


	// In passing x's memory address, the value of x is NOT duplicated. 
	// changeOne receives x's memory address as its parameter, not a copy 
	// of x's value... in contrast to passing any non-pointer value.

	// So that's the first real reason to use pointers: to pass a value without
	// duplicating it, especially important for large (memory wise) values.



	// What if we wanted to change TWO values? Can we return two values
	// from a function? NO!
	double angle, gunpowder;
	getCannon(&angle, &gunpowder);
	// So there's our second reason: multiple return values.

	return 0;
}

void changeOne(int *a) {
	*a = 100;
}

void getCannon(double *ang, double *gun) {
	*ang = -1;
	while (*ang < 0 || *ang > 90) {
		cout << "Enter an angle between 0 and 90: ";
		cin >> *ang;
	}
	*gun = 0;
	while (*gun <= 0) {
		cout << "Enter a positive amount of gunpowder: ";
		cin >> *gun;
	}
}

// For now, a pointer is the ONLY way to give permission for a function
// to mutate a value created by a different scope.