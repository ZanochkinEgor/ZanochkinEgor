#include "Task.h"
#include "List.h"
#include "Inheritor1.h"
#include "Inheritor2.h"

void Menu()
{
	List list;
	Student age;
	auto c = 0, a = 0, b = 0, value = 0, addNum = 0, count = 0;
	auto count_of_students = 2;
	auto menu_number = 1;
	auto delete_number = 0;
	string fileName;
	stringstream ss;
	int del;
	Student* studentAge;
	studentAge = age.createList(count_of_students);
	list.createList(count_of_students, studentAge);
	while (menu_number)
	{
		menu_number = 0;
		cout << endl << "Menu:" << endl;
		cout << "1.Add a new student" << endl;
		cout << "2.Add a new student (enter from keyboard)" << endl;
		cout << "3.Delete one student" << endl;
		cout << "4.Show all student" << endl;
		cout << "5.Show student via his index" << endl;
		cout << "6.Show student via his count of RGZ" << endl;
		cout << "7.Read list from file" << endl;
		cout << "8.Write to file" << endl;
		cout << "9.Surname+Name in object" << endl;
		cout << "10.Sort (mark)" << endl;
		cout << "11.End program" << endl;
		cin >> menu_number;
		switch (menu_number)
		{
		case 1:
			cout << "1. Add student with rgz for teacher parameter" << endl;
			cout << "2. Add student with gender parameter" << endl;
			cin >> addNum;
			cout << endl;

			if (addNum == 1)
			{
				Task* newStudent = list.newStudent(studentAge, 1);
				list.addStudent(newStudent);
				cout << "Add student - done" << endl;
				break;
			}
			else if (addNum == 2)
			{
				Task* newStudent = list.newStudent(studentAge, 2);
				list.addStudent(newStudent);
				cout << "Add student - done" << endl;
			}
			else
				cout << "Wtong number" << endl;
			break;
		case 2:
			list.enterNewStudent();
			break;
		case 3:
			cout << "Enter a index of student who you want to delete:" << endl;
			cin >> delete_number;
			if (delete_number < 1)
			{
				cout << "Wrong student index" << endl;
				break;
			}
			del = list.getStudentID(delete_number);
			if (del == -1)
			{
				break;
			}
			list.deleteStudent(del);
			cout << "Delete student - done" << endl;
			break;
		case 4:
			list.printAll();
			break;
		case 5:
			cout << "Enter a index of student:";
			cin >> c;
			b = list.getStudentID(c);
			if (b == -1)
				break;
			list.printOneStudent(b);
			break;
		case 6:
			cout << "Enter a count of RGZ:";
			cin >> a;
			b = list.getStudentRGZ(a);
			if (b == -1)
				break;
			list.printOneStudent(b);
			break;
		case 7:
			cout << "Enter file name:";
			cin >> fileName;
			list.readFile(fileName);
			break;
		case 8:
			cout << "Enter file name:";
			cin >> fileName;
			list.writeFile(fileName);
			break;
		case 9:
			count = list.regexTask();
			if (count == 0)
				cout << "There is no students with Name and Surname" << endl;
			break;
		case 10:
			cout << "1) Increasing" << endl;
			cout << "2) Decreasing" << endl;
			cin >> value;
			cout << endl;
			if (value == 1)
				list.sort(list.sortAsc);
			else if (value == 2)
				list.sort(list.sortDesc);
			else cout << "Wrong number." << endl;
			break;
		case 11:
			menu_number = 0;
			break;
		default:
			cout << "You have chosen the wrong number of the menu";
			break;
		}
	}
	age.deleteList();
	return;
}