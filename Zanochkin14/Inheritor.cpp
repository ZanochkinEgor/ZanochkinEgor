#include "Inheritor.h"

stringstream Inheritor::getStr() const
{
	stringstream temp;
	temp << studentIndex << " " << name << " " << mark << " " << countOfDoneExercises << " " << rgz << " " << rgzForTeacher;
	return temp;
}

string Inheritor::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(7) << studentIndex << setw(14) << name << setw(8) << mark << setw(8) << countOfDoneExercises << setw(8) << rgz << rgzForTeacher;
	return temp.str();
}

bool Inheritor::operator==(const int id) const
{
	return this->studentIndex == id;
}

int Inheritor::amountElementsPerCriterium(int num, string data)
{
	try
	{
		if (num == 1)
		{
			int number = stoi(data);
			if (this->studentIndex == number)
				return 1;
			else
				return 0;
		}
		else if (num == 2)
		{
			if (this->name == data)
				return 1;
			else
				return 0;
		}
		else if (num == 3)
		{
			int number = stoi(data);
			if (this->mark == number)
				return 1;
			else
				return 0;
		}
		else if (num == 4)
		{
			int number = stoi(data);
			if (this->countOfDoneExercises == number)
				return 1;
			else
				return 0;
		}
		else if (num == 5)
		{
			int number = stoi(data);
			if (this->rgz == number)
				return 1;
			else
				return 0;
		}
		else if (num == 6)
		{
			int number = stoi(data);
			if (this->rgzForTeacher == number)
				return 1;
			else
				return 0;
		}
	}
	catch (const std::exception& ex)
	{
		cout << endl << ex.what() << endl << endl;
		return -1;
	}
	return 0;
}

int Inheritor::findElementPerCriterium(int num, string data)
{
	try
	{
		if (num == 1)
		{
			int number = stoi(data);
			if (this->studentIndex == number)
			{
				cout << *this << endl << endl;
				return 1;
			}
		}
		else if (num == 2)
		{
			if (this->name == data)
			{
				cout << *this << endl << endl;
				return 1;
			}
		}
		else if (num == 3)
		{
			int number = stoi(data);
			if (this->mark == number)
			{
				cout << *this << endl << endl;
				return 1;
			}
		}
		else if (num == 4)
		{
			int number = stoi(data);
			if (this->countOfDoneExercises == number)
			{
				cout << *this << endl << endl;
				return 1;
			}
		}
		else if (num == 5)
		{
			int number = stoi(data);
			if (this->rgz == number)
			{
				cout << *this << endl << endl;
				return 1;
			}
		}
		else if (num == 6)
		{
			int number = stoi(data);
			if (this->rgzForTeacher == number)
			{
				cout << *this << endl << endl;
				return 1;
			}
		}
	}
	catch (const std::exception& ex)
	{
		cout << endl << ex.what() << endl << endl;
		return -1;
	}
	return 0;
}

Inheritor::Inheritor() : Task(), rgzForTeacher(generateRgzForTeacher()) {}
Inheritor::Inheritor(int studentIndex, string name, int mark, int countOfDoneExercises, int rgz, int rgzForTeacher) : Task(studentIndex, name, mark, countOfDoneExercises, rgz), rgzForTeacher(rgzForTeacher) {}
Inheritor::Inheritor(const Inheritor& object) : Task(object), rgzForTeacher(object.rgzForTeacher) {}
Inheritor::~Inheritor() {}