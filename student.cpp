#include <iostream>
#include "student.h"
using namespace std;

Student::Student() {

}

Student::Student(string id, string fname, string lname, string email, int age, int days[3], DegreeProgram dp) {
	_student_id = id;
	_first_name = fname;
	_last_name = lname;
	_email_address = email;
	_age = age;
	for (int i = 0; i < 3; ++i) {
		_days_to_complete[i] = days[i];
	}
	_degree_program = dp;
}

string Student::student_id() {
	return _student_id;
}
void Student::student_id(string id) {
	_student_id = id;
}

string Student::first_name() {
	return _first_name;
}
void Student::first_name(string fname) {
	_first_name = fname;
}

string Student::last_name() {
	return _last_name;
}
void Student::last_name(string lname) {
	_last_name = lname;
}

string Student::email_address() {
	return _email_address;
}
void Student::email_address(string email) {
	_email_address = email;
}

int Student::age() {
	return _age;
}
void Student::age(int age) {
	_age = age;
}

int* Student::days_to_complete() {
	return _days_to_complete;
}
void Student::days_to_complete(int days[3]) {
	for (int i = 0; i < 3; ++i) {
		_days_to_complete[i] = days[i];
	}
}

DegreeProgram Student::degree_program() {
	return _degree_program;
}
void Student::degree_program(DegreeProgram dp) {
	_degree_program = dp;
}

void Student::print() {
	string ageStr = "";

	if (email_address().length() < 18) {
		ageStr = "\t\tAge:";
	}
	else {
		ageStr = "\tAge:";
	}

	cout << _student_id << "\tFirst Name: " << _first_name << "\tLast Name: " << _last_name;
	cout << "\tEmail: " << _email_address << ageStr << _age << "\tdaysInCourse: {" << _days_to_complete[0] << ", " << _days_to_complete[1] << ", " << _days_to_complete[2] << "}\t";
	cout << "Degree Program: " << print_dp(_degree_program) << endl;
}

string Student::print_dp(DegreeProgram dp) {
	switch (dp) {
	case DegreeProgram::SECURITY:
		return "Security";
	case DegreeProgram::NETWORK:
		return "Network";
	case DegreeProgram::SOFTWARE:
		return "Software";
	default:
		throw runtime_error("Invalid DegreeProgram Value");
	}
}

Student::~Student()
{
}
