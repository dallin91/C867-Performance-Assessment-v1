#include "student.h"

//default constructor
Student::Student() {
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	for (int i = 0; i < daysArrayLen; ++i) {
		this->daysToComplete[i] = 0;
	}
	this->degreeProgram = DegreeProgram::UNDECIDED;
}

//constructor
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
	int studentAge, int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < daysArrayLen; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//destructor
Student::~Student() {}

//accessors
string Student::GetStudentID() {
	return this->studentID;
}
string Student::GetStudentFirstName() {
	return this->studentFirstName;
}
string Student::GetStudentLastName() {
	return this->studentLastName;
}
string Student::GetStudentEmail() {
	return this->studentEmail;
}
int Student::GetStudentAge() {
	return this->studentAge;
}
int* Student::GetNumDaysToComplete() {
	return this->daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() {
	return this->degreeProgram;
}

//mutators
void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::SetStudentFirstName(string studentFirstName) {
	this->studentFirstName = studentFirstName;
}
void Student::SetStudentLastName(string studentLastName) {
	this->studentLastName = studentLastName;
}
void Student::SetStudentEmail(string studentEmail) {
	this->studentEmail = studentEmail;
}
void Student::SetStudentAge(int studentAge) {
	this->studentAge = studentAge;
}
void Student::SetNumDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < daysArrayLen; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//for ease of comprehension
void Student::PrintHeader() {
	cout << "Format: Student ID|First Name|Last Name|Email|Age|Days to Complete Courses|Degree Program"
		<< endl;
}

void Student::Print() {
	cout << this->GetStudentID() << '\t';
	cout << this->GetStudentFirstName() << '\t';
	cout << this->GetStudentLastName() << '\t';
	cout << this->GetStudentEmail() << '\t';
	cout << this->GetStudentAge() << '\t';
	cout << this->GetNumDaysToComplete()[0] << ',';
	cout << this->GetNumDaysToComplete()[1] << ',';
	cout << this->GetNumDaysToComplete()[2] << '\t';
	cout << degreeProgramStrings[this->GetDegreeProgram()] << endl;
}