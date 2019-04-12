#pragma once

#include <string>
#include <vector>
#include <random>

class DungeonRoom {
private:
	static std::mt19937 mRandom;
	static const int NUMBER_OF_ROOM_TYPES = 3;

protected:
	std::mt19937& GetRandomEngine() { return mRandom; }

public:
	virtual std::string GetRoomName() const;
	virtual std::string GetDescription() const;

	virtual std::unique_ptr<DungeonRoom> GetNextRoom() const;


	virtual std::vector<std::string> GetActions() const;
	virtual bool DoAction(int number);
};

#endif