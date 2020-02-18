#include "Task.h"
#include "List.h"

int Task::getMark() const { return mark; }
void Task::setMark(int mark1) { Task::mark = mark1; }

int Task::getCount_of_done_exercises() const { return count_of_done_exercises; }
void Task::setCount_of_done_exercises(int count_of_done_exercises1) { Task::count_of_done_exercises = count_of_done_exercises1; }

int Task::getVariant() const { return variant; }
void Task::setVariant(int exercises1) { Task::variant = exercises1; }

void Menu() {
	List list;
	int a = 0;
	int c = 0;
	int count_of_students = 2;
	int menu_number = 1;
	int delete_number;
	list.setList_size(count_of_students);
	list.Create_list();
	while (menu_number) {
		menu_number = 0;
		cout << endl << "Menu:" << endl;
		cout << "1.Add a new student" << endl;
		cout << "2.Delete one student" << endl;
		cout << "3.Show all student" << endl;
		cout << "4.Show student via his number" << endl;
		cout << "5.End program" << endl;
		cin >> menu_number;
		switch (menu_number) {
		case 1:
			list.Add_student();
			break;
		case 2:
			cout << "Enter a number of student who you want to delete:" << endl;
			cin >> delete_number;
			list.Delete_student(delete_number);
			break;
		case 3:
			list.Print_all();
			break;
		case 4:
			cout << "Enter a number of student:";
			cin >> c;
			if (c <= list.getList_size()) {
				list.Print_one_student(c);
			}
			else {
				cout<<"You have chosen the wrong number of student";
			}
			break;
		case 5:
			list.Free_memory();
			return;
		default:
			cout<<"You have chosen the wrong number of the menu";
			break;
		}
	}
}