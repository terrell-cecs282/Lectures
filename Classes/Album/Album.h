#pragma once
#include <string>
#include <iostream>
// Classes are split into two files: a declaration (in a .h file),
// and a definition. 

class Album {
// Access modifiers apply to all members that follow, not individually.
private:
	// Never, ever, ever use a namespace in a .h file, even if it means your code
	// becomes more verbose here.
	std::string mTitle;
	std::string mArtist;
	int mReleaseYear;
	int mSales;

public:
	// Constructor.
	Album(const std::string &title, const std::string &artist,
		int releaseYear, int sales);

	// Accessors.
	const std::string& GetTitle();
	const std::string& GetArtist();
	int GetReleaseYear();
	int GetSales();

	// Mutators.
	void AddSales(int increaseAmount);
	void SetSales(int salesAmount);

	// Utilities.
	enum class RiaaCertification {
		NONE,
		GOLD,
		PLATINUM,
		MULTI_PLATINUM,
		DIAMOND
	};

	RiaaCertification GetCertification();




	// Operators.
	// A "cast" operator: invoked when an Album object is explicitly cast
	// to another type (in this case, std::string).
	operator std::string();
};