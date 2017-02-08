#include <iostream>
// #include <string>
//#include <stdlib.h>	// system

using namespace std;

// Using system code is not portable,
// google search stackoverflow thread titled
// Pause console in C++ program
// it's not advised and if anything cin.get() is more portable

int main()
{
	// system("cls");
	cout << string(50, '\n');

	cout << "\tHi, there!\n\n";
	cout << "\nComputers are ";
	cout << "great!\n";

	cout << "Press enter to continue..." << endl;
	// system("pause");
	cin.get();
	// system("cls");	// don't use system code, ever
	cout << string(50, '\n');

	cout << "Good, you cleared my message." << endl;
	cout << "Bye, Bye!" << endl;

	return 0;
}