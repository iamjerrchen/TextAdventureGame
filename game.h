/* Jerry Chen : jerrychen31@gmail.com
 *	This class will be a an abstract class.
 *		play will be pure virtual, the derived will deal with creation
 *		This way, the derived classes will be able to be forced to
 *		define them so that they will be able to be independent
 *		Preferably, the main can use functins easier.
 *		Remember MP4 where ordering structure was a template type
 */

#ifndef GAME_H
#define GAME_H

// including STL
#include <stdlib.h>	// what is this used for in this class

// including my files

;
class Game{

protected:

	// this way derived classes can make the struct
	#include "room.h"	// include room as protected

public:

	// class functions
	// In the end, I might actually want to return something
	// such as a bool to know that it restarted
	virtual void play() = 0;

};

// I'm still trying to decide whether I need the #include here
#include "caveExplorer.h"	// Game one
// Game two
// Game three
// Game four

#endif






