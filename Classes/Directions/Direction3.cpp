#include "Direction3.h"


Direction3::Direction3() : mX(0), mY(0), mZ(0) {
}

Direction3::Direction3(double x, double y, double z)
	: mX(x), mY(y), mZ(z) {
}

Direction3 Direction3::operator+(const Direction3 &rhs) const {
	return Direction3{ mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ };
}

Direction3 Direction3::operator-(const Direction3 &rhs) const {
	return Direction3{ mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ };
}

Direction3 Direction3::operator-() const {
	return Direction3{ -mX, -mY, -mZ };
}

Direction3& Direction3::operator+=(const Direction3 &rhs) {
	mX += rhs.mX;
	mY += rhs.mY;
	mZ += rhs.mZ;
	return *this;
}

Direction3& Direction3::operator-=(const Direction3 &rhs) {
	return (*this = (*this - rhs)); // ... wat?
}

std::ostream & operator<<(std::ostream & lhs, const Direction3 & rhs) {
	lhs << "<" << rhs.GetX() << ", " << rhs.GetY() << ", " << rhs.GetZ() << ">";
	return lhs;
}
