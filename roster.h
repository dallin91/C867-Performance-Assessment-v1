#pragma once
#include "student.h"

class Roster {
public:
	const static int numStudents = 5;
	Student* rosterArray[numStudents];
	int lastIndex = -1;

public:
	//parse each set of data in studentData table
	void parse(string row);
	//add each student object to classRosterArray
	void add(string studentID, string firstName, string lastName, string email,
		int age, double daysToComplete1, double daysToComplete2, double daysToComplete3,
		DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};