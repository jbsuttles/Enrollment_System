#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include "roster.h"
using namespace std;

Roster::Roster()
{
	this->lastIndex = -1;
	this->capacity = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) 
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentat(int index)
{
	return classRosterArray[index];
}

void Roster::parseStudentData(string datarow) 
{
	if (lastIndex < capacity) {
		++lastIndex;

		//Parse through data string seperating data by comas

		//Student ID
		int rhs = datarow.find(',');
		string studentId = datarow.substr(0, rhs);

		//First Name
		int lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		string firstName = datarow.substr(lhs, rhs - lhs);

		//Last Name
		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		string lastName = datarow.substr(lhs, rhs - lhs);

		//Email
		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		string email = datarow.substr(lhs, rhs - lhs);

		//Age
		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		int age = stoi(datarow.substr(lhs, rhs - lhs));

		//Days
		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		int daysInCourse1 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		int daysInCourse2 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		int daysInCourse3 = stoi(datarow.substr(lhs, rhs - lhs));

		//Degree
		DegreeProgram degree;
		lhs = rhs + 1;
		rhs = datarow.find(',', lhs);
		string degreeString = datarow.substr(lhs, rhs - lhs);

		if (degreeString == "SECURITY") {
			degree = SECURITY;
		}
		else if (degreeString == "NETWORK") {
			degree = NETWORK;
		}
		else if (degreeString == "SOFTWARE") {
			degree = SOFTWARE;
		}
		else {
			cerr << "Invalid Degree Type. Exiting now.";
			exit(-1);
		}

		//All information added together
		add(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	}
	else {
		cerr << "List has exceeded capacity.\n Exiting now.";
		exit(-1);
	}
}

void Roster::add(string studentId, string firstName, string lastName, string email,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) 
{
	//Populate  array with days
	int days[Student::daysArraySize];
	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;


	//Create new objects of classes
	if (degree == SECURITY) {
		classRosterArray[lastIndex] = new Security(studentId, firstName, lastName, email, age, days, degree);
	}
	else if (degree == NETWORK) {
		classRosterArray[lastIndex] = new Network(studentId, firstName, lastName, email, age, days, degree);
	}
	else {
		classRosterArray[lastIndex] = new Software(studentId, firstName, lastName, email, age, days, degree);
	}
}

void Roster::remove(string studentId)
{
	int currentLastIndex = lastIndex;
	for (int i = 0; i <= lastIndex; i++) {

		if (this->classRosterArray[i]->getStudentId() == studentId) {
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (currentLastIndex == lastIndex) {
		cout << "Student not found.\n" << endl;
	}
}

void Roster::printAll()
{

	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i <= lastIndex; i++) {

		if (this->classRosterArray[i]->getStudentId() == studentId) {

			int* daysTotal = this->classRosterArray[i]->getDays();
			double daysDoube[sizeof(daysTotal)];
			
			//Convert int to double in array
			for (int i = 0; i < sizeof(daysTotal); i++) {
				daysDoube[i] = static_cast<double>(daysTotal[i]);
			}

			//Output AVG
			cout << "Average number of days for " << this->classRosterArray[i]->getStudentId()
				<< " is " << (daysDoube[0] + daysDoube[1] + daysDoube[2])/3.0 << "\n" << endl;
		}
	}
	
}

void Roster::printInvalidEmails()
{
	//Check for blank value
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getEmail().find(' ') != string::npos) {
			cout << this->classRosterArray[i]->getEmail() << "\n";
		}
		else if ((this->classRosterArray[i]->getEmail().find('@') == string::npos) ||
			(this->classRosterArray[i]->getEmail().find('.') == string::npos)) {
			cout << this->classRosterArray[i]->getEmail() << "\n";
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree)
{
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degree) {
			(this->classRosterArray)[i]->print();
		}
	}
}

Roster::~Roster() {

}