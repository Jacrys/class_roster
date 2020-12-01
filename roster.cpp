#include <iostream>
#include <vector>
#include "roster.h"
using namespace std;

Roster::Roster() {
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int n = stoi(studentID.substr(1)) - 1;

	int days[3];

	days[0] = daysInCourse1;
	days[1] = daysInCourse2;
	days[2] = daysInCourse3;

	Student* stu = new Student;
	
	stu->student_id(studentID);
	stu->first_name(firstName);
	stu->last_name(lastName);
	stu->email_address(emailAddress);
	stu->age(age);
	stu->days_to_complete(days);
	stu->degree_program(degreeprogram);

	_classRosterArray[n] = stu;
	end = n + 1;
} 

void Roster::remove(string studentID) {
	for (int i = 0; i < end; ++i) {
		if (this->_classRosterArray[i]) {
			if (this->_classRosterArray[i]->student_id() == studentID) {
				delete _classRosterArray[i];
				this->_classRosterArray[i] = _classRosterArray[end - 1];
				--end;
				cout << "Student ID " << studentID << " successfully removed." << endl;
				return;
			}
		}
	}
	cout << "The requested StudentID was not found in the Class Roster." << endl;
}

void Roster::printAll() {
	for (int i = 0; i < end; i++) {
		this->_classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int *days;
	int sum = 0;

	for (int i = 0; i < end; ++i) {
		if (this->_classRosterArray[i]) {
			if (this->_classRosterArray[i]->student_id() == studentID) {
				days = this->_classRosterArray[i]->days_to_complete();

				for (int j = 0; j < 3; ++j) {
					sum += days[j];
				}

				cout << "The average number of days spent in a course for student " << studentID << " is " << sum / 3 << " days." << endl;
				return;
			}
		}
	}
	cout << "The requested StudentID was not found in the Class Roster." << endl;
}

void Roster::printInvalidEmails() {
	string invalidEmails = "";

	for (int i = 0; i < end; ++i) {
		if (this->_classRosterArray[i]->email_address().find("@") == string::npos || this->_classRosterArray[i]->email_address().find(".") == string::npos || this->_classRosterArray[i]->email_address().find(" ") != string::npos) {
			if (invalidEmails == "") {
				invalidEmails = this->_classRosterArray[i]->email_address();
			}
			else {
				invalidEmails = invalidEmails + ", " + this->_classRosterArray[i]->email_address();
			}
		}
	}

	if (invalidEmails != "") {
		cout << "The following Email Addresses are invalid: " << invalidEmails << endl;
	}
	else {
		cout << "All Email Addresses were valid." << endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	vector <Student *> matchingStudents;

	for (int i = 0; i < end; ++i) {
		if (this->_classRosterArray[i]->degree_program() == degreeProgram) {
			matchingStudents.push_back(this->_classRosterArray[i]);
		}
	}

	cout << Student::print_dp(degreeProgram) << "Degree students: " << endl;
	for (int j = 0; j < matchingStudents.size(); ++j) {
		matchingStudents[j]->print();
	}
}

Roster::~Roster() {
	for (int i = 0; i < end; i++)
	{
		delete this->_classRosterArray[i];
	}
}
