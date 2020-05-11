#include "TemplateClass.h"
#include "InheritorClass.h"

void TestIndex(TemplateClass<int>&, int);
void TestSort(TemplateClass<int>&, int);
void TestMin(TemplateClass<int>&, int);

void main()
{
	const int size = 5;
	int numbers[size] = { 2, 1, 0, -1, -2 };
	int** array = new int* [size];
	for (size_t i = 0; i < size; i++)
		array[i] = &numbers[i];
	TemplateClass<int> object(array);
	TestIndex(object, size);
	TestSort(object, size);
	TestMin(object, size);
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << "There is no memory leak" << endl;
}

void TestIndex(TemplateClass<int>& obj, int size)
{
	if (obj.index(0, size) == 2)
		cout << "Test index - successful" << endl << endl;
	else
		cout << "Test index - unsuccessful" << endl << endl;
}

void TestSort(TemplateClass<int>& obj, int size)
{
	if (*obj.sort(1, size) == -1)
		cout << "Test sort - successful" << endl << endl;
	else
		cout << "Test sort - unsuccessful" << endl << endl;
}

void TestMin(TemplateClass<int>& obj, int size)
{
	if (obj.min(size) == -2)
		cout << "Test min - successful" << endl << endl;
	else
		cout << "Test min - unsuccessful" << endl << endl;
}