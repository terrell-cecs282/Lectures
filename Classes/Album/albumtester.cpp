#include "Album.h"
#include <string>
#include <iostream>
#include <array>
using namespace std;

void UseAlbums(const Album& a1, Album a2);

int main(int argc, char* argv[]) {
	// Two flavors of constructing an Album.
	Album theBoss = Album{ "Born to Run", "Bruce Springsteen", 1975, 6000000 };
	Album zoso{ "Untitled", "Led Zeppelin", 1971, 23000000 };

	// Can't do this:
	// Album empty;
	// because all objects are constructed immediately (no "null" for objects),
	// and there is not an Album constructor with no arguments.

	cout << theBoss.GetReleaseYear() << endl;
	cout << zoso.GetArtist() << endl;

	// Can't do this:
	// cout << theBoss;
	// because there is no known way of using an Album with cout.

	// But we can do this:
	cout << (string)theBoss << endl;
	// because we have an operator std::string.


	// Demonstrate a few unfortunate behaviors or our implementation.
	UseAlbums(theBoss, zoso);

	// Can't declare an array of albums -- what value would each entry in the 
	// array take on?
	// std::array<Album, 3> albums;

	// OK, so we actually can, if we know all the elements right now:
	std::array<Album, 2> albums2 = { theBoss, zoso };
}

void UseAlbums(const Album& a1, Album a2) {
	// Remember: a1 is a const reference to the given argument, while a2
	// is a full duplicate of the second argument.

	a2.SetSales(1000);
	// Does this change the argument that was passed?

	// Can we do this?
	// a1.SetSales(1000);
	// Why or why not?


	// Can we do this?
	// a1.GetSales();
	// Why or why not?
}