
#pragma once
#include <iostream>
class Direction3 {
private:
	double mX, mY, mZ;

public:
	Direction3();
	Direction3(double x, double y, double z);

	inline double GetX() const { return mX; }
	inline double GetY() const { return mY; }
	inline double GetZ() const { return mZ; }

	inline void SetX(double x) { mX = x; }
	inline void SetY(double y) { mY = y; }
	inline void SetZ(double z) { mZ = z; }

	// Simple arithmetic operators.
	Direction3 operator+(const Direction3 &rhs) const;
	Direction3 operator-(const Direction3 &rhs) const;
	Direction3 operator-() const;



	// Compound arithmetic operators. Why the difference in return value?
	Direction3& operator+=(const Direction3 &rhs);
	Direction3& operator-=(const Direction3 &rhs);
};

std::ostream& operator<<(std::ostream &lhs, const Direction3 &rhs);