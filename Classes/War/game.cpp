#include "Card.h"
#include "Deck.h"
#include <array>
#include <iostream>
using namespace std;


int PlayOneRound(Deck &p1, Deck &p2);

#define TESTING

// A C++ application can only have one main. This main will only be compiled if the
// symbol TESTING is #define'd. Otherwise it will be ignored.
#ifdef TESTING
int main(int argc, char* argv[]) {
	// Demonstrate our class. 
	Deck d1 = Deck{};
	cout << d1 << endl;

	// C++ gives us a "copy constructor" for free. It is used anytime we construct
	// a new object by assigning an old object. There are three syntaxes:
	Deck d2 = d1;
	Deck d3{ d1 };
	Deck d4(d1);
	// In all three cases, we have a Deck being declared for the first time, with
	// an existing deck being offered as its initial value. This is copy constuction.

	// The default copy constructor does a recursive copy-construct on the object's
	// instance variables. Fundamental types copy neatly. Pointers and references
	// copy *addresses*, not the thing they point/refer to (this will be important later).
	// Well-designed classes, like those from the standard library, duplicate fully.

	// Copy constructors are used when: 
	// - creating a new object explicitly; 
	// - passing an object as an argument to a function by value; 
	// - returning an object by value.

	cout << endl << "Shuffling... " << endl;
	d1.Shuffle();
	cout << d1 << endl << endl;

	// Since d2/3/4 are distinct objects, shuffling d1 does not affect the others.
	cout << "Unshuffled: " << d2 << endl;

	// We also get a free "copy assignment" operator. 
	d2 = d1;
	// d2 already exists; this is NOT CONSTRUCTION. It is assignment, and it copies
	// the rhs value to the lhs. Again, most types behave how you would hope with
	// copy assignment, including vectors.

	Card c = d1.DealOne();
	cout << "Dealt " << c << endl;
	cout << d1 << endl;
}


#else
int main(int argc, char* argv[]) {
	Deck d1 = Deck{};
	d1.Shuffle();

	Deck d2;
	d2.Shuffle();

	std::array<int, 3> wins = { 0, 0, 0 }; // draws, p1 wins, p2 wins.
	while (!d1.IsEmpty()) {
		int result = PlayOneRound(d1, d2);
		if (result == 0) {
			cout << "Tie!";
		}
		else if (result == 1) {
			cout << "Player 1 wins!";
		}
		else {
			cout << "Player 2 wins!";
		}
		wins[result]++;

		cout << endl << endl;
		cout << "Play again? y/n: ";
		char again;
		cin >> again;

		if (again != 'y')
			break;
	}
}

int PlayOneRound(Deck &p1, Deck &p2) {
	cout << "Dealing cards... ";
	Card c1 = p1.DealOne();
	Card c2 = p2.DealOne();
	cout << c1 << " vs. " << c2 << "..." << endl;
	
	// Compare c1 and c2. 
	if (c1 < c2) {
		// This actually compiles as:
		// if (c1.operator<(c2))
		return 2; // player 2 wins
	}
	else if (c1 > c2) {
		return 1; // player 1 wins
	}
	return 0;
}
#endif