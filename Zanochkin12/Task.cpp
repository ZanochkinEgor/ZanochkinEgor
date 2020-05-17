#include "Task.h"

int Task::getStudentIndex() const { return studentIndex; }

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

Task::Task(int student_index, string name, int mark, int countOfDoneExercises, int rgz) : studentIndex(student_index), name(name), mark(mark), countOfDoneExercises(countOfDoneExercises), rgz(rgz) {}
Task::Task() : studentIndex(generateID()), name("Egor"), mark(4), countOfDoneExercises(8), rgz(generateRGZ()) {}
Task::Task(const Task& stud) : studentIndex(stud.studentIndex), name(stud.name), mark(stud.mark), countOfDoneExercises(stud.countOfDoneExercises), rgz(stud.rgz) {}
Task::~Task() {}