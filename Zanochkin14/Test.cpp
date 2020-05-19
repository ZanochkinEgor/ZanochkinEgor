#include "Inheritor.h"
#include "Functor.h"

void vectorTest();
void setTest();
void listTest();
void mapTest();

vector <shared_ptr<Task>> concTwoVectors(vector <shared_ptr<Task>>& first, vector <shared_ptr<Task>>& second)
{
	vector <shared_ptr<Task>> vecForMerge;
	vecForMerge.insert(vecForMerge.end(), first.begin(), first.end());
	vecForMerge.insert(vecForMerge.end(), second.begin(), second.end());
	return vecForMerge;
}

void main()
{
	vectorTest();
	setTest();
	listTest();
	mapTest();
	if (_CrtDumpMemoryLeaks())
		cout << endl << "WARNING! Memory leak" << endl;
	else
		cout << endl << "There is no memory leak" << endl;
}

void vectorTest()
{
	cout << "VECTOR" << endl << endl;
	int i = 0;
	int result = 0;
	string data1 = "Egor";
	int amountOfElements = 0;
	vector<shared_ptr<Task>> vec;
	vector<shared_ptr<Task>>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0)
			vec.emplace_back(new Inheritor());
		else if (i == 1)
			vec.emplace_back(new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	int vectorSize = vec.size();
	vec.emplace_back(newStudent(1));
	if (vec.size() == vectorSize + 1)
		cout << "Vector add test - succsessful" << endl;
	else
		cout << "Vector add test - UNsuccsessful" << endl;
	it = vec.begin();
	vec.erase(it);
	if (vectorSize == vec.size())
		cout << "Vector delete test - succsessful" << endl;
	else
		cout << "Vector delete test - UNsuccsessful" << endl;
	if (vec[1]->getStudentIndex() == 3)
		cout << "Vector get object test - succsessful" << endl;
	else
		cout << "Vector get object test - UNsuccsessful" << endl;
	it = vec.begin();
	while (result != -1 && i < vec.size())
	{
		result = (*it)->amountElementsPerCriterium(2, data1);
		i++;
		it++;
		amountOfElements += result;
	}
	if (amountOfElements == 0)
		cout << "Vector count elements test - succsessful" << endl;
	else
		cout << "Vector count elements test - UNsuccsessful" << endl;
	Functor obj(2);
	sort(vec.begin(), vec.end(), obj);
	if (vec[0]->getStudentIndex() == 3)
		cout << "Vector sort test - succsessful" << endl;
	else
		cout << "Vector sort test - UNsuccsessful" << endl;
	vector <shared_ptr<Task>> vecForConc(vec.begin(), vec.end());
	vec = concTwoVectors(vec, vecForConc);
	if (vec.size() == 4)
		cout << "Concatenate two vectors test - succsessful" << endl << endl;
	else
		cout << "Concatenate two vectors test - UNsuccsessful" << endl << endl;
}

void setTest()
{
	cout << endl << endl << "SET" << endl << endl;
	int i = 0;
	int result = 0;
	string data1 = "Egor";
	int amountOfElements = 0;
	unordered_set<shared_ptr<Task>> Set;
	unordered_set<shared_ptr<Task>>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0)
			Set.emplace(new Inheritor());
		else if (i == 1)
			Set.emplace(new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	int setSize = Set.size();
	Set.emplace(newStudent(1));
	if (Set.size() == setSize + 1)
		cout << "Set add test - succsessful" << endl;
	else
		cout << "Set add test - UNsuccsessful" << endl;
	it = Set.begin();
	Set.erase(it);
	if (setSize == Set.size())
		cout << "Set delete test - succsessful" << endl;
	else
		cout << "Set delete test - UNsuccsessful" << endl;
	it = Set.begin();
	stringstream ss = (*it)->getStr();
	string data2 = ss.str();
	if (data2 == "6 Vasya 2 5 10 7" || data2 == "5 Oleg 3 7 9 6" || data2 == "4 Egor 4 8 8 5")
		cout << "Set get object test - succsessful" << endl;
	else
		cout << "Set get object test - UNsuccsessful" << endl;
	it = Set.begin();
	while (result != -1 && i < Set.size())
	{
		result = (*it)->amountElementsPerCriterium(2, data1);
		i++;
		it++;
		amountOfElements += result;
	}
	if (amountOfElements == 1)
		cout << "Set count elements test - succsessful" << endl;
	else
		cout << "Set count elements test - UNsuccsessful" << endl;
	vector <shared_ptr<Task>> temp(Set.begin(), Set.end());
	Set.clear();
	Functor object(2);
	sort(temp.begin(), temp.end(), object);
	Set.insert(temp.begin(), temp.end());
	it = Set.begin();
	ss = (*it)->getStr();
	data1 = ss.str();
	if (data1 == "6 Vasya 2 5 10 7" || data1 == "5 Oleg 3 7 9 6" || data1 == "4 Egor 4 8 8 5")
		cout << "Set sort test - succsessful" << endl << endl;
	else
		cout << "Set sort test - UNsuccsessful" << endl << endl;
}

void listTest()
{
	cout << endl << endl << "LIST" << endl << endl;
	int i = 0;
	int result = 0;
	string data1 = "Egor";
	int amountOfElements = 0;
	stringstream ss;
	list <shared_ptr<Task>> List;
	list <shared_ptr<Task>>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		if (i == 0)
			List.emplace_back(new Inheritor());
		else if (i == 1)
			List.emplace_back(new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	int listSize = List.size();
	List.emplace_back(newStudent(1));
	if (List.size() == listSize + 1)
		cout << "List add test - succsessful" << endl;
	else
		cout << "List add test - UNsuccsessful" << endl;
	it = List.begin();
	List.erase(it);
	if (listSize == List.size())
		cout << "List delete test - succsessful" << endl;
	else
		cout << "List delete test - UNsuccsessful" << endl;
	it = List.begin();
	ss = (*it)->getStr();
	string data2 = ss.str();
	if (data2 == "8 Oleg 3 7 12 9")
		cout << "List get object test - succsessful" << endl;
	else
		cout << "List get object test - UNsuccsessful" << endl;
	it = List.begin();
	while (result != -1 && i < List.size())
	{
		result = (*it)->amountElementsPerCriterium(2, data1);
		i++;
		it++;
		amountOfElements += result;
	}
	if (amountOfElements == 0)
		cout << "List count elements test - succsessful" << endl;
	else
		cout << "List count elements test - UNsuccsessful" << endl;
	Functor object(2);
	List.sort(object);
	it = List.begin();
	ss = (*it)->getStr();
	data1 = ss.str();
	if (data1 == "9 Vasya 2 5 13 10")
		cout << "List sort test succsessful" << endl << endl;
	else
		cout << "List sort test failed" << endl << endl;
}

void mapTest()
{
	cout << endl << endl << "MAP" << endl << endl;
	int i = 0;
	int result = 0;
	string data1 = "Egor";
	int amountOfElements = 0;
	stringstream ss;
	map <int, shared_ptr<Task>> Map;
	map <int, shared_ptr<Task>>::const_iterator it;
	for (; i < 2; i++)
	{
		if (i == 0)
			Map.emplace(i + 1, new Inheritor());
		else if (i == 1)
			Map.emplace(i + 1, new Inheritor(generateID(), "Oleg", 3, 7, generateRGZ(), generateRgzForTeacher()));
	}
	int mapSize = Map.size();
	Map.emplace(++i, newStudent(1));
	if (Map.size() == mapSize + 1)
		cout << "Map add test - succsessful" << endl;
	else
		cout << "Map add test - UNsuccsessful" << endl;
	it = Map.begin();
	Map.erase(it);
	if (mapSize == Map.size())
		cout << "Map delete test - succsessful" << endl;
	else
		cout << "Map delete test - UNsuccsessful" << endl;
	it = Map.find(2);
	if (it == Map.begin())
		cout << "Map get object test - succsessful" << endl;
	else
		cout << "Map get object test - UNsuccsessful" << endl;
	it = Map.begin();
	while (result != -1 && i < Map.size())
	{
		result = it->second->amountElementsPerCriterium(2, data1);
		i++;
		it++;
		amountOfElements += result;
	}
	if (amountOfElements == 0)
		cout << "Map count elements test - succsessful" << endl;
	else
		cout << "Map count elements test - UNsuccsessful" << endl;
	Functor object(2);
	vector <shared_ptr<Task>> temp;
	for (auto const& a : Map)
		temp.push_back(a.second);
	sort(temp.begin(), temp.end(), object);
	transform(temp.begin(), temp.end(), inserter(Map, Map.end()), [&i](const shared_ptr<Task>& s) 
		{ 
			return make_pair(i++, s); 
		});
	it = Map.begin();
	ss = it->second->getStr();
	data1 = ss.str();
	if (data1 == "11 Oleg 3 7 15 12")
		cout << "Map sort test - succsessful" << endl << endl;
	else
		cout << "Map sort test - UNsuccsessful" << endl << endl;
}