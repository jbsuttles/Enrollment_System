#pragma once
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Software : public Student
{
public:

	//Constructors
	Software();
	Software(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree);

	//Setter
	DegreeProgram getDegreeProgram();

	void print();

	//Destructor
	~Software();
};
