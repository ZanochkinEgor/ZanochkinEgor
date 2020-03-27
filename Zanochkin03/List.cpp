#include "List.h"
#include "Task.h"

int List::getListSize() const { return listSize; }
void List::setListSize(int size) { listSize = size; }

void List::addStudent(const Task task)
{
	setListSize(getListSize() + 1);
	Task* newstud = new Task[listSize];
	for (int i = 0; i < listSize - 1; i++)
		newstud[i] = stud[i];
	newstud[listSize - 1] = task;
	if (newstud[listSize - 1].getStudentIndex() == 0)
	{
		newstud[listSize - 1].setStudentIndex(stud[listSize - 2].getStudentIndex() + 1);
		newstud[listSize - 1].setRgz(stud[listSize - 2].getRgz() + 1);
	}
	delete[] stud;
	stud = new Task[listSize];
	for (int i = 0; listSize > i; i++)
		stud[i] = newstud[i];
	delete[] newstud;
}
void List::createList()
{
	stud = new Task[listSize];
	for (int i = 0; listSize > i; i++)
	{
		stud[i] = CreateStudent();
		stud[i].setStudentIndex(i + 1);
		stud[i].setRgz(i + 5);
	}
}
void List::deleteStudent(int c)
{
	setListSize(getListSize() - 1);
	Task* newstud = new Task[listSize];
	int i = 0;
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
	for (int i = 0; i < getListSize(); i++)
		stud[i] = newstud[i];
	delete[] newstud;
}
void List::printOneStudent(stringstream& ss) const
{
	int index;
	string name;
	int mark;
	int exercises;
	int rgz;
	cout << std::left << setw(6) << "Index" << setw(7) << "Name" << setw(10) << "Mark" << setw(13) << "Exercises" << setw(8) << "RGZ" << endl;
	ss >> index;
	ss >> name;
	ss >> mark;
	ss >> exercises;
	ss >> rgz;
	cout << std::left;
	cout << setw(6) << index;
	cout << setw(7) << name;
	cout << setw(10) << mark;
	cout << setw(13) << exercises;
	cout << setw(8) << rgz;
}
void List::printAll() const
{
	cout << std::left <<setw(6)<< "Index" << setw(7) << "Name" << setw(10) << "Mark" << setw(13) << "Exercises" << setw(8) << "RGZ"<<endl;
	for (int i = 0; List::getListSize() > i; i++)
		cout << std::left <<setw(6)<< stud[i].getStudentIndex() << setw(7) << stud[i].getName() << setw(10) << stud[i].getMark() << setw(13) << stud[i].getCountOfDoneExercises() << setw(8) << stud[i].getRgz()<<endl;
}
List::~List()
{
	cout << "Destructor List" << endl;
	delete[] stud;
}

int List::getStudentID(int id) const
{
	for (int i = 0; i < listSize; i++)
		if (stud[i].getStudentIndex() == id)
			return i;
	cout << "Wrong ID" << endl;
	return -1;
}

int List::getStudentRGZ(int a) const
{
	for (int i = 0; i < listSize; i++)
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
	delete[] stud;
	stud = new Task[c];
	for (int i = 0; c > i; i++) 
	{
		int studentIndex;
		string name;
		int mark;
		int countOfDoneExercises;
		
		int rgz;
		
		fin >> studentIndex;
		fin >> name;
		fin >> mark;
		fin >> countOfDoneExercises;
		fin >> rgz;
		Task ex(studentIndex, name, mark, countOfDoneExercises, rgz);
		stud[i] = ex;
	}
	setListSize(c);
	fin.close();
	cout << "Data from file have written";
	return;
}

int List::FileString(string filename) 
{
	int c = 0;
	string line;
	std::ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error open file";
		return 0;
	}
	while (getline(fin, line)) {
		c++;
	}
	fin.close();
	return c;
}

void List::WriteFile(string filename) const 
{
	std::ofstream fout(filename);
	if (!fout.is_open())
	{
		cout << "";
		return;
	}
	for (int i = 0; listSize > i; i++) {
		fout << std::left;
		fout << setw(3) << stud[i].getStudentIndex();
		fout << setw(7) << stud[i].getName();
		fout << setw(7) << stud[i].getMark();
		fout << setw(6) << stud[i].getCountOfDoneExercises();
		fout << setw(6) << stud[i].getRgz() << endl;
	}
	cout << "Write to file - correct" << endl;
	return;
}

stringstream List::getObj(int i) const {
	stringstream ss;
	ss << stud[i].getStudentIndex();
	ss << " " << stud[i].getName();
	ss << " " << stud[i].getMark();
	ss << " " << stud[i].getCountOfDoneExercises();
	ss << " " << stud[i].getRgz();
	return ss;
}

stringstream List::DataToString() 
{
	stringstream ss;
	int index, mark, rgz, exercises;
	string name;
	cout << "Enter student data (ID, Name, Mark, Exercises, RGZ):" << endl;
	cin >> index >> name >> mark >> exercises >> rgz;
	ss << index<<" " << name<<" " << mark<<" " << exercises<<" " << rgz;
	return ss;
}

Task List::StringToObject(stringstream ss) {
	Task add;
	int index, mark, rgz, exercises;
	string name;
	ss >> index >> name >> mark >> exercises >> rgz;
	add.setStudentIndex(index);
	add.setName(name);
	add.setMark(mark);
	add.setCountOfDoneExercises(exercises);
	add.setRgz(rgz);
	return add;
}