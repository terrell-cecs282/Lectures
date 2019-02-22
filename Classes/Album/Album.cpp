#include "Album.h"
#include <sstream>
using namespace std;
// A .cpp file contains the definitions / bodies of a class's methods.
// Because we are not inside the class declaration, C++ doesn't know
// what "GetTitle" is supposed to belong to the Album class unless we 
// indicate that with the "scope resolution operator", :: 

// Read this as: the Album constructor from the Album class.
Album::Album(const string& title, const string& artist,
	int releaseYear, int sales)
	// We don't use = to assign instance variables in C++; we use 
	// an "initializer list".
	: mTitle(title), mArtist(artist), mReleaseYear(releaseYear),
	mSales(sales) {
}

// Read this as: the GetTitle() method of the Album class, returning a 
// const string reference.
const string& Album::GetTitle() {
	return mTitle;
}

const string& Album::GetArtist() {
	return mArtist;
}

int Album::GetReleaseYear() {
	return mReleaseYear;
}

int Album::GetSales() {
	return mSales;
}

void Album::AddSales(int increaseAmount) {
	if (increaseAmount > 0) {
		mSales += increaseAmount;
	}
}

void Album::SetSales(int salesAmount) {
	if (salesAmount > 0) {
		mSales = salesAmount;
	}
}
// Because the RiaaCertification enum is declared inside Album, it must be scoped
// as Album::RiaaCertification.
Album::RiaaCertification Album::GetCertification() {
	if (mSales >= 10000000) {
		// We use :: to select an enum case, unlike Java where we use a period.
		return RiaaCertification::DIAMOND;
	}
	if (mSales >= 2000000) {
		return RiaaCertification::MULTI_PLATINUM;
	}
	if (mSales >= 1000000) {
		return RiaaCertification::PLATINUM;
	}
	if (mSales >= 500000) {
		return RiaaCertification::GOLD;
	}
	return RiaaCertification::NONE;
}

Album::operator std::string() {
	string certStr = "";
	//
	RiaaCertification cert = GetCertification();
	if (cert == RiaaCertification::DIAMOND) {
		certStr = "Diamond";
	}
	else if (cert == RiaaCertification::MULTI_PLATINUM) {
		certStr = "Multi-Platinum";
	}
	else if (cert == RiaaCertification::PLATINUM) {
		certStr = "Platinum";
	}
	else if (cert == RiaaCertification::GOLD) {
		certStr = "Gold";
	}

	ostringstream os;
	os << mArtist << " - " << mTitle << " (" << mReleaseYear
		<< "); " << mSales << " sales";
	if (cert != RiaaCertification::NONE) {
		os << " [CERTIFIED " << certStr << "]";
	}

	// Return the compiled string.
	return os.str();
}
