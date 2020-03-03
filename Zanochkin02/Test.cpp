#include "List.h"
#include "Task.h"

int TestAddStudent(List&, int);
int TestDeleteStudent(List&, int);

int main()
{
	{
		List test;
		int count = 0;
		test.setListSize(2);
		test.createList();

		count = TestAddStudent(test, count);
		count = TestDeleteStudent(test, count);

		if (count == 2)
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
	test.addStudent(Create_student2());
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