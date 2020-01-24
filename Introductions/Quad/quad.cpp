#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	double a, b, c;

	cout << "Enter a b and c:";
	cin >> a >> b >> c;

	double descriminant = b * b - 4 * a * c;
	if (descriminant < 0) {
		cout << "No real solutions" << endl;
		return 0;
	}
	if (descriminant == 0) {
		cout << "One solution: x = " << -b / (2 * a) << endl;
	}
	else {
		double sq = sqrt(descriminant);
		cout << "Two solutions: x1 = " << (-b + sq) / (2 * a)
			<< "; x2 = " << (-b - sq) / (2 * a) << endl;
	}

}