#include "caveExplorer.h"

CaveExplorer::CaveExplorer()
{
	create();	// is this what I want to do?
}

/* Copy constructor - Don't care much for it at the moment
 *		The reason is because I only need the destructor
 *		and I don't need to copy a different came.
 *		The games should be independent of one another
 *		even the states of the game doesn't matter.
 *		There's no saving in this game at current time
 */
CaveExplorer::CaveExplorer(const CaveExplorer &other)
{
	copy(other);
}

/*	Assignment operator - Similar situation, don't need
 *		Refer to notes of copy constructor
 */
CaveExplorer & CaveExplorer::operator=(const CaveExplorer &other)
{
	if(this != &other)
	{
		clear();
		copy(other);
	}

	return *this;
}

/* Destructor - Simply calls clear
 */
CaveExplorer::~CaveExplorer()
{
	clear();
}

/* clear - Big Three helper, more specifically destructor helper
 *		If the entrance exists, remove all the rooms
 *		Then if there are anymore dynamic memory, delete
 */
void CaveExplorer::clear()
{
	if(entrance)
		clearHelp(entrance);	// delete diagram

	// If I decide to make more dynamic memory, delete here
}

/* clearHelp - clear's helper, the recursive portion of clear
 *		Removes all the rooms recursively
 *		There may be a problem, if there's a cycle
 *		I don't think a null check will work to prevent deleting a second time
 *		I can do a test, int *a, *b, *c
 *		a = c, b = c. Delete one of them and check the value or delete the other
 */
void CaveExplorer::clearHelp(Room *&curr)
{
	if(curr->up)	// up room exists
		clearHelp(curr->up);

	if(curr->right)	// right room exists
		clearHelp(curr->right);

	if(curr->down)	// down room exists
		clearHelp(curr->down);

	if(curr->left)	// left room exists
		clearHelp(curr->left);

	// no more traversals, delete current room
	delete curr;
	curr = NULL;	// good practice
}

/* copy - Big Three helper, but since we don't care much for
 *		the copy constructor and assignment operator, we are
 *		missing a couple possible tests.
 *		After I create the first pack, I'll fix this most likely
 */
void CaveExplorer::copy(const CaveExplorer &other)
{
	if(other.getEntrance())
	{	// create the entrance
		entrance = new Room(*(other.getEntrance()))
		copyHelp(other.getEntrance(), entrance)
	}
	else
		entrance = NULL;

	// rooms already copied, now copy everything else
	player = other.getPlayer();
	guide = other.getGuide();
	gem = other.getGem();
}

/* Recursive Copy Helper - Copies the rooms
 *		This should call Room's copy constructor
 *		builds as it explores othercurr
 *		copy() makes sure that the entrance exists first
 *		before it calls the helper
 */
void CaveExplorer::copyHelp(const Room *othercurr, Room *&curr)
{
	// I have a feeling this function wont work the way I want it
	// This method only works for trees
	// So this doesn't allow cycles
	// It'll create the same thing, but it will have duplicates of the same room
	// that means some rooms may be in a different branch with the same
	// characteristics
	if(othercurr->up)
	{	// copy the up room, use Room's copy constructor
		curr->up = new Room (*(othercurr->up));
		copyHelp(othercurr->up, curr->up);
	}

	if(othercurr->right)
	{
		curr->right = new Room(*(othercurr->right));
		copyHelp(othercurr->right, curr->right);
	}

	if(othercurr->down)
	{
		curr->down = new Room(*(othercurr->down));
		copyHelp(othercurr->down, curr->down);
	}

	if(othercurr->left)
	{
		curr->left = new Room(*(othercurr->left));
		copyHelp(othercurr->left, curr->left);
	}
}

// thought of something
// if I want to restart, I could return false
// and modify main so that it recalls play instead of calling restart()
void CaveExplorer::play()
{
	backstory();	// output the introduction

	Room *curr = entrance;	// simple traversal

	while(1)
	{
		// play the situation, situation should return
		// decision from the player

		if(curr->finalState)	// at the end of the game
		{
			cout << "\nYou have the following options:\n";
			cout << "\tEnter r if you wish to restart.\n"
			cout << "\tEnter anything else if you wish to quit.\n";
			char finalDecision;
			cin >> finalDecision;

			if(finalDecision == 'r')
			{
				curr = entrance;	// move to beginning
				restart();	// resets the members
				backstory();
				continue;
			}

			return;	// they want to quit
		}

		// move to next room
	}
}

void CaveExplorer::buildMap()
{

}

void CaveExplorer::create()
{
	entrance = NULL;
	buildMap();	// set up the room
	restart(); // initializes to state
}

// maybe I can do pos locally
void CaveExplorer::restart()
{
	// reset everything to initial state
	player = "";
	guide = false;
	diamond = false;
	// this will be simple if the states of the events don't change
}

/* This function simply outputs the backstory of what's happening.
 *		Tells you who you are as a player, what you're doing.
 *		Nothing more than text.
 *		One big thing I want to note is setting up the \t and \n
 *			to make the text visually appealing.
 *	This function's text should be the next thing that shows
 *		After the main file's text.
 */
void CaveExplorer::backstory()
{

}

void CaveExplorer::currInventory()
{	
	cout << "\n" << player << ", you currently have the following:\n"
	// simple, check bools if exist say the player has it
	if(guide)
		cout << "\tLupis is with you.\n";
	if(gem)
		cout << "\tYou have the gem.\n";

}








