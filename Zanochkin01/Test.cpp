#include "List.h"
#include "Task.h"

void Test_Add_student(List, int);
void Test_Delete_student(List, int);

int main()
{
	List stud;
	int count = 0;
	stud.setList_size(2);
	stud.Create_list();

	Test_Add_student(stud, count);
	//Test_Delete_student(stud, count);

	if (count == 2)
		cout << "All tests are succesful";
	else
		cout << "Not all tests are succesful";

	stud.Free_memory();
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
	return 0;
}

void Test_Add_student(List stud, int count)
{
	stud.Add_student();
	if (stud.getList_size() == 3)
	{
		cout << "Test 1 is succesful";
		count++;
	}
	else
		cout << "Test 1 is unsuccesful";
}

void Test_Delete_student(List stud, int count)
{
	stud.Delete_student(stud.getList_size());
	if (stud.getList_size() == 1)
	{
		cout << "Test 2 is succesful";
		count++;
	}
	else
		cout << "Test 2 is unsuccesful";
}