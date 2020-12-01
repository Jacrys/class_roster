#pragma once
#include <string>
#include "student.h"

using namespace std;

class Roster {
	private:
		Student *_classRosterArray[5];
        int end;

	public:
		Roster();

        void add(string studentID, string firstName, string lastName, string emailAddress,
            int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string StudentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeprogram);

        ~Roster();
};