#pragma once
#include "Card.h"
#include <vector>
#include <random>
// Represents a deck of cards that can be dealt from.
class Deck {
private:
	// We'll use a vector to store the cards in the deck, and "deal" from the back end.
	std::vector<Card> mCards;

	// Static members belong to the entire class, not to a specific instance. They 
	// are declared in the .h file but must be initialized in the .cpp file.
	static std::mt19937 mRandomEngine;

public:
	// Constructs a deck with a default ordering of cards.
	Deck();
	// Shuffles a deck.
	void Shuffle();

	// True if there are no cards left in the deck.
	inline bool IsEmpty() const { return mCards.empty(); }

	// Returns a copy of the "top" card of the deck, removing that card from the deck.
	Card DealOne();

	// We want to write operator<< to print a deck for debugging/testing... but
	// if the operator is not a member of this class, then it can't access the vector
	// of cards to print them. We could add an accessor like this:
	// const std::vector<Card>& GetCards() const { return mCards; }
	// but that exposes the order of the cards in the deck and maybe we don't want that.

	// Instead, we'll still use a global << operator... but we'll give it "friend access".
	// Friend classes and functions have access to the private declarations of a class.
	friend std::ostream& operator<<(std::ostream& lhs, const Deck &rhs);
	// We take the Deck by reference this time, because duplicating a Deck would duplicate
	// its vector and that is expensive.
};