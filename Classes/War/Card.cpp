#include "Card.h"
#include <array>
#include <string>

using namespace std;

Card::Card(CardKind kind, CardSuit suit) : mKind(kind), mSuit(suit) {
}

Card::operator std::string() const {
	std::array<string, 4> kinds = { "Jack", "Queen", "King", "Ace" };
	std::array<string, 4> suits = { "Spades", "Clubs", "Diamonds", "Hearts" };
	string kindStr;
	if (mKind < CardKind::JACK) {
		// The C++ canonical means for casting is static_cast, even though
		// C/Java-style casts still work.

		// A static cast is checked at compile time (statically) to make sure
		// there is a valid conversion from source to target.
		kindStr = std::to_string(static_cast<int>(mKind));
	}
	else {
		kindStr = kinds[static_cast<int>(mKind) - static_cast<int>(CardKind::JACK)];
	}

	string suitStr = suits[static_cast<int>(mSuit)];
	return kindStr + " of " + suitStr;
}

bool Card::operator<(Card rhs) const {
	return static_cast<int>(mKind) < static_cast<int>(rhs.mKind);
}

bool Card::operator>(Card rhs) const {
	return static_cast<int>(mKind) > static_cast<int>(rhs.mKind);
}

std::ostream& operator<<(std::ostream& lhs, Card rhs) {
	// The next line only compiles because we have operator string.
	lhs << static_cast<string>(rhs);
	return lhs;
}
