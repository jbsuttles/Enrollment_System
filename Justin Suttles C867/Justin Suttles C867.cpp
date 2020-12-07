// Justin Suttles C867.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "network.h"
#include "security.h"
#include "software.h"
#include "degree.h"
using namespace std;

int main()
{

	int numStudents = 5;
	const string studentData[5] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Justin,Suttles,justin@wgu.edu,30,15,30,45,SOFTWARE" };

	//Create Roster object
	Roster * roster = new Roster(numStudents);

	//Populate Roster object
	for (int i = 0; i < numStudents; i++) {
		roster->parseStudentData(studentData[i]);
	}

	//Print all student data
	cout << "All students: \n";
	roster->printAll();

	//Print invalid email addresses
	cout << "Invalid email addresses: \n";
	roster->printInvalidEmails();

	//Average days for all students
	cout << "Aaverage days for all students: \n";
	for (int i = 0; i < numStudents; i++) {
		roster->printAverageDaysInCourse(roster->getStudentat(i)->getStudentId());
	}

	//Student in Software
	cout << "Students in the Software program: \n";
	roster->printByDegreeProgram(SOFTWARE);

	//Remove student A3
	cout << "Remove student with ID of A3: \n";
	roster->remove("A3");
	roster->printAll();

	//Try to remove student A3 again and expect error
	cout << "Remove student with ID of A3: \n";
	roster->remove("A3");

	system("pause");
	return 0;
}
