/* Jerry Chen : jerrychen31@gmail.com
 *	Cave Explorer is one of the games
 * 	
 *
 *
 *
 */

#ifndef CAVEEXPLORER_H
#define CAVEEXPLORER_H

// including STL
#include <time.h>	// manage the time, and how long to wait
#include <string>

// including my files
#include "game.h"	// need to include base class

class CaveExplorer : public Game {

private:

	// Big Three Helpers
	void clear();
	void copy(const CaveExplorer &other);

	// clear and copy, recursive functions
	void clearHelp(Room *&curr);
	void copyHelp(const Room *othercurr, Room *&curr);

public:

	CaveExplorer();

	// Big Three
	// I did a test, Game *a = new CaveExplorer is still a Game type
	//		with a CaveExplorer object
	CaveExplorer(const CaveExplorer &other);
	CaveExplorer & operator=(const CaveExplorer &other);
	~CaveExplorer();

	void play();

private:

	// Functions that shouldn't be accessible to the client
	// Althought these aren't pure virtual, each game should still have them
	void buildMap();
	void create();
	void restart();
	void backstory();	// will print out the backstory of the game

	void currInventory();	// prints what's available

	/* If you add more members, fix clear if it's dynamic
	 *		Also add to copy, you gotta copy everything over
	 */

	// member variables not affected by player
	Room * entrance;	// only possible because it's protected

	// member variables affected by the player
	std::string player;

	// items that affect the flow of the game
	bool guide;	// person from entrance, his name is Lupis
	bool gem;	// item found in game

public:
	// put it down here because it needs to be after members
	// getters and setters
	Room * getEntrance() const {return entrance;}
	std::string getPlayer() const {return player;}
	bool getGuide() const {return guide;}
	bool getGem() const {return gem;}

};

#endif
