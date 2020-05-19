#include "Functor.h"

Functor::Functor(int sort) : sort(sort) {}
Functor::~Functor() {}

bool Functor::operator() (const shared_ptr<Task>& a, const shared_ptr<Task>& b) {
	if (sort == 1)
		return a->getStudentIndex() < b->getStudentIndex();
	else if (sort == 2)
		return a->getStudentIndex() > b->getStudentIndex();
}