#include "Point.h"

Point3::Point3() : mX(0), mY(0), mZ(0) {

}

Point3::Point3(double x, double y, double z)
	: mX(x), mY(y), mZ(z) {

}

Point3 Point3::operator+(const Direction3& rhs) const {
	return Point3{mX + rhs.GetX(), mY + rhs.GetY(), mZ + rhs.GetZ()};
}
