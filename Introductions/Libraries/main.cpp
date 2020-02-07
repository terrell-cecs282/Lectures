#include <iostream>
#include "doors.h"
using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		cout << "Let's make a deal!";

		int prize = getPrizeDoor();
		int chosen = getUserDoor();

		int reveal = getRevealedDoor(prize, chosen);
		cout << "Let's open door number " << reveal << "... "
			<< "It's a goat!" << endl;

		cout << "Would you like to switch doors? y/n" << endl;
		char choice;
		cin >> choice;

		if (choice) {
			chosen = switchDoor(chosen, reveal);
		}

		cout << "You've chosen door number " << chosen << "..." << endl;
		if (chosen == reveal) {
			cout << "You win!" << endl;
			int prizeNum = getPrizeNumber();
			// prizes etc.
		}
		else {
			cout << "You suck!" << endl;
		}

		cout << "Play again? y/n" << endl;
		cin >> choice;
		if (choice == 'n') {
			break;
		}
	}
}