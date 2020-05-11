#include "List.h"

void TestReadFile(List&, int, string);
void TestTask(List&, int, string);
void TestWriteInFile(List&, string, int);

void main()
{
	string filename;
	cout << "Enter name of the file for test: ";
	cin >> filename;
	if (filename == "Text1.txt")
	{
		List obj;
		TestReadFile(obj, 4, filename);
		TestTask(obj, 6, "Result.txt");
		TestWriteInFile(obj, "Result.txt", 7);
	}
	else if (filename == "Text2.txt")
	{
		List obj;
		TestReadFile(obj, 2, filename);
		TestTask(obj, 4, "Result.txt");
		TestWriteInFile(obj, "Result.txt", 5);
	}
	else if (filename == "Text3.txt")
	{
		List obj;
		TestReadFile(obj, 2, filename);
		TestTask(obj, 0, "Result.txt");
		TestWriteInFile(obj, "Result.txt", 4);
	}
	else
		cout << endl << "Wrong file name" << endl;
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
}

void TestReadFile(List& test, int size, string data)
{
	test.readFromFile(data);
	if (size == test.getArraySize())
		cout << endl << endl << "Test readFromFile - successful" << endl << endl;
	else
		cout << endl << endl << "Test readFromFile - unsuccessful" << endl << endl;
}

void TestTask(List& test, int size, string res)
{
	int* resArr;
	int count = 0;
	resArr = test.task();
	for (int i = 0; i < size; i++)
		if (resArr[i] > 0)
			count++;
	if (count == size)
		cout << endl << endl << "Test task - successful" << endl << endl;
	else
		cout << endl << endl << "Test task - unsuccessful" << endl << endl;
	test.writeInFile(res, resArr);
}

void TestWriteInFile(List& test, string filename, int num)
{
	if (test.stringsInFile(filename) == num)
		cout << endl << endl << "Test writeInFile - successful" << endl << endl;
	else
		cout << endl << endl << "Test writeInFile - unsuccessful" << endl << endl;
}