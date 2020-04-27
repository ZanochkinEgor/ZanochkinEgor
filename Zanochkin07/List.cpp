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

Task** List::addStudent(Task* student, Task** list)
{
	Task** newList = new Task * [listSize+1];
	for (size_t i = 0; i < listSize; i++)
		*(newList + i) = *(list + i);
	newList[listSize++] = student;
	studentList = newList;
	delete list;
	return studentList;
}

Task** List::createList(int size, Student* age)
{
	studentList = new Task*[size];
	for (size_t i = 0; i<size; i++)
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
	return studentList;
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

Task** List::deleteStudent(int value, Task** list)
{
	if (listSize == 0)
	{
		cout << "Empty list" << endl;
		return NULL;
	}
	Task** newList = new Task * [listSize - 1];
	for (size_t i = 0; i < value; i++)
		*(newList + i) = *(list + i);
	for (size_t i = value, j = value + 1; j < listSize; i++, j++)
		*(newList + i) = *(list + j);
	delete* (studentList + value);
	listSize--;
	studentList = newList;
	delete list;
	return studentList;
}

void List::printOneStudent(stringstream& ss) const
{
	int index, number;
	string name, name2, data;
	int mark, age;
	int exercises;
	int rgz;
	sint day, month, year;
	regex regular("(^[A-ZÀ-ß]+[\\wA-Za-z,.;:-]* [\\wA-Za-z,.;:-]+)");
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(12) << "Date" << "Rgz4Teacher/Gender" << endl;
	ss >> index;
	number = getStudentID(index, studentList);
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

void List::printAll(Task** object) const
{
	auto i = 0;
	if (listSize == 0)
	{
		cout << "Empty list" << endl << endl;
		return;
	}
	else if (listSize < i || i < 0)
		cout << "Wrong number" << endl << endl;
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(12) << "Date" << "Rgz4Teacher/Gender" << endl;
	for (; i < listSize; i++)
		object[i]->print();
	cout << endl;
}

List::~List()
{
	for (size_t i = 0; i < listSize; i++)
		delete studentList[i];
	delete[] studentList;
}

int List::getStudentID(int id,Task** list) const
{
	for (size_t i = 0; i < listSize; i++)
		if (list[i]->getStudentIndex() == id)
			return i;
	cout << "Wrong ID" << endl;
	return -1;
}

int List::getStudentRGZ(int a, Task** list) const
{
	for (size_t i = 0; i < listSize; i++)
		if (list[i]->getRgz() == a)
			return i;
	cout << "Wrong count of RGZ" << endl;
	return -1;
}

Task** List::ReadFile(string filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error open file" << endl;
		return NULL;
	}
	int size = List::FileString(filename);
	string line, var;
	regex regularInheritor1("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	regex regularInheritor1TwoWords("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2TwoWords("([\\d]* [A-Z]+[\\wA-ZA-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	size_t i = 0, a = 0, b = 0;

	int index, mark, rgz, exercises, age, rgz4Teach;
	string name, name2, data, gender, surname;
	sint day, month, year;
	
	for (size_t i = 0; i < listSize; i++)
	{
		delete* (studentList + i);
	}
	delete[] studentList;
	
	studentList = new Task *[size];
	while (getline(fin, line))
	{
		if (regex_match(line.c_str(), regularInheritor1))
		{
			std::istringstream temp(line);
			temp >> index;
			temp >> surname;
			temp >> age;
			temp >> mark;
			temp >> exercises;
			temp >> rgz;
			temp >> day;
			temp >> month;
			temp >> year;
			temp >> rgz4Teach;

			do {
				b = 0;

				a = name.find("--");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("  ");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(",,");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("::");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(";;");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("_");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			studentList[i] = new Inheritor(index, surname, age, mark, exercises, rgz, day, month, year, rgz4Teach);
			i++;
		}
		if (regex_match(line.c_str(), regularInheritor2))
		{
			std::istringstream temp(line);
			temp >> index;
			temp >> surname;
			temp >> age;
			temp >> mark;
			temp >> exercises;
			temp >> rgz;
			temp >> day;
			temp >> month;
			temp >> year;
			temp >> gender;

			do {
				b = 0;

				a = name.find("--");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("  ");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(",,");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("::");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(";;");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("_");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			studentList[i] = new Inheritor2(index, surname, age, mark, exercises, rgz, day, month, year, gender);
			i++;
		}
		if (regex_match(line.c_str(), regularInheritor1TwoWords))
		{
			std::istringstream temp(line);
			temp >> index;
			temp >> name;
			temp >> name2;
			temp >> age;
			temp >> mark;
			temp >> exercises;
			temp >> rgz;
			temp >> day;
			temp >> month;
			temp >> year;
			temp >> rgz4Teach;

			if (name2 == "") name = name + " ";
			else(name = name + " " + name2);

			do {
				b = 0;

				a = name.find("--");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("  ");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(",,");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("::");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(";;");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("_");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			studentList[i] = new Inheritor(index, name, age, mark, exercises, rgz, day, month, year, rgz4Teach);
			i++;
		}
		if (regex_match(line.c_str(), regularInheritor2TwoWords))
		{
			std::istringstream temp(line);
			temp >> index;
			temp >> name;
			temp >> name2;
			temp >> age;
			temp >> mark;
			temp >> exercises;
			temp >> rgz;
			temp >> day;
			temp >> month;
			temp >> year;
			temp >> gender;

			if (name2 == "") name = name + " ";
			else(name = name + " " + name2);

			do {
				b = 0;

				a = name.find("--");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("  ");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(",,");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("::");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find(";;");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

				a = name.find("_");
				if (a != -1)
				{
					name.erase(a, 1);
					b = 1;
				}

			} while (b == 1);

			studentList[i] = new Inheritor2(index, name, age, mark, exercises, rgz, day, month, year, gender);
			i++;
		}

	}
	listSize = size;
	fin.close();
	cout << endl << "Read from file - correct" << endl;
	return studentList;
}

int List::FileString(string filename)
{
	int c = 0;
	string line;
	regex regularInheritor1("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	regex regularInheritor1TwoWords("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2TwoWords("([\\d]* [A-Z]+[\\wA-ZA-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	std::ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error open file";
		return 0;
	}
	while (getline(fin, line))
	{
		if (regex_match(line, regularInheritor1) || regex_match(line, regularInheritor2) || regex_match(line, regularInheritor1TwoWords) || regex_match(line, regularInheritor2TwoWords))
			c++;
		else 
			cout << "String is not correct" << endl;
	}
	fin.close();
	return c;
}

void List::WriteFile(string filename) const
{
	std::ofstream fout(filename);

	for (size_t i = 0; i < getListSize(); i++)
		studentList[i]->writeInFile(fout);
	
	cout << "Write to file - correct" << endl;
	fout.close();
}

Task** List::enterNewStudent()
{
	int index, mark, rgz, exercises, age, rgz4Teach;
	string name, surname, data, gender;
	sint day, month, year;
	regex regularInheritor1("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	regex regularInheritor1TwoWords("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	regex regularInheritor2TwoWords("([\\d]* [A-Z]+[\\wA-ZA-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [A-Za-z]*)");
	cout << "Enter data in line(index,Surname,Name(if it exist),age,mark,exercises,rgz,date(day,month,year),Rgz4Teacher/Gender)" << endl;
	cin.ignore();
	getline(cin, data);

	if (regex_match(data, regularInheritor1))
	{
		std::istringstream temp(data);
		temp >> index;
		temp >> surname;
		temp >> age;
		temp >> mark;
		temp >> exercises;
		temp >> rgz;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> rgz4Teach;

		Task* Task = new Inheritor(index, surname, age, mark, exercises, rgz, day, month, year, rgz4Teach);
		addStudent(Task, studentList);
	}
	else if (regex_match(data, regularInheritor2))
	{
		std::istringstream temp(data);
		temp >> index;
		temp >> surname;
		temp >> age;
		temp >> mark;
		temp >> exercises;
		temp >> rgz;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> gender;

		Task* Task = new Inheritor2(index, surname, age, mark, exercises, rgz, day, month, year, gender);
		addStudent(Task, studentList);
	}
	else if (regex_match(data, regularInheritor1TwoWords))
	{
		std::istringstream temp(data);
		temp >> index;
		temp >> surname;
		temp >> name;
		temp >> age;
		temp >> mark;
		temp >> exercises;
		temp >> rgz;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> rgz4Teach;

		if (name == "") surname = surname + " ";
		else(surname = surname + " " + name);

		Task* Task = new Inheritor(index, surname, age, mark, exercises, rgz, day, month, year, rgz4Teach);
		addStudent(Task, studentList);
	}
	else if (regex_match(data, regularInheritor2TwoWords))
	{
		std::istringstream temp(data);
		temp >> index;
		temp >> surname;
		temp >> name;
		temp >> age;
		temp >> mark;
		temp >> exercises;
		temp >> rgz;
		temp >> day;
		temp >> month;
		temp >> year;
		temp >> gender;

		if (name == "") surname = surname + " ";
		else(surname = surname + " " + name);

		Task* Task = new Inheritor2(index, surname, age, mark, exercises, rgz, day, month, year, gender);
		addStudent(Task, studentList);
	}
	else
		cout << endl << "You enter wrong data" << endl;
	return studentList;
}

int List::regexTask(List& student)
{
	int value = 0;
	regex regular("(^[A-ZÀ-ß]+[\\wA-Za-z,.;:-]* [\\wA-Za-z,.;:-]+)");
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(12) << "Date" << "Rgz4Teacher/Gender" << endl;
	for (size_t i = 0; i < listSize; i++)
		if (regex_match(student.studentList[i]->getName(), regular))
		{
			student.studentList[i]->print();
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
		for (size_t i = 0; i < getListSize() - 1; i++)
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