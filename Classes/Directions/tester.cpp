#include <iostream>
#include "Direction3.h"

using namespace std;

int main(int argc, char* argv[]) {
	Direction3 north = Direction3{ 0, 1, 0 };
	Direction3 east = Direction3{ 1, 0, 0 };
	Direction3 northEast = north + east;
	// What direction is northEast?
	cout << northEast << endl;

	Direction3 x;
	x += north;
	cout << x << endl;
	// What direction is x?

	Direction3 z = -north;
	cout << z << endl;

	// Why doesn't this line compile?
	// Direction3 w = north * east;


}