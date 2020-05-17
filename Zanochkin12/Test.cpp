#include "Inheritor.h"

void vectorTest();
void setTest();
void listTest();
void mapTest();

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
	vector <int> vec = { 1,2,3,4 };
	int vectorSize = vec.size();
	vec.push_back(123);
	if (vec.size() == vectorSize + 1)
		cout << "Vector add test - succsessful" << endl;
	else
		cout << "Vector add test - UNsuccsessful" << endl;
	vector<int>::iterator it = vec.begin();
	vec.erase(it);
	if (vectorSize == vec.size())
		cout << "Vector delete test - succsessful" << endl;
	else
		cout << "Vector delete test - UNsuccsessful" << endl;
	if (vec[1] == 3)
		cout << "Vector get object test - succsessful" << endl;
	else
		cout << "Vector get object test - UNsuccsessful" << endl;
}

void setTest()
{
	cout << endl << endl << "SET" << endl << endl;
	set <int> Set = { 1,2,3,4 };
	int setSize = Set.size();
	Set.insert(123);
	if (Set.size() == setSize + 1)
		cout << "Set add test - succsessful" << endl;
	else
		cout << "Set add test - UNsuccsessful" << endl;
	set<int>::iterator itForDel = Set.begin();
	Set.erase(itForDel);
	if (setSize == Set.size())
		cout << "Set delete test - succsessful" << endl;
	else
		cout << "Set delete test - UNsuccsessful" << endl;
	set<int>::iterator itForGet = Set.end();
	if (Set.find(1) == itForGet)
		cout << "Set get object test - succsessful" << endl;
	else
		cout << "Set get object test - UNsuccsessful" << endl;
}

void listTest()
{
	cout << endl << endl << "LIST" << endl << endl;
	list <int> List = { 1,2,3,4 };
	int listSize = List.size();
	List.push_back(123);
	if (List.size() == listSize + 1)
		cout << "List add test - succsessful" << endl;
	else
		cout << "List add test - UNsuccsessful" << endl;
	list<int>::iterator itForDel = List.begin();
	List.erase(itForDel);
	if (listSize == List.size())
		cout << "List delete test - succsessful" << endl;
	else
		cout << "List delete test - UNsuccsessful" << endl;
	list<int>::iterator itForGet = List.begin();
	advance(itForGet, 4);
	if (List.end() == itForGet)
		cout << "List get object test - succsessful" << endl;
	else
		cout << "List get object test - UNsuccsessful" << endl;
}

void mapTest()
{
	cout << endl << endl << "MAP" << endl << endl;
	map <int, int> Map;
	Map.insert(pair<int, int>(1, 1));
	Map.insert(pair<int, int>(2, 2));
	Map.insert(pair<int, int>(3, 3));
	Map.insert(pair<int, int>(4, 4));
	int mapSize = Map.size();
	Map.insert(pair<int, int>(5, 123));
	if (Map.size() == mapSize + 1)
		cout << "Map add test - succsessful" << endl;
	else
		cout << "Map add test - UNsuccsessful" << endl;
	map<int, int>::iterator itForDel = Map.begin();
	Map.erase(itForDel);
	if (mapSize == Map.size())
		cout << "Map delete test - succsessful" << endl;
	else
		cout << "Map delete test - UNsuccsessful" << endl;
	map<int, int>::iterator itForGet = Map.end();
	if (Map.find(123) == itForGet)
		cout << "Map get object test - succsessful" << endl;
	else
		cout << "Map get object test - UNsuccsessful" << endl;
}