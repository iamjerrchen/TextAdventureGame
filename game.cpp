// I don't need this file in the current moment
//		because I don't need to define any methods

#include "game.h"

Game::Game()
{
	create();
}

// copy constructor
Game::Game(const Game &other)
{
	if(other.getMainRoom())
		copy(other);
	else
		mainRoom = NULL;
}

// assignment operator
Game & Game::operator=(const Game &other)
{
	if(this != &other)
	{
		if(mainRoom)	// sanity check if mainRoom even exists
			clear(mainRoom);

		if(other.getMainRoom())
			copy(other);
		else
			mainRoom = NULL;
	}

	return *this;
}

// Some precautions I need to make is setting pointers to NULL
// after a delete
// I also need to make sure I pass stuff by reference and make other const
// then I need to do sanity checks for recursive functions
// and check for NULLs
Game::~Game()
{
	// clear only removes room data
	// other dynamic memory needs to be separately remover
	if(mainRoom)	// mainRoom room exists
		clear(mainRoom);
}

/* Big Three Helper - Clears Memory
 *		Recursively goes to every room starting at mainRoom
 */
void Game::clear(Room *&curr)
{
	if(curr->up)	// up room exists
		clear(curr->up);

	if(curr->right)	// right room exists
		clear(curr->right);

	if(curr->down)	// down room exists
		clear(curr->down);

	if(curr->left)	// left room exists
		clear(curr->left);

	// no more traversals, delete current room
	delete curr;
	curr = NULL;	// good practice
}

/* Big Three Helper - Copies Memory
 *		Recursively goes to every room and copies data
 */
void Game::copy(const Game &other)
{
	// made a separate copy because this one isn't recursive
	copy(other.getMainRoom(), mainRoom);
}

/*	Copy Helper - Recursively copies the rooms
 *		Here's a problem, how do I make the pointers
 *			point to the previous rooms?
 *		Should I just do a directed game, can't go back?
 *		Should I change the structure to a graph?
 */
void Game::copy(const Room *othercurr, Room *&curr)
{
	
	if(othercurr->up)
	{
		curr->up = new Room (*(othercurr->up));
		copy(othercurr->up, curr->up);
	}

	if(othercurr->right)
	{
		curr->right = new Room(*(othercurr->right));
		copy(othercurr->right, curr->right);
	}

	if(othercurr->down)
	{
		curr->down = new Room(*(othercurr->down));
		copy(othercurr->down, curr->down);
	}

	if(othercurr->left)
	{
		curr->left = new Room(*(othercurr->left));
		copy(othercurr->left, curr->left);
	}
}

/* Getting function for the Main Room pointer
 *
 */
Room * Game::getMainRoom() const
{
	return mainRoom;
}

/* Creates a new game, reassure, will only call if game doesn't exists
 *
 *
 */












