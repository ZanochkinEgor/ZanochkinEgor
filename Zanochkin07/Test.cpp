#include "List.h"
#include "Task.h"

Task** TestAddStudent(List&, Student*, Task**);
Task** TestDeleteStudent(List&, Task**);
void TestGetStudentID(List&, Task**);
void TestReadFile(List&, Task**);
void TestSort(List&, Task**);

int main()
{
	{
		List test;
		Student age;
		Student* studentAge;
		Task** studentList;
		studentAge = age.createList(2);
		studentList = test.createList(2, studentAge);

		studentList = TestAddStudent(test, studentAge, studentList);
		studentList = TestDeleteStudent(test, studentList);
		TestGetStudentID(test, studentList);
		TestReadFile(test, studentList);
		TestSort(test, studentList);
		age.deleteList();
	}
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
	return 0;
}

Task** TestAddStudent(List& test, Student* age, Task** stud)
{
	int value = test.getListSize();
	Task* newStudent = test.newStudent(age, 1);
	stud = test.addStudent(newStudent, stud);
	if (test.getListSize() > value)
		cout << endl << "Test: Add_student - successful" << endl;
	else
		cout << endl << "Test: Add_student - unsuccessful" << endl;
	return stud;
}

Task** TestDeleteStudent(List& test, Task** stud)
{
	int size = test.getListSize();
	stud = test.deleteStudent(2, stud);
	int newSize = test.getListSize();
	if (size > newSize)
		cout << endl << "Test: Delete_student - successful" << endl;
	else
		cout << endl << "Test: Delete_student - unsuccessful" << endl;
	return stud;
}

void TestGetStudentID(List& test, Task** stud)
{
	int num = test.getStudentID(2, stud);
	if (num == 1)
		cout << endl << "Test: GetStudentId - successful" << endl;
	else
		cout << endl << "Test: GetStudentId - unsuccessful" << endl;
}

void TestReadFile(List& test, Task** stud)
{
	int expected = 4;
	int real = test.FileString("Text.txt");
	if (expected == real)
		cout << endl << "Test: ReadFile - successful" << endl;
	else
		cout << endl << "Test: ReadFile - unsuccessful" << endl;
}

void TestSort(List& test, Task** stud)
{
	int beforeSorting = stud[0]->getMark();
	test.sort(test.sortDesc);
	int afterSorting = stud[0]->getMark();
	int expected = 5;

	if (beforeSorting != afterSorting && afterSorting == expected) 
		cout << endl << "Test: Sort - successful" << endl;
	else
		cout << endl << "Test: Sort - unsuccessful" << endl;

}