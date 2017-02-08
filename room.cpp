#include "room.h"

Room::Room() : type("Empty Room"), num(-1), descrip("blank"), discovered(false),
	situation(NULL), pick(0), up(NULL), right(NULL), down(NULL), left(NULL)
{

}

// what is the type of derived event needs to be created
// might make this easier if this created the situation based on selection
Room::Room(string roomType, int roomNum, string roomDescrip, int what) : type(roomType),
	num(roomNum), descrip(roomDescrip), discovered(false),
	up(NULL), right(NULL), down(NULL), left(NULL)
{
	pick = what;
	choose(what);
}

// copy constructor
Room::Room(const Room &other)
{
	copy();
}

Room::~Room()
{
	clear();
}

// allows Game to make copy constructor
Room & Room::operator=(const Room &other)
{
	// will not be copying Room address, that's Game's Business
	if(this != &other)
	{
		clear();
		copy(other);
	}

	return *this;
}

void Room::clear()
{
	delete situation;
	situation = NULL;
}

void Room::copy(const Room &other)
{
	type = other.type;
	num = other.num;
	descrip = other.descript;
	discovered = other.discovered;
	pick = other.pick;
	// need something to allow this, assignment operator overload
	// pure virtual or maybe a copy constructor, maybe all three
//	*situation = *(other.situation);	// this doesn't work
	choose(other.pick());

	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;
}

// This is the choose for Cave Explorer, I will need to make
// a separate choose function for the other games
void Room::chooseCE(int what)
{
	// just setting up what the function should do
	// there could be more
	if(what == )
		situation = new ;
	else if(what == )
		situation = new ;
	else if(what == )
		situation = new ;
	else
		situation = new ;
}












