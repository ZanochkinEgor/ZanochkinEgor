#include "Task.h"

void main()
{
	Menu();
	if (_CrtDumpMemoryLeaks())
		cout << "WARNING! Memory leak" << endl;
	else
		cout << "There is no memory leak" << endl;
}