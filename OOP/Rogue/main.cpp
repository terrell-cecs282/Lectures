#include "DungeonRoom.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main(int argc, char* argv[]) {
	cout << "Welcome to our Rogue-like game. Let's begin!" << endl;

	unique_ptr<DungeonRoom> currentRoom = std::make_unique<DungeonRoom>();

	while (true) {
		cout << endl << endl << "You enter " << currentRoom->GetRoomName() << endl;
		cout << currentRoom->GetDescription() << endl;
		vector<string> actions = currentRoom->GetActions();

		cout << "What do you want to do?" << endl;
		int counter = 1;
		for (string &a : actions) {
			cout << counter << ") " << a << endl;
			counter++;
		}

		int choice;
		cin >> choice;
		if (!currentRoom->DoAction(choice))
			return 0;

		unique_ptr<DungeonRoom> nextRoom = currentRoom->GetNextRoom();
		currentRoom = std::move(nextRoom);

	}
}