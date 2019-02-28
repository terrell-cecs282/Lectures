#include "Deck.h"

using namespace std;

// This syntax initializes the static member mRandomEngine.
mt19937 Deck::mRandomEngine = mt19937{ (random_device{})() };

Deck::Deck() {
	for (int suit = 0; suit <= 3; suit++) {
		for (int kind = 2; kind <= 14; kind++) {
			Card c = Card{ static_cast<Card::CardKind>(kind),
				static_cast<Card::CardSuit>(suit) };
			mCards.push_back(c);

			// Instead of all that, we could have instead done:
			// mCards.emplace_back(static_cast<Card::CardKind>(kind),
			//	static_cast<Card::CardSuit>(suit));
		}
	}
}

void Deck::Shuffle() {
	// Perform a Fisher-Yates Shuffle. 

	for (int i = mCards.size() - 1; i > 0; i--) {
		uniform_int_distribution<int> range{ 0, i };
		int j = range(mRandomEngine);
		std::swap(mCards[i], mCards[j]);
	}
}

Card Deck::DealOne() {
	Card temp = mCards.back();
	mCards.pop_back();
	return temp;
}

std::ostream & operator<<(std::ostream & lhs, const Deck & rhs) {
	lhs << '[';
	bool first = true;
	for (Card c : rhs.mCards) {
		if (!first) {
			lhs << "; ";
		}
		lhs << c;
		first = false;
	}
	lhs << ']';
	return lhs;
}
