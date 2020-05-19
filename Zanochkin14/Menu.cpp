#include "Inheritor.h"
#include "Task.h"
#include "Functor.h"

vector <shared_ptr<Task>> concatenateTwoVectors(vector <shared_ptr<Task>>& one, vector <shared_ptr<Task>>& two);

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
	vector<shared_ptr<Task>> vec;
	vector<shared_ptr<Task>>::iterator it;
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
		cout << "7. Sort (index)" << endl;
		cout << "8. Concatenate two vectors" << endl;
		cout << "9. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(vec.begin(), vec.end(), [](const shared_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 2:
			try
			{
				vec.emplace_back(newStudent(add++));
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(vec.begin(), vec.end(), [](const shared_ptr<Task>& object)
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(vec.begin(), vec.end(), [](const shared_ptr<Task>& object)
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
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
			cout << "Sort:" << endl;
			cout << "1. Ascending sort" << endl;
			cout << "2. Descending sort" << endl;
			int sortNum;
			cin >> sortNum;
			if (sortNum == 1 || sortNum == 2)
			{
				Functor obj(sortNum);
				sort(vec.begin(), vec.end(), obj);
				cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(vec.begin(), vec.end(), [](const shared_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl;
			}
			else
				cout << "Wrong number" << endl << endl;
			break;
		case 8:
		{
			int i = 0;
			vector <shared_ptr<Task>> vecForConc;
			for (; i < 2; i++)
			{
				if (i == 0)
					vecForConc.emplace_back(new Inheritor(generateID(), "Albert", 5, 1, generateRGZ(), generateRgzForTeacher()));
				else if (i == 1)
					vecForConc.emplace_back(new Inheritor(generateID(), "Vika", 2, 3, generateRGZ(), generateRgzForTeacher()));
			}
			cout << "Vector for concatenate:" << endl;
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(vecForConc.begin(), vecForConc.end(), [](const shared_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			vec = concatenateTwoVectors(vec, vecForConc);
			vecForConc.clear();
			cout << "Vector after concatenating:" << endl;
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(vec.begin(), vec.end(), [](const shared_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		}
		case 9:
			menuNum = 0;
			break;
		default:
			cout << "Wrong command, try something else" << endl << endl;
			break;
		}
	}
	return;
}

vector <shared_ptr<Task>> concatenateTwoVectors(vector <shared_ptr<Task>>& first, vector <shared_ptr<Task>>& second)
{
	vector <shared_ptr<Task>> vecForMerge;
	vecForMerge.insert(vecForMerge.end(), first.begin(), first.end());
	vecForMerge.insert(vecForMerge.end(), second.begin(), second.end());
	return vecForMerge;
}

void setMenu()
{
	int menuNum = 1;
	int num = 0;
	int add = 1;
	unordered_set <shared_ptr<Task>> Set;
	unordered_set <shared_ptr<Task>>::iterator it;
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
		cout << "7. Sort (index)" << endl;
		cout << "8. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(Set.begin(), Set.end(), [](const shared_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 2:
			Set.emplace(newStudent(add++));
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(Set.begin(), Set.end(), [](const shared_ptr<Task>& object)
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(Set.begin(), Set.end(), [](const shared_ptr<Task>& object)
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
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
			cout << "Sort:" << endl;
			cout << "1. Ascending sort" << endl;
			cout << "2. Descending sort" << endl;
			int sortNum;
			cin >> sortNum;
			if (sortNum == 1 || sortNum == 2)
			{
				vector<shared_ptr<Task>> temp(Set.begin(), Set.end());
				Set.clear();
				Functor obj(sortNum);
				sort(temp.begin(), temp.end(), obj);
				Set.insert(temp.begin(), temp.end());
				cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(Set.begin(), Set.end(), [](const shared_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl;
			}
			else
				cout << "Wrong number" << endl << endl;
			break;
		case 8:
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
	list <shared_ptr<Task>> List;
	list <shared_ptr<Task>>::iterator it;
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
		cout << "7. Sort (index)" << endl;
		cout << "8. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(List.begin(), List.end(), [](const shared_ptr<Task>& object)
				{
					cout << *object << endl;
				});
			cout << endl;
			break;
		case 2:
			List.emplace_front(newStudent(add++));
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
			for_each(List.begin(), List.end(), [](const shared_ptr<Task>& object)
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(List.begin(), List.end(), [](const shared_ptr<Task>& object)
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
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
			cout << "Sort:" << endl;
			cout << "1. Ascending sort" << endl;
			cout << "2. Descending sort" << endl;
			int sortNum;
			cin >> sortNum;
			if (sortNum == 1 || sortNum == 2)
			{
				Functor obj(sortNum);
				List.sort(obj);
				cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
				for_each(List.begin(), List.end(), [](const shared_ptr<Task>& object)
					{
						cout << *object << endl;
					});
				cout << endl;
			}
			else
				cout << "Wrong number" << endl << endl;
			break;
		case 8:
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
	map <int, shared_ptr<Task>> Map;
	map <int, shared_ptr<Task>>::iterator it,it2;
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
		cout << "7. Sort (index)" << endl;
		cout << "8. Concatenate two maps" << endl;
		cout << "9. Exit" << endl;
		cin >> menuNum;
		cout << endl;
		switch (menuNum)
		{
		case 1:
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
			for_each(Map.begin(), Map.end(), [](const pair<const int, shared_ptr<Task>>& object)
				{
					cout << *object.second << "\t      " << object.first << endl;
				});
			cout << endl;
			break;
		case 2:
			Map.emplace(++i, newStudent(add++));
			cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
			for_each(Map.begin(), Map.end(), [](const pair<const int, shared_ptr<Task>>& object)
				{
					cout << *object.second << "\t      " << object.first << endl;
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
				cout << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
				cout << *it->second << "\t      " << it->first << endl << endl;
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
				cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
				for_each(Map.begin(), Map.end(), [](const pair<const int, shared_ptr<Task>>& object)
					{
						cout << *object.second << "\t      " << object.first << endl;
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
			cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << endl;
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
			cout << "Sort:" << endl;
			cout << "1. Ascending sort" << endl;
			cout << "2. Descending sort" << endl;
			int sortNum;
			cin >> sortNum;
			if (sortNum == 1 || sortNum == 2)
			{
				i = 0;
				Functor obj(sortNum);
				vector <shared_ptr<Task>> temp;
				for (auto const& a : Map)
					temp.push_back(a.second);
				sort(temp.begin(), temp.end(), obj);
				Map.clear();
				transform(temp.begin(), temp.end(), inserter(Map, Map.end()), [&i](const shared_ptr<Task>& a) 
					{ 
						return make_pair(++i, a); 
					});
				cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
				for_each(Map.begin(), Map.end(), [](const pair<const int, shared_ptr<Task>>& object)
					{
						cout << *object.second << "\t      " << object.first << endl;
					});
				cout << endl;
			}
			else
				cout << "Wrong number" << endl << endl;
			break;
		case 8:
		{
			map <int, shared_ptr<Task>> Map1;
			stringstream ss1, ss2;
			int idFirst, idSecond, markFirst, markSecond, exFirst, exSecond, rgzFirst, rgzSecond, rgzForTeachFirst, rgzForTeachSecond, id, mark, ex, rgz, rgzForTeach;
			string nameFirst, nameSecond, name;
			i = 0;
			for (; i < 2; i++)
			{
				if (i == 0)
					Map1.emplace(i+1,new Inheritor(generateID(), "Albert", 5, 1, generateRGZ(), generateRgzForTeacher()));
				else if (i == 1)
					Map1.emplace(i+1,new Inheritor(generateID(), "Vika", 2, 3, generateRGZ(), generateRgzForTeacher()));
			}
			cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
			cout << "Map for concatenate:" << endl;
			for_each(Map1.begin(), Map1.end(), [](const pair<const int, shared_ptr<Task>>& object)
				{
					cout << *object.second << "\t      " << object.first << endl;
				});
			multimap <int, shared_ptr<Task>> mMap(Map.begin(), Map.end());
			multimap <int, shared_ptr<Task>>::iterator IT2 = mMap.begin(), IT = mMap.begin();
			mMap.insert(Map1.begin(), Map1.end());
			cout << "Multimap:" << endl;
			for_each(mMap.begin(), mMap.end(), [](const pair<const int, shared_ptr<Task>>& object)
				{
					cout << *object.second << "\t " << object.first << endl;
				});
			Map1.clear();
			Map.clear();
			advance(IT2, 1);
			int key = 1;
			for (i = 1; i < mMap.size(); i++)
			{
				if (IT->first == IT2->first)
				{
					ss1 = IT->second->getStr();
					ss2 = IT2->second->getStr();
					ss1 >> idFirst;
					ss1 >> nameFirst;
					ss1 >> markFirst;
					ss1 >> exFirst;
					ss1 >> rgzFirst;
					ss1 >> rgzForTeachFirst;

					ss2 >> idSecond;
					ss2 >> nameSecond;
					ss2 >> markSecond;
					ss2 >> exSecond;
					ss2 >> rgzSecond;
					ss2 >> rgzForTeachSecond;

					id = idFirst + idSecond;
					name = nameFirst + nameSecond;
					mark = markFirst + markSecond;
					ex = exFirst + exSecond;
					rgz = rgzFirst + rgzSecond;
					rgzForTeach = rgzForTeachFirst + rgzForTeachSecond;
					Map.emplace(key++, new Inheritor(id, name, mark, ex, rgz, rgzForTeach));
				}
				advance(IT, 1);
				advance(IT2, 1);
			}
			Map.insert(mMap.begin(), mMap.end());
			cout << endl << "Result:" << endl;
			cout << endl << setw(5) << "Index" << setw(6) << "Name" << setw(12) << "Mark" << setw(11) << "Exercises" << setw(5) << "RGZ" << setw(11) << "Rgz4Teach" << setw(6) << "Key" << endl;
			for_each(Map.begin(), Map.end(), [](const pair<const int, shared_ptr<Task>>& object)
				{
					cout << *object.second << "\t      " << object.first << endl;
				});
			cout << endl;
			break;
		}
		case 9:
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