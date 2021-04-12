#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;



student::student() {
	this->studentId = "";
	this->firstName = ""; 
	this->lastName = "";
	this->emailAddress = "";
	this->age = age; 
	for (int i = 0; i < arraySize; i++) this->daysToComplete[i] = 0; 
	this->degreeprogram = DegreeProgram::UNDECIDED;


}

student::student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < arraySize; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeprogram = degreeProgram;


}

student::~student() {}

string student::getStudentId() {return this->studentId;}
string student::getFirstName() { return this->firstName; }
string student::getLastName() { return this->lastName; }
string student::getEmailAddress() { return this->emailAddress; }
int student::getAge() { return this->age; }
int * student::getDaysToComplete() { return this->daysToComplete; }
DegreeProgram student::getDegreeprogram() {
	return this->degreeprogram;
}

void student::setStudentId(string ID) {
	this ->studentId = ID;
}
void student::setFirstName(string firstName) {
	this->firstName = firstName;

}
void student::setLastName(string lastName) {
	this->lastName = lastName; 
}
void student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void student::setAge(int age) {
	this->age = age;
}
void student::setdaysToComplete(int daysToComplete[]) {

	for (int i = 0; i < arraySize; i++) this->daysToComplete[i] = daysToComplete[i];
}

void student::setDegreeprogram(DegreeProgram dProgram) {
	this->degreeprogram = dProgram; 
}

void student::printHeader() {
	cout << "Output format: ID|FirstName|LastName|EmailAddress|Age|DaysToCompleteProgram|DegreeProgram\n";
}

void student::print() {
	cout << this->getStudentId() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysToComplete()[0] << ',';
	cout << this->getDaysToComplete()[1] << ',';
	cout << this->getDaysToComplete()[2] << ',';
	cout << degreeProgramStrings[this->getDegreeprogram()] << '\n';

}




