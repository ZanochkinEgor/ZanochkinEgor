#include "List.h"
#include "Task.h"

void TestAddStudent(List&, Student*);
void TestDeleteStudent(List&);
void TestGetStudentID(List&);
void TestReadFile(List&);
void TestSort(List&);

int main()
{
	{
		List test;
		Student age;
		Student* studentAge;
		studentAge = age.createList(2);
		test.createList(2, studentAge);

		TestAddStudent(test, studentAge);
		TestDeleteStudent(test);
		TestGetStudentID(test);
		TestReadFile(test);
		TestSort(test);
		age.deleteList();
	}
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
	return 0;
}

void TestAddStudent(List& test, Student* age)
{
	int value = test.getListSize();
	Task* newStudent = test.newStudent(age, 1);
	test.addStudent(newStudent);
	if (test.getListSize() > value)
		cout << endl << "Test: Add_student - successful" << endl;
	else
		cout << endl << "Test: Add_student - unsuccessful" << endl;
}

void TestDeleteStudent(List& test)
{
	int size = test.getListSize();
	test.deleteStudent(2);
	int newSize = test.getListSize();
	if (size > newSize)
		cout << endl << "Test: Delete_student - successful" << endl;
	else
		cout << endl << "Test: Delete_student - unsuccessful" << endl;
}

void TestGetStudentID(List& test)
{
	int num = test.getStudentID(2);
	if (num == 1)
		cout << endl << "Test: GetStudentId - successful" << endl;
	else
		cout << endl << "Test: GetStudentId - unsuccessful" << endl;
}

void TestReadFile(List& test)
{
	int expected = 4;
	int real = test.fileString("Text.txt");
	if (expected == real)
		cout << endl << "Test: ReadFile - successful" << endl;
	else
		cout << endl << "Test: ReadFile - unsuccessful" << endl;
}

void TestSort(List& test)
{
	int beforeSorting = test[0]->getMark();
	test.sort(test.sortDesc);
	int afterSorting = test[0]->getMark();
	int expected = 5;

	if (beforeSorting != afterSorting && afterSorting == expected)
		cout << endl << "Test: Sort - successful" << endl;
	else
		cout << endl << "Test: Sort - unsuccessful" << endl;
}