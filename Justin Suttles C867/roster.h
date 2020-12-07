#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include "student.h"
#include "network.h"
#include "security.h"
#include "software.h"
using namespace std;

class Roster {

private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;

public:

	//Constructors
	Roster();
	Roster(int capacity);

	//Functions
	Student* getStudentat(int index);
	void parseStudentData(string datarow);
	void add(string studentId, string firstName, string lastName, string email,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);

	//Destructor
	~Roster();
};