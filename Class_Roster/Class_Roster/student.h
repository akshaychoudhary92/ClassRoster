#pragma once
#include <string>
#include "degree.h"


using  std::string;


class student
{
public: 
    const static int arraySize = 3; 
	string studentId;
	string firstName; 
	string lastName; 
	string emailAddress; 
	int age; 
	int daysToComplete[arraySize];
	DegreeProgram degreeprogram; 

public:
	student();
	student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeprogram);
	~student(); 



public:
    string getStudentId();
    void setStudentId(string studentId) { this->studentId = studentId; };

    string getFirstName();
    void setFirstName(string firstName) { this->firstName = firstName; };

    string getLastName();
    void setLastName(string lastName) { this->lastName = lastName; };

    string getEmailAddress();
    void setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; };

    int getAge();
    void setAge(int age) { this->age = age; };

    int* getDaysToComplete();
    void setdaysToComplete(int daysToComplete[]);

    DegreeProgram getDegreeprogram();
    void setDegreeprogram(DegreeProgram degreeprogram);

    static void printHeader(); 

    void print();
};

