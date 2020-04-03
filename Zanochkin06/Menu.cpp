#include "Task.h"
#include "List.h"
#include "InherList.h"
#include "InherTask.h"

void Menu()
{
	List list;
	InheritorList list1;
	Student age;
	int c = 0, a = 0, b = 0, value = 0;
	////////////////////
	auto count_of_students = 1;
	//Плюсы auto: В зависимости от введеных данных переменная может менять свой тип. Например, былa int, а после некоторых изменений стала double.
	////////////////////
	int menu_number = 1;
	int delete_number;
	string fileName;
	stringstream ss,ss1;
	Task var, add;
	Inheritor var1, add1;
	int file;
	int* studentAge;
	list.setListSize(count_of_students);
	list1.setListSize(count_of_students);
	studentAge = age.createList(count_of_students);
	list.createList();
	list1.createList();
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
		cout << "7.Read array from file" << endl;
		cout << "8.Write to file" << endl;
		cout << "9.Surname+Name in object" << endl;
		cout << "10.Sort (mark)" << endl;
		cout << "11.End program" << endl;
		cin >> menu_number;
		switch (menu_number)
		{
		case 1:
			var = CreateStudent2();
			list.addStudent(var);
			var1 = InherCreateStudent2();
			list1.addStudent(var1);
			break;
		case 2:
			add = list.StringToObject(list.DataToString());
			list.addStudent(add);
			add1 = list1.StringToObject(list1.DataToString());
			list1.addStudent(add1);
			break;
		case 3:
			cout << "Enter a index of student who you want to delete:" << endl;
			cin >> delete_number;
			if (delete_number < 1)
			{
				cout << "Wrong student index" << endl;
				break;
			}
			for (size_t i = 0; list.getListSize() > i; i++)
				if (delete_number == list.stud[i].getStudentIndex())
				{
					list.deleteStudent(delete_number);
					list1.deleteStudent(delete_number);
					break;
				}
			break;
		case 4:
			cout << "Base class" << endl << endl;
			list.printAll();
			cout << endl << "Inheritor class" << endl << endl;
			list1.printAll();
			break;
		case 5:
			cout << "Enter a index of student:";
			cin >> c;
			b = list.getStudentID(c);
			if (b == -1)
				break;
			ss = list.getObj(b);
			ss1 = list1.getObj(b);
			cout << "Base class" << endl << endl;
			list.printOneStudent(ss);
			cout << endl << "Inheritor class" << endl << endl;
			list1.printOneStudent(ss1);
			break;
		case 6:
			cout << "Enter a count of RGZ:";
			cin >> a;
			b = list.getStudentRGZ(a);
			if (b == -1)
				break;
			ss = list.getObj(b);
			ss1 = list1.getObj(b);
			cout << "Base class" << endl << endl;
			list.printOneStudent(ss);
			cout << endl << "Inheritor class" << endl << endl;
			list1.printOneStudent(ss1);
			break;
		case 7:
			cout << "Enter file name for base class:";
			cin >> fileName;
			list.ReadFile(fileName, list.FileString(fileName));
			cout << "Enter file name for inheritor class:";
			cin >> fileName;
			list1.ReadFile(fileName, list1.FileString(fileName));
			break;
		case 8:
			cout << "Enter file name:";
			cin >> fileName;
			list.WriteFile(fileName);
			list1.WriteFile(fileName);
			break;
		case 9:
			cout << "Base class" << endl << endl;
			list.regexTask();
			cout << endl << "Inheritor class" << endl << endl;
			list1.regexTask();
			break;
		case 10:
			cout << "1) Increasing" << endl;
			cout << "2) Decreasing" << endl;
			cin >> value;
			cout << endl;
			if (value == 1)
			{
				list.sort(list.sortAsc);
				list1.sort(list1.sortAsc);
			}
			else if (value == 2)
			{
				list.sort(list.sortDesc);
				list1.sort(list1.sortDesc);
			}
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