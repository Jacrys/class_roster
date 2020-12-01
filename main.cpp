// class_roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"

using namespace std;

vector <string> parseStudent(string student, char delim = ',');

int main()
{
    cout << "C867 - Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID# 001114518" << endl;
    cout << "William 'Keith' Lewis" << endl;
    cout << endl;

    const string studentData[] ={ 
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,William,Lewis,wlewi24@wgu.edu,38,21,22,25,SOFTWARE" 
    };

    Roster* classRoster = new Roster;

    for (int i = 0; i < 5; ++i) {
        vector <string> temp = parseStudent(studentData[i]);
        DegreeProgram dp;

        if (temp[8] == "SECURITY") {
            dp = DegreeProgram::SECURITY;
        }
        else if (temp[8] == "NETWORK") {
            dp = DegreeProgram::NETWORK;
        }
        else if (temp[8] == "SOFTWARE") {
            dp = DegreeProgram::SOFTWARE;
        }

        classRoster->add(temp[0], temp[1], temp[2], temp[3], stoi(temp[4]), stoi(temp[5]), stoi(temp[6]), stoi(temp[7]), dp);
    }

    classRoster->printAll();
    cout << endl;
    classRoster->printInvalidEmails();
    cout << endl;
    for (int j = 0; j < 5; ++j) {
        classRoster->printAverageDaysInCourse(studentData[j].substr(0, 2));
    }
    cout << endl;
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    classRoster->remove("A3");
    cout << endl;
    classRoster->printAll();
    cout << endl;
    classRoster->remove("A3");
    cout << endl;

    classRoster->~Roster();
    classRoster = new Roster();
}

vector <string> parseStudent(string student, char delim) {
    vector <string> flatStudent;

    stringstream ss(student);
    string token;

    int days[3];
    DegreeProgram dp;

    while (getline(ss, token, delim)) {
        flatStudent.push_back(token);
    }

    return flatStudent;
}