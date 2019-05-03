#include "Owner.h"
#include <string>
#include <memory>
using namespace std;
int main() {
	Owner<string> o = make_owner<string>("Hello");
	Owner<string> o2 = std::move(o);
	string copy = *o2;
	string *borrowed = o2.get();

}