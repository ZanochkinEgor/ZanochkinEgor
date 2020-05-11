#pragma once
#include "Student.h"

class TemplateClass
{
public:
	template <typename T>
	void print(T* array, int size) const noexcept
	{
		cout << endl << "Array:" << endl;
		for (size_t i = 0; i < size; i++)
			cout << array[i] << endl;
		cout << endl;
	}

	template <typename T>
	int index(T* array, T element, int size) noexcept
	{
		for (size_t i = 0; i < size; i++)
			if (array[i] == element)
				return i;
		return -1;
	}

	template <typename T>
	void sort(T* array, int choise, int size) noexcept
	{
		TemplateClass object;
		bool pr = 0;
		bool sort;
		T temp;
		do
		{
			pr = false;
			for (int i = 0; i < size - 1; i++)
			{
				if (choise == 1)
					sort = object.sortAscending(array[i], array[i + 1]);
				else if (choise == 2)
					sort = object.sortDescending(array[i], array[i + 1]);
				if (sort)
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					pr = true;
				}
			}
		} while (pr);
	}

	template <typename T>
	T min(T* array, int size) noexcept
	{
		T min = array[0];
		for (size_t i = 1; i < size; i++)
			if (array[i] < min)
				min = array[i];
		return min;
	}

	template <typename T>
	static bool sortAscending(const T& a, const T& b) noexcept
	{
		return a > b;
	}

	template <typename T>
	static bool sortDescending(const T& a, const T& b) noexcept
	{
		return a < b;
	}
};