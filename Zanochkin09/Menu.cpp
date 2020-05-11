#include "List.h"

void Menu() noexcept
{
	string filename;
	cout << "Enter your file name or \\exit to end work: ";
	filename = fileName();
	while (filename != "\\exit")
	{
		List obj;
		try
		{
			obj.readFromFile(filename);
			obj.print();
			int* resultArray = obj.task();
			if (resultArray[0] > 0)
			{
				cout << endl << endl << "Enter file name for output:" << endl;
				filename = fileName();
				obj.writeInFile(filename, resultArray);
			}
			else
				cout << "There is no positive elements in any array" << endl << endl;
			delete[] resultArray;
		}
		catch (const std::exception& ex)
		{
			cout << endl << ex.what() << endl << endl;
		}
		cout << "Enter your file name or \\exit to end work: ";
		filename = fileName();
	}
}