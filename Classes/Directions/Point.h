#pragma once
#include "Direction3.h"	

// Operators can be written with any combination of operand types; they don't have
// to match (all of the Direction3 operators had matching operand types).
class Point3 {
private:
	int mX, mY, mZ;
public:
	Point3();
	Point3(double x, double y, double z);

	inline double GetX() const { return mX; }
	inline double GetY() const { return mY; }
	inline double GetZ() const { return mZ; }

	inline void SetX(double x) { mX = x; }
	inline void SetY(double y) { mY = y; }
	inline void SetZ(double z) { mZ = z; }

	// Operators can take operands of any type. 
	Point3 operator+(const Direction3& rhs) const;
};
