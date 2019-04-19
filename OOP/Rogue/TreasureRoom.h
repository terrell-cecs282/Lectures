#pragma once
#include "DungeonRoom.h"

class TreasureRoom : public DungeonRoom {
private:
	int mTreasureType;
	static const int NUMBER_OF_TREASURE_TYPES = 3;

public:
	TreasureRoom();

	std::string GetRoomName() const override;
	std::string GetDescription() const override;
	std::vector<std::string> GetActions() const override;
	bool DoAction(int number) override;
};

