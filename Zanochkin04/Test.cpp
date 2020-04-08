#include "List.h"
#include "Task.h"

int TestAddStudent(List&, int);
int TestDeleteStudent(List&, int);
int TestGetStudentID(List&, int);
int TestReadFile(List&, int);

int main()
{
	{
		List test;
		int count = 0;
		test.setListSize(2);
		test.createList();

		count = TestAddStudent(test, count);
		count = TestDeleteStudent(test, count);
		count = TestGetStudentID(test, count);
		count = TestReadFile(test, count);

		if (count == 4)
			cout << endl << "All tests are successful" << endl;
		else
			cout << endl << "Not all tests are successful" << endl;

	}
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
	return 0;
}

int TestAddStudent(List& test, int count)
{
	test.addStudent(CreateStudent2());
	if (test.getListSize() == 3)
	{
		cout << endl << "Test: Add_student - successful" << endl;
		count++;
	}
	else
		cout << endl << "Test: Add_student - unsuccessful" << endl;
	return count;
}

int TestDeleteStudent(List& test, int count)
{
	test.deleteStudent(test.getListSize());
	if (test.getListSize() == 2)
	{
		cout << endl << "Test: Delete_student - successful" << endl;
		count++;
	}
	else
		cout << endl << "Test: Delete_student - unsuccessful" << endl;
	return count;
}

int TestGetStudentID(List& test, int count)
{
	int num = test.getStudentID(2);
	if (num == 1)
	{
		cout << endl << "Test: GetStudentId - successful" << endl;
		count++;
	}
	else
		cout << endl << "Test: GetStudentId - unsuccessful" << endl;
	return count;
}

int TestReadFile(List& test, int count)
{
	string filename = "Text.txt";
	int a = 3;
	test.ReadFile(filename,a);

	string expected = "Ivanov Vasya";
	string real = test.stud[0].getName();

	if (expected == real)
	{
		cout << endl << "Test: Readfile - successful" << endl;
		count++;
	}
	else
		cout << endl << "Test: Readfile - unsuccessful" << endl;
	return count;
}