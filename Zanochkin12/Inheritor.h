#include "Task.h"

class Inheritor final : public Task
{
private:
	int rgzForTeacher;
public:
	string getInfo() const override final;

	bool operator==(const int) const override final;

	Inheritor();
	Inheritor(int, string, int, int, int, int);
	Inheritor(const Inheritor&);
	~Inheritor() override final;
};