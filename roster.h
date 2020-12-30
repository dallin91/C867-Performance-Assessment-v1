#pragma once
#include "student.h"

class Roster {
public:
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
	int lastIndex = -1;

public:
	//parse each set of data in studentData table
	void parse(string row);
	//add each student object to classRosterArray
	void add(string studentID, string firstName, string lastName, string email,
		int age, int daysToComplete1, int daysToComplete2, int daysToComplete3,
		DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};