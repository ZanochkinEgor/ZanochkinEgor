#include "List.h"
#include "Task.h"
#include "Date.h"

int List::getListSize() const { return listSize; }

int generateID()
{
	static int id = 1;
	return id++;
}

int generateRGZ()
{
	static int RGZ = 5;
	return RGZ++;
}

void List::addStudent(Task* student)
{
	Task** newList = new Task * [listSize + 1];
	Task** temp = studentList;
	for (size_t i = 0; i < listSize; i++)
		newList[i] = studentList[i];
	newList[listSize++] = student;
	studentList = newList;
	newList = temp;
	delete newList;
}

void List::createList(int size, Student* age)
{
	studentList = new Task * [size];
	for (size_t i = 0; i < size; i++)
	{
		if (i == 0)
		{
			int id = generateID();
			int rgz = generateRGZ();
			*(studentList + i) = new Inheritor(id, "Vasya", *(age), 2, 5, rgz, 2, 2, 2002, 5);
		}
		else if (i == 1)
		{
			int id = generateID();
			int rgz = generateRGZ();
			*(studentList + i) = new Inheritor2(id, "Ivanova Katya", *(age + 1), 5, 10, rgz, 1, 1, 2000, "Female");
		}
	}
	listSize = size;
}

Task* List::newStudent(Student* age, int value)
{
	if (value == 1)
	{
		int id = generateID();
		int rgz = generateRGZ();
		Task* Task = new Inheritor(id, "Vasya", *(age), 2, 5, rgz, 2, 2, 2002, 5);
		return Task;
	}
	else
	{
		int id = generateID();
		int rgz = generateRGZ();
		Task* Task = new Inheritor2(id, "Ivanova Katya", *(age + 1), 5, 10, rgz, 1, 1, 2000, "Female");
		return Task;
	}
}

void List::deleteStudent(int value)
{
	if (listSize == 0)
	{
		cout << "Empty list" << endl;
		return;
		
	}
	Task** newList = new Task * [listSize - 1];
	Task** temp = studentList;
	for (size_t i = 0; i < value; i++)
		newList[i] = studentList[i];
	for (size_t i = value, j = value + 1; j < listSize; i++, j++)
		newList[i] = studentList[j];
	listSize--;
	studentList = newList;
	newList = temp;
	delete* (newList + value);
	delete newList;
}

void List::printOneStudent(int num) const
{
	stringstream ss = studentList[num]->getStr();
	int index, number;
	string name, name2, data;
	int mark, age;
	int exercises;
	int rgz;
	sint day, month, year;
	regex regular("(^[A-ZÀ-ß]+[\\wA-Za-z,.;:-]* [\\wA-Za-z,.;:-]+)");
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(12) << "Date" << "Rgz4Teacher/Gender" << endl;
	ss >> index;
	number = getStudentID(index);
	if (regex_match(studentList[number]->getName(), regular))
	{
		ss >> name;
		ss >> name2;
		ss >> age;
		ss >> mark;
		ss >> exercises;
		ss >> rgz;
		ss >> day;
		ss >> month;
		ss >> year;
		ss >> data;

		if (name2 == "")
			name = name + " ";
		else
			name = name + " " + name2;
	}
	else
	{
		ss >> name;
		ss >> age;
		ss >> mark;
		ss >> exercises;
		ss >> rgz;
		ss >> day;
		ss >> month;
		ss >> year;
		ss >> data;
	}
	cout << std::left;
	cout << setw(6) << index;
	cout << setw(18) << name;
	cout << setw(8) << age;
	cout << setw(13) << mark;
	cout << setw(13) << exercises;
	cout << setw(10) << rgz;
	cout << setw(3) << day << setw(3) << month << setw(12) << year;
	cout << data;
}

void List::printAll() const
{
	auto i = 0;
	if (listSize == 0)
	{
		cout << "Empty list" << endl << endl;
		return;
	}
	else if (listSize < i || i < 0)
		cout << "Wrong number" << endl << endl;
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(8) << "Mark" << setw(15) << "Exercises" << setw(13) << "RGZ" << setw(12) << "Date" << "Rgz4Teacher/Gender" << endl;
	for (; i < listSize; i++)
		cout << *studentList[i];
	cout << endl;
}

List::~List()
{
	for (size_t i = 0; i < listSize; i++)
		delete studentList[i];
	delete[] studentList;
}

int List::getStudentID(int id) const
{
	for (size_t i = 0; i < listSize; i++)
		if (studentList[i]->getStudentIndex() == id)
			return i;
	cout << "Wrong ID" << endl;
	return -1;
}

int List::getStudentRGZ(int a) const
{
	for (size_t i = 0; i < listSize; i++)
		if (studentList[i]->getRgz() == a)
			return i;
	cout << "Wrong count of RGZ" << endl;
	return -1;
}

void List::readFile(string filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error open file" << endl;
	}
	int size = List::fileString(filename);
	string line;
	regex regularInt("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularString("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	size_t i = 0, a = 0, b = 0;
	for (size_t i = 0; i < listSize; i++)
	{
		delete* (studentList + i);
	}
	delete[] studentList;
	studentList = new Task * [size];
	while (getline(fin, line))
	{
		b = 1;
		if (regex_match(line.c_str(), regularInt))
		{
			do 
			{
				b = 0;

				a = line.find("--");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("  ");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(",,");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("::");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(";;");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("_");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

			} while (b == 1);
			std::istringstream temp(line);
			studentList[i] = new Inheritor;
			temp >> *studentList[i];
			i++;
		}
		else if (regex_match(line.c_str(), regularString))
		{
			do
			{
				b = 0;

				a = line.find("--");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("  ");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(",,");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("::");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find(";;");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

				a = line.find("_");
				if (a != -1)
				{
					line.erase(a, 1);
					b = 1;
				}

			} while (b == 1);
			std::istringstream temp(line);
			studentList[i] = new Inheritor2;
			temp >> *studentList[i];
			i++;
		}
	}
	listSize = size;
	fin.close();
	cout << endl << "Read from file - correct" << endl;
}

int List::fileString(string filename) const
{
	int c = 0;
	string line;
	regex regularInheritor1("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	std::ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error open file";
		return 0;
	}
	while (getline(fin, line))
	{
		if (regex_match(line, regularInheritor1) || regex_match(line, regularInheritor2))
			c++;
		else
			cout << "String is not correct" << endl;
	}
	fin.close();
	return c;
}

void List::writeFile(string filename) const
{
	std::ofstream fout(filename);
	for (size_t i = 0; i < listSize; i++)
		fout << *studentList[i];
	cout << "Write to file - correct" << endl;
	fout.close();
}

void List::enterNewStudent()
{
	string data;
	regex regularInt("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularString("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	cout << "Enter data in line(index,Surname,age,mark,exercises,rgz,date(day,month,year),Rgz4Teacher/Gender)" << endl;
	cin.ignore();
	getline(cin, data);
	if (regex_match(data, regularInt))
	{
		std::istringstream temp(data);
		Task* newStudent = new Inheritor;
		temp >> *newStudent;
		cout << endl;
		addStudent(newStudent);
	}
	else if (regex_match(data, regularString))
	{
		std::istringstream temp(data);
		Task* newStudent = new Inheritor2;
		temp >> *newStudent;
		cout << endl;
		addStudent(newStudent);
	}
	else
		cout << endl << "You enter wrong data" << endl;
}

int List::regexTask()
{
	int value = 0;
	regex regular("(^[A-ZÀ-ß]+[\\wA-Za-z,.;:-]* [\\wA-Za-z,.;:-]+)");
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(8) << "Mark" << setw(15) << "Exercises" << setw(13) << "RGZ" << setw(12) << "Date" << "Rgz4Teacher/Gender" << endl;
	for (size_t i = 0; i < listSize; i++)
		if (regex_match(studentList[i]->getName(), regular))
		{
			cout << *studentList[i];
			value++;
		}
	cout << endl;
	return value;
}

bool List::sortAsc(const int& a, const int& b) { return a > b; }
bool List::sortDesc(const int& a, const int& b) { return a < b; }

void List::sort(comp condition)
{
	Task* temp;
	int pr;
	do
	{
		pr = 0;
		for (size_t i = 0; i < listSize - 1; i++)
		{
			if (condition(studentList[i]->getMark(), studentList[i + 1]->getMark()))
			{
				temp = *(studentList + i);
				*(studentList + i) = *(studentList + i + 1);
				*(studentList + i + 1) = temp;
				pr = 1;
			}
		}
	} while (pr == 1);
}

Task*& List::operator[] (int i)
{
	return studentList[i];
}