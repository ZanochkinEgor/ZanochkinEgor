#include "Student.h"
#include "TemplateClass.h"

void Menu() noexcept
{
	try
	{
		intArray();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	try
	{
		floatArray();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	try
	{
		classArray();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
}

void intArray() noexcept (false)
{
	TemplateClass obj;
	int sizeInt;
	int numberInt;
	int indexInt;
	int option;
	cout << "Enter size of INT array:" << endl;
	cin >> sizeInt;
	if (sizeInt <= 0 || !cin)
		throw exception("ERROR! You've enter wrong size");
	int* arrayInt = new int[sizeInt];
	cout << endl << "Enter " << sizeInt << " int numbers:" << endl;
	for (size_t i = 0; i < sizeInt; i++)
	{
		cin >> arrayInt[i];
		if (!cin)
		{
			delete[] arrayInt;
			throw exception("ERROR! Wrong data!");
		}
	}
	obj.print(arrayInt, sizeInt);
	cout << "Enter number to get it's index:" << endl;
	cin >> numberInt;
	//Если будет ошибка при вводе, необходимо выполнить след. действия что бы в будущем cin работал правильно
	if (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		indexInt = -1;
	}
	else
		indexInt = obj.index(arrayInt, numberInt, sizeInt);
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
			obj.sort(arrayInt, option, sizeInt);
			obj.print(arrayInt, sizeInt);
		}
		else if (option == 2)
		{
			obj.sort(arrayInt, option, sizeInt);
			obj.print(arrayInt, sizeInt);
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
	cout << "Minimal element is: " << obj.min(arrayInt, sizeInt) << endl << endl;
	delete[] arrayInt;
}

void floatArray() noexcept (false)
{
	TemplateClass obj;
	int sizeFloat;
	float numberFloat;
	int indexFloat;
	int option;
	cout << "Enter size of FLOAT array:" << endl;
	cin >> sizeFloat;
	if (sizeFloat <= 0 || !cin)
		throw exception("ERROR! You've enter wrong size");
	float* arrayFloat = new float[sizeFloat];
	cout << endl << "Enter " << sizeFloat << " float numbers:" << endl;
	for (size_t i = 0; i < sizeFloat; i++)
	{
		cin >> arrayFloat[i];
		if (!cin)
		{
			delete[] arrayFloat;
			throw exception("ERROR! Wrong data!");
		}
	}
	obj.print(arrayFloat, sizeFloat);
	cout << "Enter number to get it's index:" << endl;
	cin >> numberFloat;
	if (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		indexFloat = -1;
	}
	else
		indexFloat = obj.index(arrayFloat, numberFloat, sizeFloat);
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
			obj.sort(arrayFloat, option, sizeFloat);
			obj.print(arrayFloat, sizeFloat);
		}
		else if (option == 2)
		{
			obj.sort(arrayFloat, option, sizeFloat);
			obj.print(arrayFloat, sizeFloat);
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
	cout << "Minimal element is: " << obj.min(arrayFloat, sizeFloat) << endl << endl;
	delete[] arrayFloat;
}

void classArray() noexcept (false)
{
	TemplateClass obj;
	Student oneObj;
	int sizeClass;
	int indexClass;
	int option;
	cout << "Enter size of CLASS array:" << endl;
	cin >> sizeClass;
	if (sizeClass <= 0 || !cin)
		throw exception("ERROR! You've enter wrong size");
	Student* arrayClass = oneObj.createArray(sizeClass);
	obj.print(arrayClass, sizeClass);
	cout << "Enter age to get it's index:" << endl;
	cin >> oneObj;
	if (!cin)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		indexClass = -1;
	}
	else
		indexClass = obj.index(arrayClass, oneObj, sizeClass);
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
			obj.sort(arrayClass, option, sizeClass);
			obj.print(arrayClass, sizeClass);
		}
		else if (option == 2)
		{
			obj.sort(arrayClass, option, sizeClass);
			obj.print(arrayClass, sizeClass);
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
	cout << "Student with minimal age: " << endl << obj.min(arrayClass, sizeClass) << endl << endl;
	delete[] arrayClass;
}