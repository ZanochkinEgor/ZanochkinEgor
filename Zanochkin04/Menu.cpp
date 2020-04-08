#include "Task.h"
#include "List.h"

void Menu()
{
	List list;
	int c = 0, a = 0, b = 0;
	int count_of_students = 2;
	int menu_number = 1;
	int delete_number;
	string fileName;
	stringstream ss;
	Task var;
	int file;
	list.setListSize(count_of_students);
	list.createList();
	while (menu_number)
	{
		menu_number = 0;
		cout << endl << "Menu:" << endl;
		cout << "1.Add a new student" << endl;
		cout << "2.Add a new student (enter from keyboard)" << endl;
		cout << "3.Delete one student" << endl;
		cout << "4.Show all student" << endl;
		cout << "5.Show student via his index" << endl;
		cout << "6.Individual task" << endl;
		cout << "7.Read array from file" << endl;
		cout << "8.Write to file" << endl;
		cout << "9.Surname+Name in object" << endl;
		cout << "10.End program" << endl;
		cin >> menu_number;
		switch (menu_number)
		{
		case 1:
			var = CreateStudent2();
			list.addStudent(var);
			break;
		case 2:
			//list.addStudent(list.StringToObject(list.DataToString()));
			list.addStudent(list.enterNewStudent());
			break;
		case 3:
			cout << "Enter a index of student who you want to delete:" << endl;
			cin >> delete_number;
			if (delete_number < 1)
			{
				cout << "Wrong student index" << endl;
				break;
			}
			for (int i = 0; list.getListSize() > i; i++)
				if (delete_number == list.stud[i].getStudentIndex())
				{
					list.deleteStudent(delete_number);
					break;
				}
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
			ss = list.getObj(b);
			list.printOneStudent(ss);
			break;
		case 6:
			cout << "Enter a count of RGZ";
			cin >> a;
			b = list.getStudentRGZ(a);
			if (b == -1)
				break;
			ss = list.getObj(b);
			list.printOneStudent(ss);
			break;
		case 7:
			cout << "Enter file name:";
			cin >> fileName;
			list.ReadFile(fileName, list.FileString(fileName));
			break;
		case 8:
			cout << "Enter file name:";
			cin >> fileName;
			list.WriteFile(fileName);
			break;
		case 9:
			list.regexTask();
			break;
		case 10:
			menu_number = 0;
			break;
		default:
			cout << "You have chosen the wrong number of the menu";
			break;
		}
	}
	return;
}