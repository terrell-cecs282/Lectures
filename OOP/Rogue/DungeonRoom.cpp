#include "DungeonRoom.h"
#include "TrapRoom.h"
#include "MonsterRoom.h"
#include <string>
#include <random>
#include <memory> 
using namespace std;

default_random_engine DungeonRoom::mRandom{ random_device()() };

string DungeonRoom::GetDescription() const {
	return "The room is empty.";
}

string DungeonRoom::GetRoomName() const {
	return "an empty room";
}

unique_ptr<DungeonRoom> DungeonRoom::GetNextRoom() const {
	uniform_int_distribution<int> roomType(0, NUMBER_OF_ROOM_TYPES - 1);

	switch (roomType(mRandom)) {
	case 0:
		return make_unique<DungeonRoom>();
	case 1:
		return make_unique<MonsterRoom>();
	case 2:
		return make_unique<TrapRoom>();
	}
	return nullptr;
}

vector<string> DungeonRoom::GetActions() const {
	return vector<string> {"Go to the next room."};
}

bool DungeonRoom::DoAction(int number) {
	return true;
}