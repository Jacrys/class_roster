#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
	private:
		string _student_id;
		string _first_name;
		string _last_name;
		string _email_address;
		int _age;
		int _days_to_complete[3];
		DegreeProgram _degree_program;
	public:
		Student();

		Student(string id, string fname, string lname, string email, int age, int days[3], DegreeProgram dp);

		string student_id();
		void student_id(string id);
		
		string first_name();
		void first_name(string fname);
		
		string last_name();
		void last_name(string lname);
		
		string email_address();
		void email_address(string email);
		
		int age();
		void age(int age);
		
		int * days_to_complete();
		void days_to_complete(int days[3]);
		
		DegreeProgram degree_program();
		void degree_program(DegreeProgram dp);

		void print();

		static string print_dp(DegreeProgram dp);

		~Student();
};