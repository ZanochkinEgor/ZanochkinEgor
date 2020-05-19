#include "Task.h"

class Inheritor final : public Task
{
private:
	int rgzForTeacher;
public:
	string getInfo() const override final;
	stringstream getStr() const override final;
	int amountElementsPerCriterium(int num, string data) override final;
	int findElementPerCriterium(int num, string data) override final;

	bool operator==(const int) const override final;

	Inheritor();
	Inheritor(int, string, int, int, int, int);
	Inheritor(const Inheritor&);
	~Inheritor() override final;
};