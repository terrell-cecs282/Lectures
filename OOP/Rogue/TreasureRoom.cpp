#include "TreasureRoom.h"
#include <random>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
TreasureRoom::TreasureRoom()
{
	uniform_int_distribution<int> fuckyou(0, NUMBER_OF_TREASURE_TYPES - 1);
	mTreasureType = fuckyou(GetRandomEngine());
}

std::string TreasureRoom::GetRoomName() const
{
	return std::string();
}

std::string TreasureRoom::GetDescription() const
{
	return std::string();
}

std::vector<std::string> TreasureRoom::
GetActions() const
{
	return std::vector<std::string>();
}

bool TreasureRoom::DoAction(int number)
{
	return false;
}
