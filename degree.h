#pragma once
#include <string>

using namespace std;

enum DegreeProgram {
	UNDECIDED, 
	SECURITY,
	NETWORK,
	SOFTWARE
};

//array to display string version of enum DegreeProgram
//use index number in DegreeProgram to display correct string
static const string degreeProgramStrings[] = { "UNDECIDED", "SECURITY", "NETWORK", "SOFTWARE" };