#include "List.h"
#include "Task.h"

int List::getList_size() const { return list_size; }
void List::setList_size(int size) { list_size = size; }

void List::Add_student(const Task task)
{
	setList_size(getList_size() + 1);
	Task* newstud = new Task[list_size];
	for (int i = 0; list_size > i; i++)
		newstud[i] = stud[i];
	newstud[list_size - 1] = task;
	newstud[list_size - 1].setStudent_index(stud[list_size - 2].getStudent_index() + 1);
	delete[] stud;
	stud = new Task[list_size];
	for (int i = 0; list_size > i; i++)
		stud[i] = newstud[i];
	delete[] newstud;
}
void List::Create_list()
{
	stud = new Task[list_size];
	for (int i = 0; list_size > i; i++)
	{
		stud[i] = Create_student();
		stud[i].setStudent_index(i + 1);
	}
}
void List::Delete_student(int c)
{
	setList_size(getList_size() - 1);
	Task* newstud = new Task[list_size];
	int i = 0;
	for (; i < getList_size(); i++)
	{
		if (stud[i].getStudent_index() == c)
			break;
		newstud[i] = stud[i];
	}
	for (; i < getList_size(); i++)
		newstud[i] = stud[i + 1];
	delete[] stud;
	stud = new Task[list_size];
	for (int i = 0; i < getList_size(); i++)
		stud[i] = newstud[i];
	delete[] newstud;
}
void List::Print_one_student(int number) const
{
	cout << "Index\t";
	cout << "Mark\t";
	cout << "Exercises\t";
	cout << "RGZ\t";
	cout << "Male/Female" << endl;
	printf("%-10d", stud[number].getStudent_index());
	printf("%-10d", stud[number].getMark());
	printf("%-13d", stud[number].getCount_of_done_exercises());
	printf("%-10d", stud[number].getRgz());
	printf("%s", stud[number].getMale_or_female());
}
void List::Print_all() const
{
	cout << "Index\t";
	cout << "Mark\t";
	cout << "Exercises\t";
	cout << "RGZ\t";
	cout << "Male/Female";
	for (int i = 0; List::getList_size() > i; i++)
	{
		cout << endl;
		printf("%-10d", stud[i].getStudent_index());
		printf("%-10d", stud[i].getMark());
		printf("%-13d", stud[i].getCount_of_done_exercises());
		printf("%-10d", stud[i].getRgz());
		printf("%s", stud[i].getMale_or_female());
	}
}
List::~List()
{
	cout << "Destructor" << endl;
	delete[] stud;
}

void List::Get_student_ID(int id) const
{
	for (int i = 0; i < list_size; i++)
		if (stud[i].getStudent_index() == id)
		{
			Print_one_student(i);
			return;
		}
	cout << "Wrong ID" << endl;
}