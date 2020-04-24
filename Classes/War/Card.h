#pragma once
#include <string>
#include <ostream>
class Card {
public:
	// Normally we put private variables first, but our variables will be of the
	// following types which must be declared first.
	enum class CardSuit {
		SPADES,
		CLUBS,
		DIAMONDS,
		HEARTS
	};

	enum class CardKind {
		TWO = 2, // each successive value will count up from here.
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE
	};

private:
	// A card is a suit and a kind.
	CardSuit mSuit;
	CardKind mKind;

public:
	// Constructs a card with a given kind and suit.
	Card(CardKind kind, CardSuit suit);

	// enums are implemented as small integers -- no need to return by reference.
	inline CardSuit GetSuit() const { return mSuit; }
	inline CardKind GetKind() const { return mKind; }

	inline void SetSuit(CardSuit suit) { mSuit = suit; }
	inline void SetKind(CardKind kind) { mKind = kind; }

	operator std::string() const;

	// In C++, an operator is just another function, whose name happens to be 
	// "operatorXX", where XX is the symbol we use in the operator.
	// Like all functions, it has a return value, parameters, can be const, etc.

	// Some operators can be members of a class like any other member method.
	// These operators implicitly take the "Left hand side" of the operator as the
	// "this" object, and the right hand side (if any) as an explicit parameter.
	bool operator<(Card rhs) const;
	bool operator>(Card rhs) const;
};

// Operators can only be a member of a class if the lhs operand is an instance of
// the class. since "cout << c" has a lhs of type ostream, the << operator cannot
// be a member of Card. We still declare it globally in this .h file so anyone who
// uses Card can cout it.

// This is the standard pattern for a << operator -- take the ostream by reference,
// return it by reference, and take the object to print as either a const reference
// or full value.
std::ostream& operator<<(std::ostream& lhs, Card rhs);