// This file will contain all the tests for text visualization
// including STL
#include <iostream>	// standard io and cin.get()
#include <stdlib.h>

using std::cout;	// save some key strokes for a text game
using std::endl;
using std::cin;
using std::string;

// I'm gonna encapsulate these functions
// any message I want to send to the user
void creatorMessage()
{
	cout << string(50, '\n');
	// say who created, and greetings and such
	cout << "Welcome to my Text Adventure game.\n";
	cout << "My name is Jerry Chen. I hope you enjoy what I have created.\n";
	cout << "If there are any issues with the game (i.e. Typos, Logic Error, Bug...)\n";
	cout << "Email me: @jerrychen31@gmail.com\n";

	cout << "\nAs a note to myself: Started - 12/21/16\n";

	cout << "\nEnter when you are ready to play...\n";
	cin.get();
}

// decided to make this function bool, that way I can return
// false when the player decides to quit game
bool pickStory()
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
			return true;
		}
		else if(input == '2')
		{
			return true;
		}
		else if(input == '3')
		{
			return true;
		}
		else if(input == '4')
		{
			return true;
		}
		else if(input == '5')
			return false;	// they quit
		else
		{
			cout << "\nInvalid input... Try again.\n\n";
			continue;
		}
	}
}

int main()
{	// Introduction
	creatorMessage();

	if(pickStory())
	{
		cout << "Unfortunately I haven't installed any games XD\n";
	}
	else
		cout << "How unfortunate. You didn't want to play.\n";
	// otherwise they quit

	return 0;
}