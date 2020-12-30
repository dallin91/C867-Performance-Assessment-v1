#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int daysArrayLen = 3;

private:
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	int studentAge;
	int daysToComplete[daysArrayLen];
	DegreeProgram degreeProgram;

public:
	//constructors
	Student();
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
		int studentAge, int daysToComplete[], DegreeProgram degreeProgram);
	//destructor
	~Student();

	//Accessors
	string GetStudentID();
	string GetStudentFirstName();
	string GetStudentLastName();
	string GetStudentEmail();
	int GetStudentAge();
	int* GetNumDaysToComplete();
	DegreeProgram GetDegreeProgram();

	//Mutators
	void SetStudentID(string studentID);
	void SetStudentFirstName(string studentFirstName);
	void SetStudentLastName(string studentLastName);
	void SetStudentEmail(string studentEmail);
	void SetStudentAge(int studentAge);
	void SetNumDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	static void PrintHeader();
	void Print();
};