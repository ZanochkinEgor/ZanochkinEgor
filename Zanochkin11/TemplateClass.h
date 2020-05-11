#pragma once
#include "Student.h"

template <typename T>
class TemplateClass
{
private:
	T** array;
public:
	void print(int size) const noexcept
	{
		cout << endl << "Array:" << endl;
		for (size_t i = 0; i < size; i++)
			cout << *array[i] << endl;
		cout << endl;
	}

	int index(T element, int size) noexcept
	{
		for (size_t i = 0; i < size; i++)
			if (*array[i] == element)
				return i;
		return -1;
	}

	T* sort(int choise, int size) noexcept
	{
		TemplateClass<T> object(T);
		bool pr = 0;
		bool sort;
		T* temp= NULL;
		do
		{
			pr = false;
			for (int i = 0; i < size - 1; i++)
			{
				if (choise == 1)
					sort = *array[i] > * array[i + 1];
				else if (choise == 2)
					sort = *array[i] < *array[i + 1];
				if (sort)
				{
					temp = *(array + i);
					*(array + i) = *(array + i + 1);
					*(array + i + 1) = temp;
					pr = true;
				}
			}
		} while (pr);
		return temp;
	}

	T min(int size) noexcept
	{
		T min = *array[0];
		for (size_t i = 1; i < size; i++)
			if (*array[i] < min)
				min = *array[i];
		return min;
	}

	TemplateClass(T** array) : array(array) {}
	~TemplateClass() {}
};