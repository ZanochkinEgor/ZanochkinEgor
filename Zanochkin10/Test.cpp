#include "TemplateClass.h"

void TestIndex(TemplateClass&, int*, int);
void TestSort(TemplateClass&, int*, int);
void TestMin(TemplateClass&, int*, int);

void main()
{
	TemplateClass object;
	const int size = 5;
	int array[size] = { 2, 1, 0, -1, -2 };
	TestIndex(object, array, size);
	TestSort(object, array, size);
	TestMin(object, array, size);
	if (_CrtDumpMemoryLeaks())
	{
		cout << endl << "WARNING! Memory leak" << endl;
	}
	else
		cout << "There is no memory leak" << endl;
}

void TestIndex(TemplateClass& obj, int* arr, int size)
{
	if (obj.index(arr, 0, size) == 2)
		cout << "Test index - successful" << endl << endl;
	else
		cout << "Test index - unsuccessful" << endl << endl;
}

void TestSort(TemplateClass& obj, int* arr, int size)
{
	obj.sort(arr, 1, size);
	if (arr[0] == -2 && arr[size - 1] == 2)
		cout << "Test sort - successful" << endl << endl;
	else
		cout << "Test sort - unsuccessful" << endl << endl;
}

void TestMin(TemplateClass& obj, int* arr, int size)
{
	if (obj.min(arr, size) == -2)
		cout << "Test min - successful" << endl << endl;
	else
		cout << "Test min - unsuccessful" << endl << endl;
}