//Filename: Homework10_CCourse
//Programmer:  Haolin Li                                          CSCI 123, Fall 2016
//Project #x                                                                   Instructor:  Timothy Mai
//Due Date: 10/29/2016                                                                  Date Submitted:
//Program Description: class definition of CCourse
#ifndef CCOURSE_H
#define CCOURSE_H
#include <iostream>
#include <string>

using namespace std;

class CCourse
{
private:
	int NumofStudents = 0;;
public:
	string CRN, Title, StudentIDs[5];
	int Units;
	CCourse(const CCourse &obj);
	CCourse();
	~CCourse();
	CCourse(string, string, int, int, string, string, string, string ,string);
	friend istream& operator>>(istream& input, CCourse& c);
	friend ostream& operator<<(ostream& output, const CCourse &c);
	void setCRN(string);
	void increaseStudents(int);
	void decreaseStudents(int);
	void setStudents(int);
	int getUnits() const;
	int Numofstu() const;
};

#endif