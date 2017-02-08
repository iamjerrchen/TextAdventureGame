#include <time.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// testing whether I can use the time to create diversions
// in the path of events
// for example if 5 seconds pass before decision then something else
// happens
int main()
{
	time_t secBefore;	// get current time
	time_t secAfter;

	cout << "Wait at least 10 seconds: \n";
	cout << "Press Enter to continue...";
	secBefore = time(0);

	cin.get();

	secAfter = time(0);

	if(secAfter-secBefore > 10)
		cout << "You Pass!" << endl;
	else
		cout << "You Failed!" << endl;

	cout << secAfter-secBefore << endl;

	return 0;
}