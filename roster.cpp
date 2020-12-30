#include "roster.h"

void Roster::parse(string studentData) {

	//parse student ID
	int rhs = studentData.find(",");
	string stuID = studentData.substr(0, rhs);

	//parse first name
	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fName = studentData.substr(lhs, rhs - lhs);

	//parse last name
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lName = studentData.substr(lhs, rhs - lhs);

	//parse email
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);

	//parse age
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string tempAge = studentData.substr(lhs, rhs - lhs);
	int age = stoi(tempAge);

	//parse days to complete 
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days1 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days2 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days3 = stoi(studentData.substr(lhs, rhs - lhs));

	//parse degree program
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	DegreeProgram degree;
	string degreeStr = studentData.substr(lhs, rhs - lhs);
	if (degreeStr == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (degreeStr == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (degreeStr == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}


	add(stuID, fName, lName, email, age, days1, days2, days3, degree);
}

void Roster::add(string studentID, string firstName, string lastName, string email,
	int age, int daysToComplete1, int daysToComplete2, int daysToComplete3,
	DegreeProgram degreeProgram) {
	int daysArr[3] = { daysToComplete2, daysToComplete2, daysToComplete3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email,
		age, daysArr, degreeProgram);
}

void Roster::remove(string studentID) {
	bool success = false;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			success = true;

			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; //decreases index by 1, getting rid of the last index
		}
	}
	if (success) {
		cout << studentID << " removed from roster." << endl;
		this->printAll();
	}
	else {
		cout << studentID << " not found on roster." << endl;
	}
}

void Roster::printAll() {
	Student::PrintHeader(); //prints header from student class to improve comprehension

	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->GetStudentID() << '\t';
		cout << classRosterArray[i]->GetStudentFirstName() << '\t';
		cout << classRosterArray[i]->GetStudentLastName() << '\t';
		cout << classRosterArray[i]->GetStudentEmail() << '\t';
		cout << classRosterArray[i]->GetStudentAge() << '\t';
		cout << classRosterArray[i]->GetNumDaysToComplete()[0] << '\t';
		cout << classRosterArray[i]->GetNumDaysToComplete()[1] << '\t';
		cout << classRosterArray[i]->GetNumDaysToComplete()[2] << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->GetDegreeProgram()] << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int average = 0.0;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		string tempID = classRosterArray[i]->GetStudentID();
		if (tempID == studentID) {
			average = (classRosterArray[i]->GetNumDaysToComplete()[0] + classRosterArray[i]->GetNumDaysToComplete()[1]
				+ classRosterArray[i]->GetNumDaysToComplete()[2]) / 3;
			cout << "Student ID: " << studentID << endl;
			cout << "Average number of days to complete course: " << average << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string invalidEmail = classRosterArray[i]->GetStudentEmail();
		if ((invalidEmail.find(".") == string::npos || invalidEmail.find("@") == string::npos) ||
			(invalidEmail.find(" ") != string::npos)) {
			cout << invalidEmail << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	Student::PrintHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}

	cout << endl;
}

Roster::~Roster() {
	cout << "Destructor initiated" << endl;

	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}