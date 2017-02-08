/*	Jerry Chen : jerrychen31@gmail.com
 *	This is the main file for the AdventureGame pack.
 *		The user will be prompted to select one of the 4 games
 *		A Game pointer will be initialized and will create the
 *		proper game that the user wants to play.
 */

// including STL
#include <iostream>	// standard io and cin.get()
#include <stdlib.h>

using std::cout;	// save some key strokes for a text game
using std::endl;
using std::cin;

// including my files
#include "game.h"	// game includes everything else


// I'm gonna encapsulate these functions
// any message I want to send to the user
void creatorMessage()
{
	cout << std::string(50, '\n');
	// say who created, and greetings and such
	cout << "Welcome to my Text Adventure game.\n";
	cout << "My name is Jerry Chen. I hope you enjoy what I have created.\n";
	cout << "If there are any issues with the game (i.e. Typos, Logic Error, Bug...)\n";
	cout << "Email me: @jerrychen31@gmail.com\n";

	cout << "\nAs a note to myself: Started - 12/21/16\n";

	cout << "\nPress enter when you are ready to play...\n";
	cin.get();
}

// decided to make this function bool, that way I can return
// false when the player decides to quit game
bool pickStory(Game *&create)
{
	// explain to the user the possible inputs
	cout << "Pick one of the following choices...\n";
	cout << "\tEnter 1 for CaveExplorer.\n";
	cout << "\tEnter 2 for CaveExplorer.\n";
	cout << "\tEnter 3 for CaveExplorer.\n";
	cout << "\tEnter 4 for CaveExplorer.\n";

	char input;

	// keep getting the input till valid
	while(1)	// the condition to terminate will occur inside
	{
		cout << "\tEnter 5 to quit the game.\n";
		cout << endl;
		// do I need to flush the stream?
		cin >> input;

		// Now I know that it has to be a valid input
		if(input == '1')
		{
			create = new CaveExplorer; // Game One
			return true;
		}
		else if(input == '2')
		{
			create = new CaveExplorer; // Game Two
			return true;
		}
		else if(input == '3')
		{
			create = new CaveExplorer; // Game Three
			return true;
		}
		else if(input == '4')
		{
			create = new CaveExplorer; // Game Four
			return true;
		}
		else if(input == '5')
			return false;	// they quit

		// didn't exit the function
		cout << "\nInvalid input... Try again.\n\n";
	}
}

int main()
{	// Introduction
	creatorMessage();

	Game *join = NULL;
	if(pickStory(join))
		// the player picked a story and wants to play
		join->play();
	else
		cout << "How unfortunate... You don't want to play.\n"

	return 0;
}