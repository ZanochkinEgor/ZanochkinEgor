#include "List.h"
#include "Task.h"

int List::getListSize() const { return listSize; }
void List::setListSize(int size) { listSize = size; }

void List::addStudent(const Task task)
{
	setListSize(getListSize() + 1);
	Task* newstud = new Task[listSize];
	for (int i = 0; listSize > i; i++)
		newstud[i] = stud[i];
	newstud[listSize - 1] = task;
	newstud[listSize - 1].setStudentIndex(stud[listSize - 2].getStudentIndex() + 1);
	newstud[listSize - 1].setRgz(stud[listSize - 2].getRgz() + 1);
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
		stud[i] = Create_student();
		stud[i].setStudentIndex(i + 1);
		stud[i].setRgz(i + 1);
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
void List::printOneStudent(int number) const
{
	cout << "Index\t";
	cout << "Mark\t";
	cout << "Exercises\t";
	cout << "RGZ\t";
	cout << "Male/Female" << endl;
	printf("%-10d", stud[number].getStudentIndex());
	printf("%-10d", stud[number].getMark());
	printf("%-13d", stud[number].getCountOfDoneExercises());
	printf("%-10d", stud[number].getRgz());
	printf("%s", stud[number].getMaleOrFemale());
}
void List::printAll() const
{
	cout << "Index\t";
	cout << "Mark\t";
	cout << "Exercises\t";
	cout << "RGZ\t";
	cout << "Male/Female";
	for (int i = 0; List::getListSize() > i; i++)
	{
		cout << endl;
		printf("%-10d", stud[i].getStudentIndex());
		printf("%-10d", stud[i].getMark());
		printf("%-13d", stud[i].getCountOfDoneExercises());
		printf("%-10d", stud[i].getRgz());
		printf("%s", stud[i].getMaleOrFemale());
	}
}
List::~List()
{
	cout << "Destructor List" << endl;
	delete[] stud;
}

void List::getStudentID(int id) const
{
	for (int i = 0; i < listSize; i++)
		if (stud[i].getStudentIndex() == id)
		{
			printOneStudent(i);
			return;
		}
	cout << "Wrong ID" << endl;
}

void List::getStudentRGZ(int a) const
{
	for (int i = 0; i < listSize; i++)
		if (stud[i].getRgz() == a)
		{
			printOneStudent(i);
			return;
		}
	cout << "Wrong count of RGZ" << endl;
}