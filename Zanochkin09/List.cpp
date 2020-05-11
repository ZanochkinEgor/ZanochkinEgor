#include "List.h"

int& List::operator[] (const size_t i) const noexcept (false)
{
	if (i > arraySize || i < 0)
		throw exception("Error! There is no such element in array");
	return *array[i];
}

int List::getArraySize() const
{
	return arraySize;
}

void List::readFromFile(string fileName) noexcept (false)
{
	int arrayIndex = 0;
	int realSizeOfArray = 0;
	int sizeOfFile;
	int oneArraySize;
	int variableForCountTwoDimArrayIndexes = 0;
	string lineInFile;
	ifstream fin(fileName);
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	getline(fin, lineInFile);
	sizeOfFile = std::stoi(lineInFile);
	if (sizeOfFile <= 0 || sizeOfFile != stringsInFile(fileName) - 1)
		throw exception("Error! Wrong information about arrays (incorrect size of a file)");
	while (!fin.eof())
	{
		getline(fin, lineInFile);
		istringstream temp(lineInFile);
		temp >> oneArraySize;
		if (oneArraySize > 0)
		{
			int spcb = count(lineInFile.begin(), lineInFile.end(), ' ');
			if (spcb == oneArraySize)
				realSizeOfArray++;
		}
	}
	if (realSizeOfArray == 0)
		throw exception("There is no correct arrays in file");
	arraySize = realSizeOfArray;
	int** tempTwoDimArray = new int* [realSizeOfArray];
	fin.seekg(0, fin.beg);
	getline(fin, lineInFile);
	for (variableForCountTwoDimArrayIndexes; variableForCountTwoDimArrayIndexes < realSizeOfArray;)
	{
		getline(fin, lineInFile);
		istringstream temp(lineInFile);
		temp >> oneArraySize;
		int spcb = count(lineInFile.begin(), lineInFile.end(), ' ');
		if (oneArraySize == spcb)
		{
			int* arr = new int[oneArraySize + 1];
			for (size_t i = 0; i < oneArraySize + 1; i++)
			{
				if (i == 0)
					arr[0] = oneArraySize;
				else
					temp >> arr[i];
			}
			tempTwoDimArray[arrayIndex] = arr;
			arrayIndex++;
			variableForCountTwoDimArrayIndexes++;
		}
	}
	array = tempTwoDimArray;
	fin.close();
	cout << endl << "Reading from file complete " << endl << endl;
}

int List::stringsInFile(string fileName) const noexcept
{
	ifstream fin(fileName);
	string line;
	int size = 0;
	while (getline(fin, line))
		size++;
	fin.close();
	return size;
}

int* List::task() noexcept (false)
{
	int size = 0;
	vector<int> resultArray;
	for (size_t i = 0; i < arraySize; i++)
		for (size_t j = 0; j < *array[i]; j++)
			if (array[i][j + 1] > 0)
			{
				resultArray.resize(++size);
				resultArray[size - 1] = array[i][j + 1];
			}
	int length = resultArray.size();
	int* resArray = new int[length];
	for (size_t i = 0; i < length; i++)
		resArray[i] = resultArray[i];
	cout << "Unsigned array:" << endl;
	for (size_t i = 0; i < length; i++)
		cout << resArray[i] << " ";
	return resArray;
}

List::~List()
{
	for (size_t i = 0; i < arraySize; i++)
		delete array[i];
	delete[] array;
}

void List::print() noexcept
{
	cout << "List of elements:" << endl;
	int count = 1;
	for (size_t i = 0; i < arraySize; i++)
	{
		cout << count << ". ";
		for (size_t j = 0; j < *array[i]; j++)
			cout << array[i][j + 1] << " ";
		cout << endl;
		count++;
	}
}

void List::writeInFile(string fileName, int* sz) const noexcept (false)
{
	ofstream fout(fileName);
	fout.exceptions(ifstream::badbit | ifstream::failbit);
	fout.setf(std::ios::left);
	int count = 1;
	for (size_t i = 0; i < arraySize; i++)
	{
		fout << count << ". ";
		for (size_t j = 0; j < *array[i]; j++)
			fout << array[i][j + 1] << " ";
		fout << endl;
		count++;
	}
	fout << endl << "Task result:" << endl;
	int arrSize = _msize(sz) / sizeof(int);
	for (size_t i = 0; i < arrSize; i++)
		fout << sz[i] << " ";
	cout << endl << "Writing in file complete " << endl << endl;
	fout.close();
}

string fileName() noexcept
{
	string filename;
	cin >> filename;
	return filename;
}