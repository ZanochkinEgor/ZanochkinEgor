#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <regex>
#include <vector>
using std::regex_match;
using std::regex;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::exception;
using std::istringstream;
using std::vector;

class List
{
private:
	int arraySize;
	int* tempArray;
	int** array;
public:
	int getArraySize() const;
	void writeInFile(string fileName, int* sz) const noexcept (false);
	void readFromFile(string fileName) noexcept (false);
	int stringsInFile(string fileName) const noexcept;
	int* task() noexcept (false);
	void print() noexcept;
	int& operator[] (const size_t i) const noexcept(false);
	~List();
};

void Menu() noexcept;
string fileName() noexcept;