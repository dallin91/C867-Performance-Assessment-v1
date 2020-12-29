#include <iostream>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;


int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Dallin,Reeves,dreev47@wgu.edu,29, 33, 27, 58,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();
	cout << endl;

	cout << "Invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.rosterArray[i]->GetStudentID());
	}
	cout << endl;

	//printing students in SOFTWARE program
	cout << "SOFTWARE degree students: " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing student ID A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Updated list of Students: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Verifying removal of student ID A3: " << endl;
	classRoster.remove("A3");
	cout << endl;


	return 0;
}