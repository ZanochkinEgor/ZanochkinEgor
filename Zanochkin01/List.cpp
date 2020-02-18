#include "List.h"
#include "Task.h"

int List::getList_size() const { return list_size; }
void List::setList_size(int size) { list_size = size; }

Task List::Create_student() {
	Task stud;
	stud.setMark(5);
	stud.setCount_of_done_exercises(5);
	stud.setVariant(1);
	return stud;
}
Task List::Create_student2() {
	Task stud;
	stud.setMark(2);
	stud.setCount_of_done_exercises(2);
	stud.setVariant(2);
	return stud;
}
void List::Add_student() {
	setList_size(getList_size() + 1);
	Task* newstud = new Task[list_size];
	for (int i = 0; list_size > i; i++)
		newstud[i] = stud[i];
	newstud[list_size - 1] = List::Create_student2();
	delete[] stud;
	stud = new Task[list_size];
	for (int i = 0; list_size > i; i++)
		stud[i] = newstud[i];
	delete[] newstud;
}
void List::Create_list() {
	stud = new Task[list_size];
	for (int i = 0; list_size > i; i++)
		stud[i] = List::Create_student();
}
void List::Delete_student(int c) {
	setList_size(getList_size() - 1);
	Task* newstud = new Task[list_size];
	int i = 0;
	for (; i < getList_size(); i++)
		newstud[i] = stud[i];
	for (; i < getList_size(); i++)
		newstud[i] = stud[i + 1];
	delete[] stud;
	stud = new Task[list_size];
	for (int i = 0; i < getList_size(); i++)
		stud[i] = newstud[i];
	delete[] newstud;
}
void List::Print_one_el(int c) const {
	cout << "Number\t";
	cout << "Variant\t";
	cout << "Mark\t";
	cout << "Exercises" << endl;
	printf("%-11d", c);
	printf("%-8d", stud[c-1].getVariant());
	printf(" %-12d", stud[c-1].getMark());
	printf("%d", stud[c-1].getCount_of_done_exercises());
}
void List::Print_all() const {
	cout << "Number\t";
	cout << "Variant\t";
	cout << "Mark\t";
	cout << "Exercises";
	for (int i = 0; List::getList_size() > i; i++) 
	{
		cout << endl;
		printf("%-11d", i+1);
		printf("%-6d", stud[i].getVariant());
		printf("%-12d", stud[i].getMark());
		printf("%d", stud[i].getCount_of_done_exercises());
	}
}
void List::Free_memory() {
	delete[] stud;
}