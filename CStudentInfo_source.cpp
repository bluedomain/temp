#include "CStudentInfo.h"

CStudentInfo::CStudentInfo()
{
	ID = "Z9999";
	FirstName = "None";
	MiddleInitial = '?';
	LastName = "None";
	EnrolledUnits = 0;
	Term = UNKNOWN;
}

CStudentInfo::~CStudentInfo() {}

CStudentInfo::CStudentInfo(string id, string first, char middle, string last, int units, YearTerm term, string c1, string c2, string c3, string c4)
{
	ID = id;
	FirstName = first;
	MiddleInitial = middle;
	LastName = last;
	EnrolledUnits = units;
	Term = term;
	CourseIDs[0] = c1;
	CourseIDs[1] = c2;
	CourseIDs[2] = c3;
	CourseIDs[3] = c4;
}

YearTerm CStudentInfo::getTerm() const
{
	return Term;
}

istream& operator >> (istream& input, YearTerm& term)
{
	int value;
	if (input >> value)
	{
		term = static_cast<YearTerm>(value);
	}
	return input;
}

ostream& operator << (ostream& output, const YearTerm term)
{
	switch (term)
	{
	case 1:
		output << "FRESHMAN";
		break;
	case 2:
		output << "SOPHOMORE";
		break;
	case 3:
		output << "JUNIOR";
		break;
	case 4:
		output << "SENIOR";
		break;
	default:
		output << "UNKNOWN\n";
		break;
	}
	return output;
}

ostream& operator << (ostream& output, const CStudentInfo& c)
{
	output << setw(8) << c.ID << setw(15) << c.FirstName << setw(18) << c.MiddleInitial << setw(15) << c.LastName;
	output << setw(18) << c.EnrolledUnits << setw(12) << c.getTerm() << setw(15) << c.CourseIDs[0];
	output << setw(15) << c.CourseIDs[1] << setw(15) << c.CourseIDs[2] << setw(15) << c.CourseIDs[3] << endl;
	return output;
}

istream& operator >> (istream& input, CStudentInfo& c)
{
	input >> c.ID >> c.FirstName >> c.MiddleInitial >> c.LastName >> c.EnrolledUnits >> c.Term;
	return input;
}

CStudentInfo::CStudentInfo(const CStudentInfo &obj)
{
	ID = obj.ID;
	FirstName = obj.FirstName;
	MiddleInitial = obj.MiddleInitial;
	LastName = obj.LastName;
	EnrolledUnits = obj.EnrolledUnits;
	Term = obj.Term;

}

void CStudentInfo::setTerm(YearTerm tt)
{
	Term = tt;
}

string CStudentInfo::showID() const
{
	return ID;
}
