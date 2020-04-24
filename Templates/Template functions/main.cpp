#include "Templates.h"
#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;


int main() {
	unique_ptr<int> bn = make_unique<int>(0);
	
	vector<unique_ptr<int>> v2;
	v2.push_back(bn);


	// By including the template in this file, we can use max2 with int...
	int x = 5, y = 10;
	// We can explicitly invoke the template with its parameter T...
	cout << max2<int>(x, y) << endl;
	// Template instantiation occurs here!


	// ... or we can leave it to the compiler to infer the type.
	cout << max2(x, y) << endl;


	// We can also use the function with double...
	double a = 3.14, b = 2.81;
	cout << max2(a, b) << endl;

	// ... or with lots of other types!

	string c = "goodbye", d = "hello";
	cout << max2(c, d) << endl;


	

	std::array<int, 8> arr = { 5, 1, 4, 6, 2, 1, 7, 1 };
	cout << "The value 1 appears " << CountArray(arr, 1) << " times in the array" << endl;
	SelectionSort(arr);
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> v = { 4, 1, 2, 5, 4, 9 };

	cout << "The value 4 appears " << Count(v.begin(), v.end(), 4) << " times in the vector" << endl;
	cout << "The value 1 STILL appears " << Count(arr.begin(), arr.end(), 1) << " times in the array" << endl;

	string s = "Hello, world!";
	cout << "The letter 'l' appears " << Count(s.begin(), s.end(), 'l') << " times in the string" << endl;
	return 0;
}

