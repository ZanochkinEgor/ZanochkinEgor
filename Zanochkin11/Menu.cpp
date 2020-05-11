#include "Student.h"
#include "TemplateClass.h"
#include "InheritorClass.h"

void Menu() noexcept
{
	try
	{
		intArray();
	}
	catch (const std::exception& ex)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << ex.what() << endl << endl;
	}
	try
	{
		floatArray();
	}
	catch (const std::exception& ex)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << ex.what() << endl << endl;
	}
	try
	{
		classArray();
	}
	catch (const std::exception& ex)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << ex.what() << endl << endl;
	}
}

void intArray() noexcept (false)
{
	int sizeInt;
	int numberInt;
	int indexInt;
	int option;
	cout << "Enter size of INT array:" << endl;
	cin >> sizeInt;
	if (sizeInt <= 0 || !cin)
		throw exception("ERROR! You've enter wrong size");
	int* numInt = new int[sizeInt];
	int** arrayInt = new int*[sizeInt];
	cout << endl << "Enter " << sizeInt << " int numbers:" << endl;
	for (size_t i = 0; i < sizeInt; i++)
	{
		cin >> numInt[i];
		if (!cin)
		{
			delete[] arrayInt;
			delete[] numInt;
			throw exception("ERROR! Wrong data!");
		}
		arrayInt[i] = &numInt[i];
	}
	TemplateClass<int> obj(arrayInt);
	obj.print(sizeInt);
	cout << "Enter number to get it's index:" << endl;
	cin >> numberInt;
	if (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		indexInt = -1;
	}
	else
		indexInt = obj.index(numberInt, sizeInt);
	if (indexInt != -1)
		cout << endl << "Index: " << indexInt << endl << endl;
	else
		cout << endl << "There is no element with that index" << endl << endl;
	cout << "Choose sort:" << endl;
	cout << "1. Ascending sort" << endl;
	cout << "2. Descending sort" << endl;
	cin >> option;
	if (cin)
	{
		if (option == 1)
		{
			obj.sort(option, sizeInt);
			obj.print(sizeInt);
		}
		else if (option == 2)
		{
			obj.sort(option, sizeInt);
			obj.print(sizeInt);
		}
		else
			cout << endl << "Wrong symbol" << endl << endl;
	}
	else
	{
		cout << endl << "You've entered wrong symbol" << endl << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cout << "Minimal element is: " << obj.min(sizeInt) << endl << endl;
	delete[] arrayInt;
	delete[] numInt;
}

void floatArray() noexcept (false)
{
	int sizeFloat;
	float numberFloat;
	int indexFloat;
	int option;
	cout << "Enter size of FLOAT array:" << endl;
	cin >> sizeFloat;
	if (sizeFloat <= 0 || !cin)
		throw exception("ERROR! You've enter wrong size");
	float* numFloat = new float[sizeFloat];
	float** arrayFloat = new float*[sizeFloat];
	cout << endl << "Enter " << sizeFloat << " float numbers:" << endl;
	for (size_t i = 0; i < sizeFloat; i++)
	{
		cin >> numFloat[i];
		if (!cin)
		{
			delete[] arrayFloat;
			delete[] numFloat;
			throw exception("ERROR! Wrong data!");
		}
		arrayFloat[i] = &numFloat[i];
	}
	TemplateClass<float> obj(arrayFloat);
	obj.print(sizeFloat);
	cout << "Enter number to get it's index:" << endl;
	cin >> numberFloat;
	if (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		indexFloat = -1;
	}
	else
		indexFloat = obj.index(numberFloat, sizeFloat);
	if (indexFloat != -1)
		cout << endl << "Index: " << indexFloat << endl << endl;
	else
		cout << endl << "There is no such element with that index" << endl << endl;
	cout << "Choose sort:" << endl;
	cout << "1. Ascending sort" << endl;
	cout << "2. Descending sort" << endl;
	cin >> option;
	if (cin)
	{
		if (option == 1)
		{
			obj.sort(option, sizeFloat);
			obj.print(sizeFloat);
		}
		else if (option == 2)
		{
			obj.sort(option, sizeFloat);
			obj.print(sizeFloat);
		}
		else
			cout << endl << "Wrong symbol" << endl << endl;
	}
	else
	{
		cout << endl << "You've entered wrong symbol" << endl << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Minimal element is: " << obj.min(sizeFloat) << endl << endl;
	delete[] arrayFloat;
	delete[] numFloat;
}

void classArray() noexcept (false)
{
	Student oneObj;
	int sizeClass;
	int indexClass;
	int option;
	cout << "Enter size of CLASS array:" << endl;
	cin >> sizeClass;
	if (sizeClass <= 0 || !cin)
		throw exception("ERROR! You've enter wrong size");
	Student** arrayClass = createArray(sizeClass);
	TemplateClass<Student> obj(arrayClass);
	obj.print(sizeClass);
	cout << "Enter age to get it's index:" << endl;
	cin >> oneObj;
	if (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		indexClass = -1;
	}
	else
		indexClass = obj.index(oneObj, sizeClass);
	if (indexClass != -1)
		cout << endl << "Index: " << indexClass << endl << endl;
	else
		cout << endl << "There is no such element with that index" << endl << endl;
	cout << "Choose sort:" << endl;
	cout << "1. Ascending sort" << endl;
	cout << "2. Descending sort" << endl;
	cin >> option;
	if (cin)
	{
		if (option == 1)
		{
			obj.sort(option, sizeClass);
			obj.print(sizeClass);
		}
		else if (option == 2)
		{
			obj.sort(option, sizeClass);
			obj.print(sizeClass);
		}
		else
			cout << endl << "Wrong symbol" << endl << endl;
	}
	else
	{
		cout << endl << "You've entered wrong symbol" << endl << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Student with minimal age: " << endl << obj.min(sizeClass) << endl << endl;
	for (size_t i = 0; i < sizeClass; i++)
		delete arrayClass[i];
	delete[] arrayClass;
}

Student** createArray(int size)
{
	Student** array = new Student * [size];
	for (size_t i = 0; i < size; i++)
	{
		if (i == 0)
			*(array + i) = new Mark();
		else if (i == 1)
			*(array + i) = new Mark("Katya", "Belko", 20, 5);
		else if (i == 2)
			*(array + i) = new Mark("Vadim", "Geltz", 40, 4);
		else if (i == 3)
			*(array + i) = new Mark("Olya", "Yaremko", 15, 3);
		else
			*(array + i) = new Mark("Random", "Random", rand() % 50 + 1, rand() % 5 + 1);
	}
	return array;
}