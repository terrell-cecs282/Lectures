// This "source file" contains the implementations/definitions of all things
// declared in the corresponding header file.

// Every cpp file is distinct: if we need to do I/O in this file, we must 
// include it ourself.
#include <iostream>
#include <random>

#include "doors.h"
// Quotation marks indicate a file to be found in this project. 

using namespace std;


// C and C++ can create "global variables": values that exist for the
// entirety of the program and can be used anywhere. There are very few
// legitimate reasons to use global variables, and in general you 
// probably should not. Because we don't yet know a better way, we will use
// a global random number generator instead of making one each time
// getPrizeDoor is called.
random_device rd;
default_random_engine engine(rd());


// We now implement the various functions.
int getPrizeDoor() {
	uniform_int_distribution<int> doors(1, 3);
	return doors(engine);
}

int getPrizeNumber() {
	uniform_int_distribution<int> prizes(1, 5);
	return prizes(engine);
}

