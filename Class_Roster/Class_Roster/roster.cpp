#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"


using std::cout;
using std::endl;

void roster::parse(string studentdata) {
	
	DegreeProgram dp = UNDECIDED;
	if (studentdata.at(0) == 'S') dp = SOFTWARE;
	else if (studentdata.at(0) == 'N') dp = NETWORK;
	else dp = SECURITY; 

	int rhs = studentdata.find(",");
	string sID = studentdata.substr(0, rhs); 

	int lhs = rhs + 1; 
	rhs = studentdata.find(",", lhs);
	string fn = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1; 
	rhs = studentdata.find(",", lhs); 
	string lasn = studentdata.substr(lhs, rhs - lhs); 

	lhs = rhs + 1; 
	rhs = studentdata.find(",", lhs); 
	string ema = studentdata.substr(lhs, rhs - lhs); 

	lhs = rhs + 1; 
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs)); 

	lhs = rhs + 1; 
	rhs = studentdata.find(",", lhs);
	int d1 = stoi(studentdata.substr(lhs, rhs - lhs)); 

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d2 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d3 = stoi(studentdata.substr(lhs, rhs - lhs));


	add(sID, fn, lasn, ema, age, d1, d2, d3, dp); 
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int complete1, int complete2, int complete3, DegreeProgram dp) {
	int sarr[3] = { complete1, complete2, complete3 };
	studentRosterArray[++lastStudent] = new student(studentID, firstName, lastName, emailAddress, age, sarr, dp); 


};

void roster::printAll() {
	student::printHeader();
	for (int i = 0; i <= roster::lastStudent; i++) {
		cout << studentRosterArray[i]->getStudentId(); cout << '\t';
		cout << studentRosterArray[i]->getFirstName(); cout << '\t'; 
		cout << studentRosterArray[i]->getLastName(); cout << '\t';
		cout << studentRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << studentRosterArray[i]->getAge(); cout << '\t';
		cout << studentRosterArray[i]->getDaysToComplete()[0]; cout << '\t';
		cout << studentRosterArray[i]->getDaysToComplete()[1]; cout << '\t';
		cout << studentRosterArray[i]->getDaysToComplete()[2]; cout << '\t';
		cout << degreeProgramStrings[studentRosterArray[i]->getDegreeprogram()] << std::endl;

	}

	
}

void roster::printByDegreeProgram(DegreeProgram dp) {
	student::printHeader();
	for (int i = 0; i <= roster::lastStudent; i++) {
		if (roster::studentRosterArray[i]->getDegreeprogram() == dp) studentRosterArray[i]->print();
	}
	cout << std::endl; 
}

void roster::printInvalidEmails() {
	bool any = false; 
	for (int i = 0; i <= roster::lastStudent; i++) {
		string ema = (studentRosterArray[i]->getEmailAddress());
		if (ema.find('.') == string::npos || (ema.find('@') == string::npos || ema.find(' ') == string::npos))
		{
			any = true; 
			cout << ema << ": " << studentRosterArray[i]->getStudentId() << std::endl;
		
		}
	}
	if (!any) cout << "none found" << std::endl;
}

void roster::printAverageDaysInCourse(string studentId) 
{
	for (int i = 0; i <= roster::lastStudent; i++) {
		cout << studentRosterArray[i]->getStudentId() << ": ";
		cout << (studentRosterArray[i]->getDaysToComplete()[0] + studentRosterArray[i]->getDaysToComplete()[1] + studentRosterArray[i]->getDaysToComplete()[2]) / 3 << std::endl;
	}

	cout << std::endl;


}

void roster::remove(string studentID) 
{
	bool success = false; 
	for (int i = 0; i <= roster::lastStudent; i++) 
	{
		if (studentRosterArray[i]->getStudentId() == studentID) \
		{
			success = true; 
			if (i < numberOfStudents - 1) {
				student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numberOfStudents - 1];
				studentRosterArray[numberOfStudents - 1] = temp;
			}
			roster::lastStudent--;
		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << endl << endl;
		this->printAll();

	}
	else cout << studentID << " not found." << endl << endl; 
}

roster::~roster() {
	cout << "Destructor called" << endl << endl; 
	for (int i = 0; i < numberOfStudents; i++) 
	{
		cout << "destroying student #" << i + 1 << endl; 
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}


