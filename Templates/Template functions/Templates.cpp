#include "Templates.h"
#include <string>
using namespace std;

int max(int a, int b) {
	return a < b ? b : a;
}

double max(double a, double b) {
	return a < b ? b : a;
}

long max(long a, long b) {
	return a < b ? b : a;
}

long long max(long long a, long long b) {
	return a < b ? b : a;
}

string max(string a, string b) {
	return a < b ? b : a;
}





// Suppose I wanted to use this code with double instead of int. What has to change?
// Does that seem like an efficient idea?

