#include <iostream>
#include <string>
#include "network.h"
#include "degree.h"
using namespace std;


Network::Network() :Student()
{
	degree = NETWORK;
}

Network::Network(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degree)
	: Student(studentId, firstName, lastName, email, age, days)
{
	degree = NETWORK;
}

DegreeProgram Network::getDegreeProgram()
{
	return NETWORK;
}

void Network::print()
{
	this->Student::print();
	cout << "Degree Program: NETWORK\n";
}

Network::~Network()
{
	Student::~Student();
}