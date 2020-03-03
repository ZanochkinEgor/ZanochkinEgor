#include "Task.h"
#include "List.h"

void Menu()
{
	List list;
	int c = 0, a = 0;
	int count_of_students = 2;
	int menu_number = 1;
	int delete_number;
	list.setListSize(count_of_students);
	list.createList();
	while (menu_number)
	{
		menu_number = 0;
		cout << endl << "Menu:" << endl;
		cout << "1.Add a new student" << endl;
		cout << "2.Delete one student" << endl;
		cout << "3.Show all student" << endl;
		cout << "4.Show student via his index" << endl;
		cout << "5.End program" << endl;
		cout << "6.Individual task" << endl;
		cin >> menu_number;
		switch (menu_number)
		{
		case 1:
			list.addStudent(Create_student2());
			break;
		case 2:
			cout << "Enter a index of student who you want to delete:" << endl;
			cin >> delete_number;
			if (delete_number < 1) {
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
		case 3:
			list.printAll();
			break;
		case 4:
			cout << "Enter a index of student:";
			cin >> c;
			list.getStudentID(c);
			break;
		case 5:
			menu_number = 0;
			break;
		case 6:
			cout << "Enter a count of RGZ";
			cin >> a;
			list.getStudentRGZ(a);
			break;
		default:
			cout << "You have chosen the wrong number of the menu";
			break;
		}
	}
	return;
}