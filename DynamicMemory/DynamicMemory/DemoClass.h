#pragma once
#include <array>

// Instances of this type will be very large in memory (40KB). 
class DemoClass {
private:
	std::array<int, 10000> mData;

public:
	DemoClass() {
		mData[0] = 100;
	}

	inline int front() {
		return mData.front();
	}
};