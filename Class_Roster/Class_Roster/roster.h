#pragma once
#include "student.h"


class roster
{
private:
	 int lastStudent = -1;
	 const static int numberOfStudents = 5;
	 student* studentRosterArray[numberOfStudents];

public:
	void parse(string row); 
	void add(string sID,
		string sFirstName,
		string sLastName,
		string sEmailAddress,
		int sAge,
		int sCompletion1,
		int sCompletion2,
		int sCompletion3,
		DegreeProgram dp);

	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentId);
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void remove(string studentID);

	~roster();

};

