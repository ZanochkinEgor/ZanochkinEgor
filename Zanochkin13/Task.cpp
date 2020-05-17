#include "Task.h"

int Task::getStudentIndex() const { return studentIndex; }

stringstream Task::getStr() const
{
	stringstream temp;
	temp << studentIndex << " " << name << " " << mark << " " << countOfDoneExercises << " " << rgz;
	return temp;
}

string Task::getInfo() const
{
	stringstream temp;
	temp.setf(std::ios::left);
	temp << setw(5) << studentIndex << setw(6) << name << setw(5) << mark << setw(5) << countOfDoneExercises << rgz;
	return temp.str();
}

ostream& operator<< (ostream& output, const Task& obj)
{
	output << obj.getInfo();
	return output;
}

bool Task::operator==(const int id) const
{
	return this->studentIndex == id;
}

int Task::amountElementsPerCriterium(int num, string data)
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
	}
	catch (const std::exception& ex)
	{
		cout << endl << ex.what() << endl << endl;
		return -1;
	}
	return 0;
}

int Task::findElementPerCriterium(int num, string data)
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
	}
	catch (const std::exception& ex)
	{
		cout << endl << ex.what() << endl << endl;
		return -1;
	}
	return 0;
}

Task::Task(int student_index, string name, int mark, int countOfDoneExercises, int rgz) : studentIndex(student_index), name(name), mark(mark), countOfDoneExercises(countOfDoneExercises), rgz(rgz) {}
Task::Task() : studentIndex(generateID()), name("Egor"), mark(4), countOfDoneExercises(8), rgz(generateRGZ()) {}
Task::Task(const Task& stud) : studentIndex(stud.studentIndex), name(stud.name), mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), rgz(stud.rgz) {}
Task::~Task() {}