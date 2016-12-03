#include "CCourse.h"
#include <iomanip>

CCourse::CCourse()
{
	CRN = "Z000";
	Title = "None";
	Units = 0;
	NumofStudents = 0;
}

CCourse::CCourse(const CCourse &obj)
{
	CRN = obj.CRN;
	Title = obj.Title;
	Units = obj.Units;
	NumofStudents = obj.NumofStudents;
}

CCourse::~CCourse() {}

istream& operator >> (istream& input, CCourse& c)
{
	input >> c.CRN >> c.Title >> c.Units >> c.NumofStudents;
	return input;
}

ostream& operator<<(ostream& output, const CCourse& c)
{
	output << setw(7) << c.CRN << setw(13) << c.Title << setw(8) << c.Units << setw(16) << c.Numofstu();
	output << setw(15) << c.StudentIDs[0] << setw(15) << c.StudentIDs[1] << setw(15) << c.StudentIDs[2] << setw(15) << c.StudentIDs[3];
	output << setw(15) << c.StudentIDs[4] << endl;
	return output;
}

CCourse::CCourse(string crn, string title, int un, int num, string s1, string s2, string s3, string s4, string s5)
{
	Units = un;
	CRN = crn;
	Title = title;
	NumofStudents = num;
	StudentIDs[0] = s1;
	StudentIDs[1] = s2;
	StudentIDs[2] = s3;
	StudentIDs[3] = s4;
	StudentIDs[4] = s5;
}


void CCourse::setCRN(string crn)
{
	CRN = crn;
}

void CCourse::increaseStudents(int num)
{
	NumofStudents += num;
}

void CCourse::decreaseStudents(int num)
{
	NumofStudents -= num;
}

void CCourse::setStudents(int num)
{
	NumofStudents = num;
}

int CCourse::getUnits() const
{
	return Units;
}

int CCourse::Numofstu() const
{
	return NumofStudents;
}