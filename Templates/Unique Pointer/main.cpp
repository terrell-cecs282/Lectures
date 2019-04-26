#include "Owner.h"
#include <string>
#include <memory>
using namespace std;
int main() {
	Owner<string> o = make_owner<string>("Hello");
	unique_ptr<string> u;


}