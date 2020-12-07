#include <iostream>
#include <string>
#include "security.h"
using namespace std;


Security::Security() :Student()
{
	degree = SECURITY;
}

Security::Security(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree)
	: Student(studentId, firstName, lastName, email, age, days)
{
	degree = SECURITY;
}

DegreeProgram Security::getDegreeProgram()
{
	return SECURITY;
}

void Security::print()
{
	this->Student::print();
	cout << "Degree Program: SECURITY\n";
}

Security::~Security()
{
	Student::~Student();
}