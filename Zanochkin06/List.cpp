#include "List.h"
#include "Task.h"
#include "Date.h"

int List::getListSize() const { return listSize; }
void List::setListSize(int size) { listSize = size; }

void List::addStudent(const Task task)
{
	if (task.getMark() == 0)
	{
		cout << "Empty object. Error";
		return;
	}
	setListSize(getListSize() + 1);
	Task* newstud = new Task[listSize];
	for (size_t i = 0; i < listSize - 1; i++)
		newstud[i] = stud[i];
	newstud[listSize - 1] = task;
	if (newstud[listSize - 1].getStudentIndex() == 0)
	{
		newstud[listSize - 1].setStudentIndex(stud->generateID());
		newstud[listSize - 1].setRgz(stud->generateRGZ());
	}
	delete[] stud;
	stud = new Task[listSize];
	for (size_t i = 0; listSize > i; i++)
		stud[i] = newstud[i];
	delete[] newstud;
}

void List::createList()
{
	stud = new Task[listSize];
	for (size_t i = 0; listSize > i; i++)
	{
		stud[i] = CreateStudent();
		stud[i].setStudentIndex(stud->generateID());
		stud[i].setRgz(stud->generateRGZ());
	}
}

void List::deleteStudent(int c)
{
	setListSize(getListSize() - 1);
	Task* newstud = new Task[listSize];
	size_t i = 0;
	for (; i < getListSize(); i++)
	{
		if (stud[i].getStudentIndex() == c)
			break;
		newstud[i] = stud[i];
	}
	for (; i < getListSize(); i++)
		newstud[i] = stud[i + 1];
	delete[] stud;
	stud = new Task[listSize];
	for (size_t i = 0; i < getListSize(); i++)
		stud[i] = newstud[i];
	delete[] newstud;
}

void List::printOneStudent(stringstream& ss) const
{
	int index;
	string name, name2;
	int mark, age;
	int exercises;
	int rgz;
	sint day, month, year;
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << "Date" << endl;
	ss >> index;
	ss >> name;
	ss >> name2;
	ss >> age;
	ss >> mark;
	ss >> exercises;
	ss >> rgz;
	ss >> day;
	ss >> month;
	ss >> year;

	if (name2 == "")
		name = name + " ";
	else (name = name + " " + name2);

	cout << std::left;
	cout << setw(6) << index;
	cout << setw(18) << name;
	cout << setw(8) << age;
	cout << setw(13) << mark;
	cout << setw(13) << exercises;
	cout << setw(10) << rgz;
	cout << setw(3) << day << setw(3) << month << year << endl;
}

void List::printAll() const
{
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << "Date" << endl;
	for (size_t i = 0; List::getListSize() > i; i++)
		cout << std::left << setw(6) << stud[i].getStudentIndex() << setw(18) << stud[i].getName() << setw(8) << stud[i].getAge() << setw(13) << stud[i].getMark() << setw(13) << stud[i].getCountOfDoneExercises() << setw(10) << stud[i].getRgz() << setw(3) << stud[i].getDay() << setw(3) << stud[i].getMonth() << stud[i].getYear() << endl;
}

List::~List()
{
	delete[] stud;
}

int List::getStudentID(int id) const
{
	for (size_t i = 0; i < listSize; i++)
		if (stud[i].getStudentIndex() == id)
			return i;
	cout << "Wrong ID" << endl;
	return -1;
}

int List::getStudentRGZ(int a) const
{
	for (size_t i = 0; i < listSize; i++)
		if (stud[i].getRgz() == a)
			return i;
	cout << "Wrong count of RGZ" << endl;
	return -1;
}

void List::ReadFile(string filename, int c)
{
	std::ifstream fin(filename);
	if (!fin.is_open())
		return;
	string line;
	regex regular("([\\d]* [A-ZР-п]+[\\wР-пр-џ,.;:-]* [\\wР-пр-џ,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	int i = 0, a = 0, b = 0;
	delete[] stud;
	stud = new Task[c];
	while (getline(fin, line) && i < c)
	{
		if (regex_match(line.c_str(), regular))
		{
			int studentIndex;
			string name, name2;
			int mark, age;
			int countOfDoneExercises;
			int rgz;
			sint day, month, year;
			std::istringstream fin(line);
			fin >> studentIndex;
			fin >> name;
			fin >> name2;
			fin >> age;
			fin >> mark;
			fin >> countOfDoneExercises;
			fin >> rgz;
			fin >> day;
			fin >> month;
			fin >> year;

			if (name2 == "")
				name = name + " ";
			else (name = name + " " + name2);

			do
			{
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

			Task ex(studentIndex, name, age, mark, countOfDoneExercises, rgz, day, month, year);
			stud[i++] = ex;
		}
	}
	setListSize(c);
	fin.close();
	cout << "Data from file have written" << endl;
	return;
}

int List::FileString(string filename)
{
	int c = 0;
	string line;
	regex regular("([\\d]* [A-ZР-п]+[\\wР-пр-џ,.;:-]* [\\wР-пр-џ,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	std::ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error open file";
		return 0;
	}
	while (getline(fin, line))
	{
		if (regex_match(line, regular))
			c++;
		else cout << "String is not correct" << endl;
	}

	fin.close();
	return c;
}

void List::WriteFile(string filename) const
{
	std::ofstream fout(filename);
	if (!fout.is_open())
	{
		cout << "Error open file";
		return;
	}
	fout << "Base class" << endl << endl;
	fout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << "Date" << endl;
	for (size_t i = 0; i < listSize; i++)
	{
		fout << std::left;
		fout << setw(6) << stud[i].getStudentIndex();
		fout << setw(18) << stud[i].getName();
		fout << setw(8) << stud[i].getAge();
		fout << setw(13) << stud[i].getMark();
		fout << setw(13) << stud[i].getCountOfDoneExercises();
		fout << setw(10) << stud[i].getRgz();
		fout << setw(3) << stud[i].getDay() << setw(3) << stud[i].getMonth() << stud[i].getYear() << endl;
	}
	cout << "Write to file - correct" << endl;
	return;
}

stringstream List::getObj(int i) const
{
	stringstream ss;
	ss << stud[i].getStudentIndex();
	ss << " " << stud[i].getName();
	ss << " " << stud[i].getAge();
	ss << " " << stud[i].getMark();
	ss << " " << stud[i].getCountOfDoneExercises();
	ss << " " << stud[i].getRgz();
	ss << " " << stud[i].getDay();
	ss << " " << stud[i].getMonth();
	ss << " " << stud[i].getYear();
	return ss;
}

stringstream List::DataToString()
{
	stringstream ss;
	int index, mark, rgz, exercises, age;
	string name, name2, temp;
	sint day, month, year;
	cout << "Enter student data (ID, Surname, Name, Age, Mark, Exercises, RGZ, Date(day,month,year)):" << endl;
	cin >> index >> name >> name2 >> age >> mark >> exercises >> rgz >> day >> month >> year;
	ss << index << " " << name << " " << name2 << " " << age << " " << mark << " " << exercises << " " << rgz << " " << day << " " << month << " " << year;
	return ss;
}

Task List::StringToObject(stringstream ss)
{
	Task add, error;
	int index, mark, rgz, exercises, age;
	string name, name2;
	sint day, month, year;
	regex regular("(^[A-Z]+[\\w]* [\\w]*)");
	ss >> index >> name >> name2 >> age >> mark >> exercises >> rgz >> day >> month >> year;

	if (name2 == "")
		name = name + " ";
	else (name = name + " " + name2);

	if (!regex_match(name.c_str(), regular))
	{
		cout << "You enter wrong data";
		return error;
	}

	add.setStudentIndex(index);
	add.setName(name);
	add.setAge(age);
	add.setMark(mark);
	add.setCountOfDoneExercises(exercises);
	add.setRgz(rgz);
	add.setDay(day);
	add.setMonth(month);
	add.setYear(year);
	return add;
}

void List::regexTask()
{
	stringstream ss;
	int index, mark, rgz, exercises, age;
	string name, name2;
	sint day, month, year;
	regex regular("(^[A-ZР-п]+[\\wР-пр-џ,.;:-]* [\\wР-пр-џ,.;:-]+)");
	int listSize = getListSize();
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << "Date" << endl;
	for (size_t i = 0; i < listSize; i++)
		if (regex_match(stud[i].getName(), regular))
		{
			ss = getObj(i);
			ss >> index >> name >> name2 >> age >> mark >> exercises >> rgz >> day >> month >> year;

			if (name2 == "")
				name = name + " ";
			else (name = name + " " + name2);

			cout << std::left;
			cout << setw(6) << index;
			cout << setw(18) << name;
			cout << setw(8) << age;
			cout << setw(13) << mark;
			cout << setw(13) << exercises;
			cout << setw(10) << rgz;
			cout << setw(3) << day << setw(3) << month << year << endl;
		}
}

bool List::sortAsc(const int& a, const int& b) { return a > b; }
bool List::sortDesc(const int& a, const int& b) { return a < b; }

void List::sort(comp condition)
{
	Task temp;
	int pr;
	do
	{
		pr = 0;
		for (size_t i = 0; i < getListSize() - 1; i++)
		{
			if (condition(stud[i].getMark(), stud[i + 1].getMark()))
			{
				temp = stud[i];
				stud[i] = stud[i + 1];
				stud[i + 1] = temp;
				pr = 1;
			}
		}
	} while (pr == 1);
}