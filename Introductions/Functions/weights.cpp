// The first step in the C++ compilation process is called the preprocessor.
// It handles all commands that start with a #, including #include, which are
// called "preprocessor directives".
// Once the preprocessor applies its logic to the entire program, the resulting
// code is sent to the compiler.

// #include locates, opens, and copy/pastes the contents of another file into
// this one.
#include <iostream>

// There are many other preprocessor commands. Some are devious, like 
// "#define", which creates a find/replace "macro".

#define neal int
// I can now use "neal" in my code, and when I compile, the preprocessor
// will replace that text with "int.

// I can be even worse.
#define float int

// We'll use other directives later.

using namespace std;

// A simple program to calculate 1RM when weight lifting.
int main(int argc, char* argv[]) {
	cout << "Enter your lift weight and reps: " << endl;
	
	double w;
	neal r;
	cin >> w >> r;
	

	double oneRM = calculateOneRM(w, r);
	cout << "Your 1RM is " << oneRM << endl;


	// Sadly, this code does not compile, because C++ is a top-down compiler
	// and needs to know that a function exists by the time we attempt to call
	// that function. On line 34, C++ does not know that calculateOneRM exists,
	// because it is defined on line 47. Bummer.
}

// Estimates the maximum amount of weight one can lift for a single repetition,
// if one can lift the given weight for the given number of repetitions.

// Formula: 1RM = 1 (if reps == 1);
//				= w * (1 + r/30) otherwise
double calculateOneRM(double weight, int reps) {
	if (reps == 1) {
		return weight;
	}
	return weight * (1 + reps / 30.0);
}