#pragma once
#include "DungeonRoom.h"

class MonsterRoom : public DungeonRoom {
private:
	int mMonsterType;
	static const int NUMBER_OF_MONSTER_TYPES = 3;

public:
	MonsterRoom();

	std::string GetRoomName() const override;
	std::string GetDescription() const override;
	std::vector<std::string> GetActions() const override;
	bool DoAction(int number) override;
};

