#include "Task.h"

class Functor
{
private:
	int sort;
public:
	bool operator() (const shared_ptr<Task>& a, const shared_ptr<Task>& b);

	Functor(int sort);
	~Functor();
};