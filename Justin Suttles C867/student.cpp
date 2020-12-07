#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student()
{
	//Empty constructor with default values
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++)
		this->days[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int days[])
{
	//Full constructor
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++)
		this->days[i] = days[i];
}

//Getters
string Student::getStudentId() 
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return days;
}

//Setters
void Student::setStudentId(string studentId)
{
	this->studentId = studentId;
}

void Student::setFirstName(string firstName) 
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDays(int days[])
{
	for (int i = 0; i < daysArraySize; i++)
		this->days[i] = days[i];
}

void Student::print()
{
	cout << studentId << '\t';
	cout << "First Name: " << firstName << '\t';
	cout << "Last Name: " << lastName << '\t';
	cout << "Age: " << age << '\t';
	cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "}\t";
}

Student::~Student()
{

}
