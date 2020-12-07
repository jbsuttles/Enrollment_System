#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	const static int daysArraySize = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[daysArraySize];
	DegreeProgram degree;

public:

	//Constructors
	Student();
	Student(string studentId, string firstName, string lastName, string email, int age, int days[]);

	//Getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	virtual DegreeProgram getDegreeProgram() = 0;

	//Setters
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);

	virtual void print() = 0;

	//Destructor
	~Student();

};