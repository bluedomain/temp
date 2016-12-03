//Filename: Homework10_Cstudentinfo
//Programmer:  Haolin Li                                         CSCI 123, Fall 2016
//Project #x                                                                   Instructor:  Timothy Mai
//Due Date:  10/29/2016                                                                 Date Submitted:
//Program Description: class definition of CStudentInfo
#ifndef STUDENT_INFO
#define STUDENT_INFO
#include <string>
#include <iostream>
#include <cstring>

using namespace std;
enum YearTerm{UNKNOWN, FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

class CStudentInfo
{
private:
	YearTerm Term;
public:
	string ID, FirstName, LastName, CourseIDs[4];
	char MiddleInitial = '\0';
	int EnrolledUnits;
	CStudentInfo();
	~CStudentInfo();
	CStudentInfo(string, string, char middle, string, int, YearTerm, string, string, string, string);
	CStudentInfo(const CStudentInfo &obj);
	friend ostream& operator<<(ostream& output, const CStudentInfo& c);
	friend istream& operator>>(istream& input, CStudentInfo& c);
	friend ostream& operator<<(ostream& output, const YearTerm term);
	void setTerm(YearTerm);
	string showID() const;
	YearTerm getTerm() const;
	friend istream& operator >> (istream& input, YearTerm& term);
};

#endif