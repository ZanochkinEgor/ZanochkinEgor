#include "List.h"
#include "Task.h"

int Test_Add_student(List&, int);
int Test_Delete_student(List&, int);

int main()
{
	List test;
	int count = 0;
	test.setList_size(2);
	test.Create_list();

	count = Test_Add_student(test, count);
	count = Test_Delete_student(test, count);

	if (count == 2)
		cout << "All tests are successful" << endl;
	else
		cout << "Not all tests are successful" << endl;

	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
	return 0;
}

int Test_Add_student(List& test, int count)
{
	test.Add_student(Create_student2());
	if (test.getList_size() == 3)
	{
		cout << "Test: Add_student - successful" << endl;
		count++;
	}
	else
		cout << "Test: Add_student - unsuccessful" << endl;
	return count;
}

int Test_Delete_student(List& test, int count)
{
	test.Delete_student(test.getList_size());
	if (test.getList_size() == 2)
	{
		cout << "Test: Delete_student - successful" << endl;
		count++;
	}
	else
		cout << "Test: Delete_student - unsuccessful" << endl;
	return count;
}