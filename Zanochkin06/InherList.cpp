#include "InherList.h"
#include "InherTask.h"

int InheritorList::getListSize() const { return listSize; }
void InheritorList::setListSize(int size) { listSize = size; }

void InheritorList::addStudent(const Inheritor task)
{
	if (task.getMark() == 0)
	{
		cout << "Empty object. Error";
		return;
	}
	setListSize(getListSize() + 1);
	Inheritor* newstud = new Inheritor[listSize];
	for (size_t i = 0; i < listSize - 1; i++)
		newstud[i] = stud[i];
	newstud[listSize - 1] = task;
	if (newstud[listSize - 1].getStudentIndex() == 0)
	{
		newstud[listSize - 1].setStudentIndex(stud->InherGenerateID());
		newstud[listSize - 1].setRgz(stud->InherGenerateRGZ());
		newstud[listSize - 1].setRgzForTeacher(stud->InherGenerateRGZForTeacher());
	}
	delete[] stud;
	stud = new Inheritor[listSize];
	for (size_t i = 0; listSize > i; i++)
		stud[i] = newstud[i];
	delete[] newstud;
}

void InheritorList::createList()
{
	stud = new Inheritor[listSize];
	for (size_t i = 0; listSize > i; i++)
	{
		stud[i] = InherCreateStudent();
		stud[i].setStudentIndex(stud->InherGenerateID());
		stud[i].setRgz(stud->InherGenerateRGZ());
		stud[i].setRgzForTeacher(stud->InherGenerateRGZForTeacher());
	}
}

void InheritorList::deleteStudent(int c)
{
	setListSize(getListSize() - 1);
	Inheritor* newstud = new Inheritor[listSize];
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
	stud = new Inheritor[listSize];
	for (size_t i = 0; i < getListSize(); i++)
		stud[i] = newstud[i];
	delete[] newstud;
}

void InheritorList::printOneStudent(stringstream& ss) const
{
	int index;
	string name, name2;
	int mark, age;
	int exercises;
	int rgz, rgzForTeacher;
	sint day, month, year;
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(20) << "Date" << "RGZ for Teacher" << endl;
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
	ss >> rgzForTeacher;

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
	cout << setw(3) << day << setw(3) << month << setw(20) << year;
	cout << rgzForTeacher << endl;
}

void InheritorList::printAll() const
{
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" <<setw(20)<< "Date" << "RGZ for Teacher"<< endl;
	for (size_t i = 0; InheritorList::getListSize() > i; i++)
		cout << std::left << setw(6) << stud[i].getStudentIndex() << setw(18) << stud[i].getName() << setw(8) << stud[i].getAge() << setw(13) << stud[i].getMark() << setw(13) << stud[i].getCountOfDoneExercises() << setw(10) << stud[i].getRgz() << setw(3) << stud[i].getDay() << setw(3) << stud[i].getMonth() <<setw(20)<< stud[i].getYear()<<stud[i].getRgzForTeacher() << endl;
}

InheritorList::~InheritorList()
{
	delete[] stud;
}

int InheritorList::getStudentID(int id) const
{
	for (size_t i = 0; i < listSize; i++)
		if (stud[i].getStudentIndex() == id)
			return i;
	cout << "Wrong ID" << endl;
	return -1;
}

int InheritorList::getStudentRGZ(int a) const
{
	for (size_t i = 0; i < listSize; i++)
		if (stud[i].getRgz() == a)
			return i;
	cout << "Wrong count of RGZ" << endl;
	return -1;
}

void InheritorList::ReadFile(string filename, int c)
{
	std::ifstream fin(filename);
	if (!fin.is_open())
		return;
	string line;
	regex regular("([\\d]* [A-ZР-п]+[\\wР-пр-џ,.;:-]* [\\wР-пр-џ,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	int i = 0, a = 0, b = 0;
	delete[] stud;
	stud = new Inheritor[c];
	while (getline(fin, line) && i < c)
	{
		if (regex_match(line.c_str(), regular))
		{
			int studentIndex;
			string name, name2;
			int mark, age;
			int countOfDoneExercises;
			int rgz, rgzForTeacher;
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
			fin >> rgzForTeacher;

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

			Inheritor ex(studentIndex, name, age, mark, countOfDoneExercises, rgz, day, month, year, rgzForTeacher);
			stud[i++] = ex;
		}
	}
	setListSize(c);
	fin.close();
	cout << "Data from file have written" << endl;
	return;
}

int InheritorList::FileString(string filename)
{
	int c = 0;
	string line;
	regex regular("([\\d]* [A-ZР-п]+[\\wР-пр-џ,.;:-]* [\\wР-пр-џ,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
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

void InheritorList::WriteFile(string filename) const
{
	std::ofstream fout(filename, std::ios::app);
	if (!fout.is_open())
	{
		cout << "Error open file";
		return;
	}
	fout << endl << "Inheritor class" << endl << endl;
	fout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(20) << "Date" << "RGZ for Teacher" << endl;
	for (size_t i = 0; i < listSize; i++)
	{
		fout << std::left;
		fout << setw(6) << stud[i].getStudentIndex();
		fout << setw(18) << stud[i].getName();
		fout << setw(8) << stud[i].getAge();
		fout << setw(13) << stud[i].getMark();
		fout << setw(13) << stud[i].getCountOfDoneExercises();
		fout << setw(10) << stud[i].getRgz();
		fout << setw(3) << stud[i].getDay() << setw(3) << stud[i].getMonth() << setw(20) << stud[i].getYear();
		fout << stud[i].getRgzForTeacher() << endl;
	}
	cout << "Write to file - correct" << endl;
	fout.close();
	return;
}

stringstream InheritorList::getObj(int i) const
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
	ss << " " << stud[i].getRgzForTeacher();
	return ss;
}

Inheritor InheritorList::enterNewStudent()
{
	Inheritor add, error;
	int index, mark, rgz, exercises, age, rgzForTeacher;
	string name, surname, data;
	sint day, month, year;
	regex regular("([\\d]* [A-Z]+[\\wA-Za-z,.;:-]* [A-Z]+[\\wA-Za-z,.;:-]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]* [\\d]*)");
	cout << "Enter student data (ID, Surname, Name, Age, Mark, Exercises, RGZ, Date(day,month,year), RGZ for Teacher):" << endl;
	getline(cin, data);
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
	temp >> rgzForTeacher;

	if (name == "")
		surname = surname + " ";
	else (surname = surname + " " + name);

	if (!regex_match(data, regular))
	{
		cout << "You enter wrong data";
		return error;
	}

	add.setStudentIndex(index);
	add.setName(surname);
	add.setAge(age);
	add.setMark(mark);
	add.setCountOfDoneExercises(exercises);
	add.setRgz(rgz);
	add.setDay(day);
	add.setMonth(month);
	add.setYear(year);
	add.setRgzForTeacher(rgzForTeacher);
	return add;
}

void InheritorList::regexTask()
{
	stringstream ss;
	int index, mark, rgz, exercises, age, rgzForTeacher;
	string name, name2;
	sint day, month, year;
	regex regular("(^[A-ZР-п]+[\\wР-пр-џ,.;:-]* [\\wР-пр-џ,.;:-]+)");
	int listSize = getListSize();
	cout << std::left << setw(10) << "Index" << setw(13) << "Name" << setw(8) << "Age" << setw(10) << "Mark" << setw(16) << "Exercises" << setw(13) << "RGZ" << setw(20) << "Date" << "RGZ for Teacher" << endl;
	for (size_t i = 0; i < listSize; i++)
		if (regex_match(stud[i].getName(), regular))
		{
			ss = getObj(i);
			ss >> index >> name >> name2 >> age >> mark >> exercises >> rgz >> day >> month >> year >> rgzForTeacher;

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
			cout << setw(3) << day << setw(3) << month << setw(20) << year;
			cout << rgzForTeacher << endl;
		}
}

bool InheritorList::sortAsc(const int& a, const int& b) { return a > b; }
bool InheritorList::sortDesc(const int& a, const int& b) { return a < b; }

void InheritorList::sort(comp condition)
{
	Inheritor temp;
	int pr;
	do
	{
		pr = 0;
		for (size_t i = 0; i < listSize - 1; i++)
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