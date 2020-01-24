#include <iostream>
// For random numbers.
#include <random>

using namespace std;

int main() {
	// Create only ONE random_device.
	random_device rd{};
	// Create only ONE engine.
	default_random_engine engine{ rd() };

	// Create a different distribution for each of your needs. The parameters are INCLUSIVE.
	uniform_int_distribution<int> range{ 1, 10 };

	// Invoke the range with the engine to get a value in the specified range.
	int r = range(engine);
	int r2 = range(engine);

	uniform_int_distribution<int> range2{ 9, 17 };

	cout << range(engine) << " " << range2(engine) << endl;

}