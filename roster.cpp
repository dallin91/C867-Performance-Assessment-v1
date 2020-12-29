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
	double days1 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double days2 = stod(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double days3 = stod(studentData.substr(lhs, rhs - lhs));

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
	int age, double daysToComplete1, double daysToComplete2, double daysToComplete3,
	DegreeProgram degreeProgram) {
	double daysArr[3] = { daysToComplete2, daysToComplete2, daysToComplete3 };

	rosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email,
		age, daysArr, degreeProgram);
}

void Roster::remove(string studentID) {
	bool success = false;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (rosterArray[i]->GetStudentID() == studentID) {
			success = true;

			if (i < numStudents - 1) {
				Student* temp = rosterArray[i];
				rosterArray[i] = rosterArray[numStudents - 1];
				rosterArray[numStudents - 1] = temp;
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
		cout << rosterArray[i]->GetStudentID() << '\t';
		cout << rosterArray[i]->GetStudentFirstName() << '\t';
		cout << rosterArray[i]->GetStudentLastName() << '\t';
		cout << rosterArray[i]->GetStudentEmail() << '\t';
		cout << rosterArray[i]->GetStudentAge() << '\t';
		cout << rosterArray[i]->GetNumDaysToComplete()[0] << '\t';
		cout << rosterArray[i]->GetNumDaysToComplete()[1] << '\t';
		cout << rosterArray[i]->GetNumDaysToComplete()[2] << '\t';
		cout << degreeProgramStrings[rosterArray[i]->GetDegreeProgram()] << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	double average = 0.0;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		string tempID = rosterArray[i]->GetStudentID();
		if (tempID == studentID) {
			average = (rosterArray[i]->GetNumDaysToComplete()[0] + rosterArray[i]->GetNumDaysToComplete()[1]
				+ rosterArray[i]->GetNumDaysToComplete()[2]) / 3;
			cout << "Student ID: " << studentID << endl;
			cout << "Average number of days to complete course: " << average << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string invalidEmail = rosterArray[i]->GetStudentEmail();
		if ((invalidEmail.find(".") == string::npos || invalidEmail.find("@") == string::npos) ||
			(invalidEmail.find(" ") != string::npos)) {
			cout << invalidEmail << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	Student::PrintHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::rosterArray[i]->GetDegreeProgram() == degreeProgram) {
			rosterArray[i]->Print();
		}
	}

	cout << endl;
}

Roster::~Roster() {
	cout << "Destructor initiated" << endl;

	for (int i = 0; i < numStudents; i++) {
		delete rosterArray[i];
		rosterArray[i] = nullptr;
	}
}