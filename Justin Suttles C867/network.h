#pragma once
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Network : public Student
{
public:

	//Constructors
	Network();
	Network(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree);

	//Getter
	DegreeProgram getDegreeProgram();

	void print();

	//Destructor
	~Network();
};