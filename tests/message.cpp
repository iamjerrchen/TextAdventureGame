#include <iostream>

bool checkMessage()
{
	// explain to the user the possible inputs
	std::cout << "Pick one of the following choices...\n";
	std::cout << "\tEnter 1 for Storyline One.\n";
	std::cout << "\tEnter 2 for Storyline Two.\n";
	std::cout << "\tEnter 3 for Storyline Three.\n";
	std::cout << "\tEnter 4 for Storyline Four.\n";

	int input;

	// keep getting the input till valid
	while(1)	// the condition to terminate will occur inside
	{
		std::cout << "\tEnter 5 to Quit Game.\n";
		std::cout << std::endl;
		// do I need to flush the stream?
		std::cin >> input;
		if(input < 1 || input > 5)
		{
			std::cout << "\nInvalid input... Try again\n\n";
			continue;
		}

		if(input == 1)
		{
			return true;
		}
		else if(input == 2)
		{
			return true;
		}
		else if(input == 3)
		{
			return true;
		}
		else if(input == 4)
		{
			return true;
		}
		else
			return false;
	}
}


int main()
{
	std::cout << std::string(50, '\n');
	std::cout << "Press enter when you are ready to play...\n";
	std::cin.get();

	if(checkMessage())
		std::cout << "You chose correctly, but...\nI don't have a game\n";
	else
		std::cout << "Sorry you didn't want to play\n";

	return 0;
}




