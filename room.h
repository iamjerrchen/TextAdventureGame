/* Jerry Chen : jerrychen31@gmail.com
 *	This file will contain the declaration if the room struct
 *		The specific room will contain an event and it will be picked
 *		by the user or based on pass events.
 *
 *
 */

#ifndef ROOM_H
#define ROOM_H

// including STL
#include <string> // holds room, text dialogue

//including my files
#include "events.h"

// this class shouldn't be dealing with dynamic memory.
// instead this class should act like a node
// might need to templatize this for different events
struct Room{	// I picked structed because I want everything public
	// this will be a private struct in game, so no worries
	std::string type;	// the room's name
	int num;		// room number
	std::string descrip;	// what's in the room/purpose
	bool discovered;	// true after visit
	bool finalState;	// whether or not it's the end

	Events * situation;
	uint8_t pick;	// 0 is empty, main starts at 1

	// directions clockwise starting at up
	Room *up;	// if NULL, means no room
	Room *right;
	Room *down;
	Room *left;

	Room();
	// might make this easier if this created the situation based on selection
	Room(std::string roomType, int roomNum, std::string roomDescrip, int what);
	// copy constructor
	Room(const Room &other);
	~Room();

	// allows Game to make copy constructor
	Room & operator=(const Room &other);

	void clear();
	void copy(const Room &other);
	void chooseCE(int what);

};

#endif