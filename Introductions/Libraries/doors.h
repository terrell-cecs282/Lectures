// Whether your editor adds the next line or not, don't worry -- we don't
// need it for now.
#pragma once


// A "Header" file contains DECLARATIONS of functions only, never
// a DEFINITION.

// Randomly choose a door for the prize.
int getPrizeDoor();

// Asks the user to choose a door.
int getUserDoor();

// Determines a door to reveal to the player.
int getRevealedDoor(int prizeDoor, int chosenDoor);

// No variable names??
int switchDoor(int, int);



// Randomly chooses a prize number from 1 to 5.
int getPrizeNumber();