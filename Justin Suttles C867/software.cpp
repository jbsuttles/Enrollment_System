#include <iostream>
#include <string>
#include "software.h"
using namespace std;


Software::Software() :Student()
{
	degree = SOFTWARE;
}

Software::Software(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree)
	: Student(studentId, firstName, lastName, email, age, days)
{
	degree = SOFTWARE;
}

DegreeProgram Software::getDegreeProgram()
{
	return SOFTWARE;
}

void Software::print()
{
	this->Student::print();
	cout << "Degree Program: SOFTWARE\n";
}

Software::~Software()
{
	Student::~Student();
}