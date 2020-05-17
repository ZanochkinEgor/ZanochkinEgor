#include "Inheritor.h"
#include "Task.h"

void Menu()
{
	int menuNumber = 1;
	while (menuNumber)
	{
		menuNumber = 0;
		cout << "Select STL-container: " << endl;
		cout << "1. Vector" << endl;
		cout << "2. Set" << endl;
		cout << "3. List" << endl;
		cout << "4. Map" << endl;
		cout << "5. Exit" << endl;
		cin >> menuNumber;
		cout << endl;
		switch (menuNumber)
		{
		case 1:
			vectorMenu();
			cout << endl;
			break;
		case 2:
			setMenu();
			cout << endl;
			break;
		case 3:
		{
			listMenu();
			cout << endl;
			break;
		}
		case 4:
		{
			mapMenu();
			cout << endl;
			break;
		}
		case 5:
			menuNumber = 0;
			break;
		default:
			cout << "Wrong command" << endl << endl;
			break;
		}
	}
}

Task* newStudent(int i)
{
	if (i % 2 != 0)
	{
		Task* stud = new Inheritor(generateID(), "Vasya", 2, 5, generateRGZ(), generateRgzForTeacher());
		return stud;
	}
	if (i % 2 == 0)
	{
		Task* stud = new Inheritor(generateID(), "Katya", 5, 10, generateRGZ(), generateRgzForTeacher());
		return stud;
	}
}

void vectorMenu()
{
	int menuNum = 1;
	int num = 0;
	int add = 1;
	vector<unique_ptr<Task>> vec;
	vector<unique_ptr<Task>>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0)
			vec.emplace_back(new Inheritor());
		else if (i == 1)
			vec.emplace_back(new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	while (menuNum)
	{
		menuNum = 0;
		cout << "VECTOR" << endl;
		cout << "1. Print all students" << endl;
		cout << "2. Add one student" << endl;
		cout << "3. Get one student" << endl;
		cout << "4. Delete one student" << endl;
		cout << "5. Amount of elements per criterion" << endl;
		cout << "6. Find element per criterium" << endl;
		cout << "7. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(vec.begin(), vec.end(), [](const unique_ptr<Task>& object) 
				{
				cout << *object << endl;
				});
			cout << endl;
			break;
		case 2:
			try
			{
				vec.emplace_back(newStudent(add++));
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(vec.begin(), vec.end(), [](const unique_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl;
			}
			catch (const std::exception& ex)
			{
				cout << endl << ex.what() << endl << endl;
			}
			break;
		case 3:
		{
			cout << "Enter index of student to get: ";
			cin >> num;
			cout << endl;
			int el = -1;
			bool check = false;
			for (const auto& object : vec)
			{
				if (object->getStudentIndex() == num)
				{
					el++;
					check = true;
					break;
				}
				else
					el++;
			}
			if (check)
			{
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				cout << *vec[el] << endl << endl;
			}
			else
				cout << "Wrong id" << endl << endl;
			break;
		}
		case 4:
		{
			cout << "Enter index of student to delete: ";
			cin >> num;
			int el = -1;
			bool check = false;
			for (const auto& object : vec)
			{
				if (object->getStudentIndex() == num)
				{
					el++;
					check = true;
					break;
				}
				else
					el++;
			}
			if (check)
			{
				it = vec.begin() + el;
				vec.erase(it);
				cout << endl;
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(vec.begin(), vec.end(), [](const unique_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl << "Delete successful" << endl << endl;
			}
			else
				cout << "Wrong id" << endl << endl;
			break;
		}
		case 5:
		{
			int amountOfElements = 0;
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = vec.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			while (result != -1 && i < vec.size())
			{
				result = (*it)->amountElementsPerCriterium(var, data);
				if (result == -1)
					break;
				i++;
				it++;
				amountOfElements += result;
			}
			if (result != -1)
				cout << endl << "Amount of elements with selected field: " << amountOfElements << endl << endl;
			break;
		}
		case 6:
		{
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = vec.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data which will be used as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			cout << endl;
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			while (result != 1 && result != -1 && i < vec.size())
			{
				result = (*it)->findElementPerCriterium(var, data);
				if (result == 1)
					break;
				i++;
				it++;
			}
			if (result == 0)
				cout << "There is no element with that criterium" << endl << endl;
			break;
		}
		case 7:
			menuNum = 0;
			break;
		default:
			cout << "Wrong command, try something else" << endl << endl;
			break;
		}
	}
	return;
}

void setMenu()
{
	int menuNum = 1;
	int num = 0;
	int add = 1;
	set <unique_ptr<Task>> Set;
	set <unique_ptr<Task>>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0)
			Set.emplace(new Inheritor());
		else if (i == 1)
			Set.emplace(new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	while (menuNum)
	{
		menuNum = 0;
		cout << "SET" << endl;
		cout << "1. Print all students" << endl;
		cout << "2. Add one student" << endl;
		cout << "3. Get one student" << endl;
		cout << "4. Delete one student" << endl;
		cout << "5. Amount of elements per criterion" << endl;
		cout << "6. Find element per criterium" << endl;
		cout << "7. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(Set.begin(), Set.end(), [](const unique_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 2:
			Set.emplace(newStudent(add++));
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(Set.begin(), Set.end(), [](const unique_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 3:
		{
			cout << "Enter index of student to get: ";
			cin >> num;
			cout << endl;
			int el = -1;
			bool check = false;
			for (const auto& object : Set)
			{
				if (object->getStudentIndex() == num)
				{
					el++;
					check = true;
					break;
				}
				else
					el++;
			}
			if (check)
			{
				it = Set.begin();
				advance(it, el);
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				cout << **it << endl << endl;
			}
			else
				cout << "Wrong id" << endl << endl;
			break;
		}
		case 4:
		{
			bool check = false;
			cout << "Enter index of student to delete: " << endl;
			cin >> num;
			int el = -1;
			for (const auto& object : Set)
			{
				if (object->getStudentIndex() == num)
				{
					el++;
					check = true;
					break;
				}
				else
					el++;
			}
			if (check)
			{
				it = Set.begin();
				advance(it, el);
				Set.erase(it);
				cout << endl;
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(Set.begin(), Set.end(), [](const unique_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl << "Delete successful" << endl << endl;
			}
			else
				cout << "Wrong id" << endl << endl;
			break;
		}
		case 5:
		{
			int amountOfElements = 0;
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = Set.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			while (result != -1 && i < Set.size())
			{
				result = (*it)->amountElementsPerCriterium(var, data);
				if (result == -1)
					break;
				i++;
				it++;
				amountOfElements += result;
			}
			if (result != -1)
				cout << endl << "Amount of elements with selected field: " << amountOfElements << endl << endl;
			break;
		}
		case 6:
		{
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = Set.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data which will be used as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			cout << endl;
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			while (result != 1 && result != -1 && i < Set.size())
			{
				result = (*it)->findElementPerCriterium(var, data);
				if (result == 1)
					break;
				i++;
				it++;
			}
			if (result == 0)
				cout << "There is no element with that criterium" << endl << endl;
			break;
		}
		case 7:
			menuNum = 0;
			break;
		default:
			cout << "Wrong command, try something else" << endl << endl;
			break;
		}
	}
	return;
}

void listMenu()
{
	int menuNum = 1;
	int add = 1;
	int num = 0;
	list <unique_ptr<Task>> List;
	list <unique_ptr<Task>>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0)
			List.emplace_front(new Inheritor());
		else if (i == 1)
			List.emplace_front(new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	while (menuNum)
	{
		menuNum = 0;
		cout << "LIST" << endl;
		cout << "1. Print all students" << endl;
		cout << "2. Add one student" << endl;
		cout << "3. Get one student" << endl;
		cout << "4. Delete one student" << endl;
		cout << "5. Amount of elements per criterion" << endl;
		cout << "6. Find element per criterium" << endl;
		cout << "7. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(List.begin(), List.end(), [](const unique_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 2:
			List.emplace_front(newStudent(add++));
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(List.begin(), List.end(), [](const unique_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 3:
		{
			cout << "Enter index of student to get:";
			cin >> num;
			cout << endl;
			bool check = false;
			int el = -1;
			for (const auto& object : List)
			{
				if (object->getStudentIndex() == num)
				{
					el++;
					check = true;
					break;
				}
				else
					el++;
			}
			if (check)
			{
				it = List.begin();
				advance(it, el);
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				cout << **it << endl << endl;
			}
			else
				cout << "Wrong id" << endl << endl;
			break;
		}
		case 4:
		{
			cout << "Enter index of student to delete: " << endl;
			cin >> num;
			bool check = false;
			int el = -1;
			for (const auto& object : List)
			{
				if (object->getStudentIndex() == num)
				{
					el++;
					check = true;
					break;
				}
				else
					el++;
			}
			if (check)
			{
				it = List.begin();
				advance(it, el);
				List.erase(it);
				cout << endl;
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(List.begin(), List.end(), [](const unique_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl << "Delete successful" << endl << endl;
			}
			else
				cout << "Wrong id" << endl << endl;
			break;
		}
		case 5:
		{
			int amountOfElements = 0;
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = List.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			while (result != -1 && i < List.size())
			{
				result = (*it)->amountElementsPerCriterium(var, data);
				if (result == -1)
					break;
				i++;
				it++;
				amountOfElements += result;
			}
			if (result != -1)
				cout << endl << "Amount of elements with selected field: " << amountOfElements << endl << endl;
			break;
		}
		case 6:
		{
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = List.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data which will be used as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			cout << endl;
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			while (result != 1 && result != -1 && i < List.size())
			{
				result = (*it)->findElementPerCriterium(var, data);
				if (result == 1)
					break;
				i++;
				it++;
			}
			if (result == 0)
				cout << "There is no element with that criterium" << endl << endl;
			break;
		}
		case 7:
			menuNum = 0;
			break;
		default:
			cout << "Wrong command, try something else" << endl;
			break;
		}
	}
	return;
}

void mapMenu()
{
	int menuNum = 1;
	int num = 0;
	int add = 1;
	int i = 0;
	map <int, unique_ptr<Task>> Map;
	map <int, unique_ptr<Task>>::iterator it;
	for (; i < 2; i++)
	{
		if (i == 0)
			Map.emplace(i + 1, new Inheritor());
		else if (i == 1)
			Map.emplace(i + 1, new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	while (menuNum)
	{
		menuNum = 0;
		cout << "MAP" << endl;
		cout << "1. Print all students" << endl;
		cout << "2. Add one student" << endl;
		cout << "3. Get one student" << endl;
		cout << "4. Delete one student" << endl;
		cout << "5. Amount of elements per criterion" << endl;
		cout << "6. Find element per criterium" << endl;
		cout << "7. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(5) << "Key" << endl;
			for_each(Map.begin(), Map.end(), [](const pair<const int, unique_ptr<Task>>& object)
				{
					cout << *object.second << "\t " << object.first << endl;
				});
			cout << endl;
			break;
		case 2:
			Map.emplace(++i, newStudent(add++));
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(5) << "Key" << endl;
			for_each(Map.begin(), Map.end(), [](const pair<const int, unique_ptr<Task>>& object)
				{
					cout << *object.second << "\t " << object.first << endl;
				});
			cout << endl;
			break;
		case 3:
		{
			cout << "Enter key of student to get: " << endl;
			cin >> num;
			cout << endl;
			it = Map.find(num);
			if (it != Map.end())
			{
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(5) << "Key" << endl;
				cout << *it->second << "\t " << it->first << endl << endl;
			}
			else
				cout << "Wrong key" << endl << endl;
			break;
		}
		case 4:
		{
			cout << "Enter key of student to delete: " << endl;
			cin >> num;
			it = Map.find(num);
			if (it != Map.end())
			{
				Map.erase(it);
				cout << endl;
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(5) << "Key" << endl;
				for_each(Map.begin(), Map.end(), [](const pair<const int, unique_ptr<Task>>& object)
					{
						cout << *object.second << "\t " << object.first << endl;
					});
				cout << endl << "Delete successful" << endl << endl;
			}
			else
				cout << "Wrong key" << endl << endl;
			break;
		}
		case 5:
		{
			int amountOfElements = 0;
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = Map.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			while (result != -1 && i < Map.size())
			{
				result = it->second->amountElementsPerCriterium(var, data);
				if (result == -1)
					break;
				i++;
				it++;
				amountOfElements += result;
			}
			if (result != -1)
				cout << endl << "Amount of elements with selected field: " << amountOfElements << endl << endl;
			break;
		}
		case 6:
		{
			int var;
			string data;
			int result = 0;
			int i = 0;
			it = Map.begin();
			cout << "Choose field of object:" << endl;
			cout << "1. Index" << endl;
			cout << "2. Name" << endl;
			cout << "3. Mark" << endl;
			cout << "4. Exercises" << endl;
			cout << "5. RGZ" << endl;
			cout << "6. RgzForTeacher" << endl;
			cin >> var;
			cout << endl << "Enter data which will be used as criterium" << endl;
			cin.ignore();
			getline(cin, data);
			cout << endl;
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(8) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			while (result != 1 && result != -1 && i < Map.size())
			{
				result = it->second->findElementPerCriterium(var, data);
				if (result == 1)
					break;
				i++;
				it++;
			}
			if (result == 0)
				cout << "There is no element with that criterium" << endl << endl;
			break;
		}
		case 7:
			menuNum = 0;
			break;
		default:
			cout << "Wrong command, try something else" << endl << endl;
			break;
		}
	}
	return;
}

int generateID()
{
	static int id = 1;
	return id++;
}

int generateRGZ()
{
	static int RGZ = 5;
	return RGZ++;
}

int generateRgzForTeacher()
{
	static int rgzForTeacher = 2;
	return rgzForTeacher++;
}