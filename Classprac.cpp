//Filename: Project 5 source code
//Programmer:  Haolin Li                                        CSCI 123, Fall 2016
//Project #4                                                    Instructor:  Timothy Mai
//Due Date: 12/3/2016                                          Date Submitted:
//Program Description: College class enrollement system using c++ class and linked list, including important ideas like operator overloading, constructor, head insertion.
#include "stdafx.h"
#include <fstream>
#include "CCourse.h"
#include "CCourse_source.cpp"
#include "CStudentInfo.h"
#include "CStudentInfo_source.cpp"
#include "CDepartment.h"
#include "CDepartment_source.cpp"
#include "Linked_list.h"
#include "Linked_source.cpp"
#include <iomanip>

CCnode *cchead;
CSnode *cshead;
CDnode *cdhead;

void readCourseInfo();
void readStudentInfo();
void writeCourseInfo();
void writeStudentInfo();
int menu();
void listAllCourses();
void listCoursesOfSpecificDepartment();
void listCoursesWithLessSpecificUnit();
void listCoursesWithEqualSpecificUnit();
void listCoursesWithMoreSpecificUnit();
void listCoursesWithSpecificTitle();
void listCourseInfoWithSpecificCrn();
void listAllStudents();
void listAllStudentInfoWithSpecificTerm();
void listAllStudentInfoWithSpecificLastName();
void listStudentInfoWithSpecificId();
void Enroll();
void Quit();
void adddepart();
void addcourse();
void cancelcourse();
void listinfospecific();
void readDepart();
void writeDepart();
void listalldepartments();
void dropcourse();

void main()
{
	// Read Student information from the file Students.dat
	readStudentInfo();
	cout.setf(ios::left);
	// Read course information from the file Courses.dat
	readCourseInfo();
	readDepart();
	int choice;
	do {
		system("CLS");
		choice = menu();

		switch (choice) {
		case 1:
			listAllCourses();
			break;
		case 2:
			listCoursesOfSpecificDepartment();
			break;
		case 3:
			listCoursesWithLessSpecificUnit();
			break;
		case 4:
			listCoursesWithEqualSpecificUnit();
			break;
		case 5:
			listCoursesWithMoreSpecificUnit();
			break;
		case 6:
			listCoursesWithSpecificTitle();
			break;
		case 7:
			listCourseInfoWithSpecificCrn();
			break;
		case 8:
			listAllStudents();
			break;
		case 9:
			listAllStudentInfoWithSpecificTerm();
			break;
		case 10:
			listAllStudentInfoWithSpecificLastName();
			break;
		case 11:
			listStudentInfoWithSpecificId();
			break;
		case 12:
			Enroll();
			break;
		case 13:
			adddepart();
			break;
		case 14:
			addcourse();
			break;
		case 15:
			cancelcourse();
			break;
		case 16:
			listinfospecific();
			break;
		case 17:
			listalldepartments();
			break;
		case 18:
			dropcourse();
			break;
		case 19:
			Quit();
			break;
		default:
			cout << "That was an invalid choice, please try again! \n";
		}
		system("PAUSE");
	} while (choice > 0 && choice < 19);
}

int menu()
{
	int option;
	cout << "             COLLEGE ENROLLMENT SYSTEM \n\n";
	cout << "1.  List All Courses. \n";
	cout << "2.  List All Courses Of A Specific Department. \n";
	cout << "3.  List All Courses With Number Of Units Less Than A Specific Number. \n";
	cout << "4.  List All Courses With A Specific Number Of Units. \n";
	cout << "5.  List All Courses With Number Of Units More Than A Specific Number. \n";
	cout << "6.  List All Courses With A Specific Title. \n";
	cout << "7.  List Course Information With CRN. \n";
	cout << "8.  List All Students.\n";
	cout << "9.  List All Students With A Specific Year Term. \n";
	cout << "10. List All Students With A Specific Last Name. \n";
	cout << "11. List Student Information With ID. \n";
	cout << "12. Enroll Into A Course. \n";
	cout << "13. Add a department. \n";
	cout << "14. Add a course. \n";
	cout << "15. Cancel a course. \n";
	cout << "16. List information of all students enrolled in a specific course.\n";
	cout << "17. List all departments. \n";
	cout << "18. Drop a course\n";
	cout << "19. Quit. \n\n";
	cout << "Please select your option: ";
	cin >> option;
	while (option < 1 || option > 19)
	{
		cout << "Invalid option!!! Please select valid option: ";
		cin >> option;
	}
	return option;
}

void Quit()
{
	// Write Student information back to the file Students.dat
	writeStudentInfo();
	// Write Course information back to the file Courses.dat
	writeCourseInfo();
	writeDepart();
	//delete linked lists
	CCnode *cctemp = cchead;
	while (cctemp != NULL)
	{
		CCnode *dele = cctemp;
		cctemp = cctemp->next;
		delete dele;
	}
	CSnode *cstemp = cshead;
	
	while (cstemp != NULL)
	{
		CSnode *csdele = cstemp;
		cstemp = cstemp->next;
		delete csdele;
	}
	
	CDnode* cdtemp = cdhead;
	while (cdtemp != NULL)
	{
		CDnode *cddele = cdtemp;
		cdtemp = cdtemp->next;
		delete cddele;
	}
	cout << "Have a nice day \n\n";
}

void listAllCourses()
{
	CCnode *temp = cchead;
	cout << "CRN    " << "Title        " << "Units   " << "NumberOfStudents\n";
	while (temp != NULL)
	{
		cout << setw(7) << temp->data.CRN << setw(13) << temp->data.Title << setw(8) << temp->data.Units << setw(16) << (temp->data).Numofstu() << endl;
		temp = temp->next;
	}

}
void listCoursesOfSpecificDepartment()
{
	int found = 0;
	CDnode *cdtemp = cdhead;
	CCnode *temp = cchead;
	string id;
	cout << "Please enter the ID of the department. ";
	cin >> id;
	while (cdtemp != NULL)
	{
		if ((cdtemp->data).ID == id)
			found = 1;
		cdtemp = cdtemp->next;
	}
	if (found != 1)
	{
		cout << "Error, No such department.\n";
		return;
	}
	while (temp != NULL)
	{
		if (temp->data.Title.find(id) != string::npos)
		{
			cout << "CRN: " << temp->data.CRN << " " << "Title: " << temp->data.Title << " ";
			cout << "Units: " << temp->data.getUnits() << endl;
		}
		temp = temp->next;
	}
}

void listCoursesWithLessSpecificUnit()
{
	int choice, found = 0;
	CCnode *temp = cchead;
	cout << "Please enter the number of units(number should not be less than 0): ";
	while (cin >> choice)
	{
		if (choice < 0)
			cout << "You've entered an invalid number!\n, please enter another number.\n";
		else
			break;
	}
	cout << "CRN    " << "Title        " << "Units   " << "NumberOfStudents\n";
	while (temp != NULL)
	{
		if (((temp->data).Units) < choice)
		{
			cout << setw(7) << temp->data.CRN << setw(13) << temp->data.Title << setw(8) << temp->data.Units << setw(16) << (temp->data).Numofstu() << endl;
			found += 1;
		}
		temp = temp->next;
	}
	if (found == 0)
		cout << "No courses meet the requirement\n";
}

void listCoursesWithEqualSpecificUnit()
{
	cout << "Please enter the number of the unit: ";
	CCnode *temp = cchead;
	int un, count = 0;
	while (cin >> un)
	{
		if (un < 0)
			cout << "You've entered an invalid number of unit, please enter another number\n";
		else
			break;
	}
	while (temp != NULL)
	{
		if (temp->data.Units == un)
		{
			cout << setw(7) << temp->data.CRN << setw(13) << temp->data.Title << setw(8) << temp->data.Units << setw(16) << (temp->data).Numofstu() << endl;
			count += 1;
		}
		temp = temp->next;
	}
	if (count == 0)
		cout << "No courses meet the requirement\n";
}

void listCoursesWithMoreSpecificUnit()
{
	cout << "Please enter the number of unit(Number should not be less than 0): ";
	int un, found = 0;
	CCnode *temp = cchead;
	while (cin >> un)
	{
		if (un < 0)
			cout << "You've entered a number which is less than 0\n";
		else
			break;
	}
	cout << "CRN    " << "Title        " << "Units   " << "NumberOfStudents\n";
	while (temp != NULL)
	{
		if ((temp->data.Units) > un)
		{
			cout << setw(7) << temp->data.CRN << setw(13) << temp->data.Title << setw(8) << temp->data.Units << setw(16) << (temp->data).Numofstu() << endl;
			found += 1;
		}
		temp = temp->next;
	}
	if (found == 0)
		cout << "No courses meet the requirement\n";
}

void listCoursesWithSpecificTitle()
{
	string ti;
	int found = 0;
	CCnode *temp = cchead;
	cout << "Please enter the title: ";
	while (1)
	{
		cin >> ti;
		while (temp != NULL)
		{
			if (temp->data.Title == ti)
			{
				cout << temp->data.CRN << endl;
				found = 1;
			}
			temp = temp->next;
		}
		if (found == 1)
			break;
		else
			cout << "Course not found!\n";
	}
}

void listCourseInfoWithSpecificCrn()
{
	cout << "Please enter the crn: ";
	string cr;
	int found = 0;
	CCnode *temp = cchead;
	cin >> cr;
	while (temp != NULL)
	{
		if ((temp->data.CRN) == cr)
		{
			cout << "Title: " << temp->data.Title << "  " << "Units: " << temp->data.Units << "  " << "Number of Students: " << temp->data.Numofstu() <<
				"  " << temp->data.StudentIDs[0] << "  " << temp->data.StudentIDs[1] << "  " << temp->data.StudentIDs[2] << "  " << temp->data.StudentIDs[3]
				<< "  " << temp->data.StudentIDs[4] << endl;
			found = 1;
			break;
		}
		temp = temp->next;
	}
	if (found != 1)
		cout << "Course not found\n";
}

void listAllStudents()
{
	CSnode *temp = cshead;
	cout << "ID      First Name     Middle Initial    Last Name      Enrolled Units    Term    Course1        Course2        Course3        Course4        \n";
	while (temp != NULL)
	{
		cout << setw(8) << temp->data.ID << setw(15) << temp->data.FirstName << setw(18) << temp->data.MiddleInitial << setw(15) << temp->data.LastName;
		cout << setw(18) << temp->data.EnrolledUnits << setw(8) << temp->data.getTerm() << setw(15) << temp->data.CourseIDs[0] << setw(15) << temp->data.CourseIDs[1] 
			<< setw(15) << temp->data.CourseIDs[2] << setw(15)
			<< temp->data.CourseIDs[3] << endl;
		temp = temp->next;
	}
}

void listAllStudentInfoWithSpecificTerm()
{
	cout << "Enter the year term(1 correspond to freshman, 2 to sophomore, 3 to junior, 4 to senior): ";
	YearTerm term;
	int te;
	while (cin >> te)
	{
		if ((te != 1) && (te != 2) && (te != 3) && (te != 4))
			cout << "You've entered an invalid number, please enter another number\n";
		else
		{
			term = static_cast<YearTerm>(te);
			break;
		}
	}
	CSnode *temp = cshead;
	cout << "ID      First Name     Middle Initial    Last Name      Enrolled Units    Term\n";
	while (temp != NULL)
	{
		if ((temp->data.getTerm()) == term)
		{
			cout << setw(8) << temp->data.ID << setw(15) << temp->data.FirstName << setw(18) << temp->data.MiddleInitial << setw(15) << temp->data.LastName;
			cout << setw(18) << temp->data.EnrolledUnits << setw(8) << temp->data.getTerm() << endl;;
		}
		temp = temp->next;
	}
}

void listAllStudentInfoWithSpecificLastName()
{
	int found = 0, choice;
	string last;
	CSnode *temp = cshead;
	cout << "Please enter the last name: ";
	while (cin >> last)
	{
		while (temp != NULL)
		{
			if (temp->data.LastName == last)
			{
				cout << "ID: " << temp->data.ID << " " << "First Name: " << temp->data.FirstName << " " << "Middle Initial: " << temp->data.MiddleInitial << " ";
				cout << "Last Name: " << temp->data.LastName << " " << "Enrolled Units: " << temp->data.EnrolledUnits << " " << "Term: " << temp->data.getTerm() << endl;
				found = 1;
			}
			temp = temp->next;
		}
		if (found == 1)
			break;
		else
		{
			cout << "Student not found! Enter another last name \n";
			cout << "Are you looking for " << last << "?\n";
			cout << "1 for yes, 2 for no";
			cin >> choice;
			if (choice == 2)
				break;
			temp = cshead;
		}
	}
}

void listStudentInfoWithSpecificId()
{
	int found = 0;
	string id;
	CSnode *temp = cshead;
	cout << "Please enter your ID: ";
	while (cin >> id)
	{
		while (temp != NULL)
		{
			if ((temp->data.ID) == id)
			{
				cout << temp->data.ID << "  " << temp->data.FirstName << "  " << temp->data.MiddleInitial << "  " << temp->data.LastName;
				cout << "  " << temp->data.EnrolledUnits << "  " << temp->data.getTerm() << "  " << temp->data.CourseIDs[0] << "  " << 
					temp->data.CourseIDs[1] << "  " << temp->data.CourseIDs[2] << "  " << temp->data.CourseIDs[3] << endl;
				found = 1;
				break;
			}
			temp = temp->next;
		}
		if (found == 1)
			break;
		else
		{
			cout << "Student not found Please enter another ID\n";
			temp = cshead;
		}
	}
}

void Enroll()
{
	string id, crn;
	int found = 0, match = 0, over = 0, nops = 0, choice;
	CSnode *cstemp = cshead;
	CCnode *cctemp = cchead;
	cout << "Please enter your student ID to start course enrollment: ";
	while (cin >> id)
	{
		while (cstemp != NULL)
		{
			if ((cstemp->data.ID) == id)
			{	
				found = 1;
				break;
			}
			cstemp = cstemp->next;
		}
		if (found == 1)
			break;
		else
		{
			cout << "Student not found!\n";
			return;
		}
	}
	cout << "Please enter the crn of the course you want to enroll in: ";
	while (cin >> crn)
	{
		while (cctemp != NULL)
		{
			if ((cctemp->data.CRN) == crn)
			{
				for (int i = 0; i < 5; i++)
				{
					if (cctemp->data.StudentIDs[i] == cstemp->data.ID)
					{
						cout << "Error, you've already enrolled into the course.\n";
						return;
					}
				}
				if ((cstemp->data.EnrolledUnits == 12) || (cstemp->data.EnrolledUnits + 3 > 12))
				{
					cout << "Reach the limit of units. You can't enroll in any course\n";
					return;
				}
				else if ((cstemp->data.EnrolledUnits + (cctemp->data.Units) <= 12) && (cctemp->data.Numofstu() < 5))
				{
					cctemp->data.increaseStudents(1);
					for (int i = 0; i < 5; i++)
					{
						if (cctemp->data.StudentIDs[i] == "N/A")
						{
							cctemp->data.StudentIDs[i] = cstemp->data.ID;
							break;
						}
					}
					for (int j = 0; j < 4; j++)
					{
						if (cstemp->data.CourseIDs[j] == "N/A")
						{
							cstemp->data.CourseIDs[j] = cctemp->data.CRN;
							break;
						}
					}
					(cstemp->data.EnrolledUnits) += (cctemp->data.Units);
					cout << "Successfully enrolled in the course.\n";
					match = 1;
					break;
				}
				else
				{
					if (cctemp->data.Numofstu() == 5)
					{
						cout << "No position left.\n";
						nops = 1;
					}
					break;
				}
			}
			cctemp = cctemp->next;
		}
		if (nops == 1)
			break;
		if ((match == 1) || (over == 1))
			break;
		if ((over != 1) && (match != 1))
		{
			cout << "Are you looking for " << crn << "?\n";
			cout << "1 for yes, 2 for no\n";
			cin >> choice;
			if (choice == 2)
				break;
		}
		cctemp = cchead;
	}
}

void readStudentInfo()
{
	ifstream read;
	read.open("Students.dat");
	if (read.fail())
	{
		cout << "Failed to read informations of students, program exited\n";
		exit(1);
	}
	YearTerm tm;
	int count = 0, units;
	string id, first, last, term, c1, c2, c3, c4;
	char middle;
	while (read >> id >> first >> middle >> last >> units >> term >> c1 >> c2 >> c3 >> c4)
	{
		count += 1;
		if (term == "FRESHMAN")
			tm = static_cast<YearTerm>(1);
		else if (term == "SOPHOMORE")
			tm = static_cast<YearTerm>(2);
		else if (term == "JUNIOR")
			tm = static_cast<YearTerm>(3);
		else
			tm = static_cast<YearTerm>(4);
		if (count == 1)
		{
			cshead = new CSnode;
			cshead->data = CStudentInfo(id, first, middle, last, units, tm, c1, c2 ,c3 ,c4);
			cshead->next = NULL;
		}
		if (count > 1)
			CS_head_insert(cshead, CStudentInfo(id, first, middle, last, units, tm, c1, c2, c3, c4));
	}
}

void writeStudentInfo()
{
	ofstream write;
	write.setf(ios::left);
	CSnode *temp = cshead;
	write.open("Students.dat");
	if (write.fail())
	{
		cout << "Failed to write informations of students. Program exited";
		exit(1);
	}
	while (temp != NULL)
	{
		write << temp->data;
		temp = temp->next;
	}
}

void readCourseInfo()
{
	ifstream read;
	read.open("Courses.dat");
	if (read.fail())
	{
		cout << "Failed to read informations of courses, program exited";
		exit(1);
	}
	string crn, title, s1, s2 ,s3 ,s4, s5;
	int units, num, count = 0;
	while (read >> crn >> title >> units >> num >> s1 >> s2 >> s3 >> s4 >> s5)
	{
		count += 1;
		if (count == 1)
		{
			cchead = new CCnode;
			cchead->data = CCourse(crn, title, units, num, s1, s2, s3, s4, s5);
			cchead->next = NULL;
		}
		if (count > 1)
		{
			CCourse data(crn, title, units, num, s1, s2 ,s3, s4 ,s5);
			CC_head_insert(cchead, data);
		}
	}
}

void writeCourseInfo()
{
	ofstream write;
	write.setf(ios::left);
	CCnode* temp = cchead;
	write.open("Courses.dat");
	if (write.fail())
	{
		cout << "Failed to write informations of courses. Program exited";
		exit(1);
	}
	while (temp != NULL)
	{
		write << temp->data;
		temp = temp->next;
	}
}

void readDepart()
{
	ifstream read;
	read.open("Departments.dat");
	if (read.fail())
	{
		cout << "Failed to read the informations of departments\n. Program exited";
		exit(1);
	}
	string id, depart;
	int count = 0;
	while (read >> id >> depart)
	{
		count += 1;
		if (count == 1)
		{
			cdhead = new CDnode;
			cdhead->data = CDepartment(id, depart);
			cdhead->next = NULL;
		}
		if (count > 1)
		{
			CDepartment data(id, depart);
			CD_head_insert(cdhead, data);
		}
	}
}

void writeDepart()
{
	ofstream write;
	write.open("Departments.dat");
	if (write.fail())
	{
		cout << "Failed to write information of department.";
		exit(1);
	}
	write.setf(ios::left);
	CDnode* temp = cdhead;
	while (temp != NULL)
	{
		write << temp->data;
		temp = temp->next;
	}
}

void adddepart()
{
	string id, depart;
	CDnode* temp = cdhead;
	cout << "Please enter the ID of the department: ";
	cin >> id;
	while (temp != NULL)
	{
		if (id == temp->data.ID)
		{
			cout << id << "already exists\n";
			break;
		}
		temp = temp->next;
	}
	cout << "Please enter the name of the department: ";
	cin >> depart;
	CD_head_insert(cdhead, CDepartment(id, depart));
}

void addcourse()
{
	CCnode* temp = cchead;
	string crn, title;
	int units;
	cout << "Please enter the title of the course: ";
	cin >> title;
	cout << "Please enter the crn of the course: ";
	cin >> crn;
	while (temp != NULL)
	{
		if ((temp->data.CRN) == crn)
		{
			cout << "The course already exists.";
			return;
		}
		temp = temp->next;
	}
	cout << "Please enter the units of the course. ";
	while (cin >> units)
	{
		if (units < 1)
		{
			cout << "Unit shouldn't be less than 1\n";
			continue;
		}
		else
			break;
	}
	CC_head_insert(cchead, CCourse(crn, title, units, 0, "N/A", "N/A", "N/A", "N/A", "N/A"));
	cout << "Successfully added course.\n";
}

void cancelcourse()
{
	int found = 0;
	string crn;
	cout << "Please enter the crn of the course: ";
	cin >> crn;
	CCnode *previous = cchead;
	CCnode *temp = previous->next;
	CSnode *cstemp = cshead;
	while (previous != NULL && temp != NULL)
	{
		if (temp->data.CRN == crn)
		{
			while (cstemp != NULL)
			{
				for (int i = 0; i < 4; i++)
				{
					if (cstemp->data.CourseIDs[i] == crn)
					{
						cstemp->data.CourseIDs[i] = "N/A";
						cstemp->data.EnrolledUnits -= temp->data.getUnits();
						temp->data.decreaseStudents(1);
						break;
					}
				}
				cstemp = cstemp->next;
			}
			previous->next = temp->next;
			delete temp;
			found = 1;
			break;
		}
		previous = previous->next;
		temp = temp->next;
	}
	if (found != 1)
		cout << "Error.\n";
}

void listinfospecific()
{
	CCnode *temp = cchead;
	CSnode *cstemp = cshead;
	string crn;
	int found = 0;
	cout << "Please enter the ID(crn) of the course: ";
	cin >> crn;
	while (temp != NULL)
	{
		if (temp->data.CRN == crn)
		{
			found = 1;
			break;
		}
		temp = temp->next;
	}
	if (found != 1)
	{
		cout << "No such course\n";
		return;
	}
	temp = cchead;
	while (temp != NULL)
	{
		if (temp->data.CRN == crn)
		{
			for (int i = 0; i < 5; i++)
			{
				while (cstemp != NULL)
				{
					if ((cstemp->data.ID) == temp->data.StudentIDs[i])
					{
						cout << setw(8) << cstemp->data.ID << setw(15) << cstemp->data.FirstName << setw(18) << cstemp->data.MiddleInitial << setw(15) << cstemp->data.LastName;
						cout << setw(18) << cstemp->data.EnrolledUnits << setw(8) << cstemp->data.getTerm() << endl;
					}
					cstemp = cstemp->next;
				}
			}
		}
		temp = temp->next;
	}
}

void listalldepartments()
{
	CDnode *temp = cdhead;
	while (temp != NULL)
	{
		cout << temp->data.ID << " " << temp->data.Depart << endl;
		temp = temp->next;
	}
}

void dropcourse()
{
	string id, crn;
	int found = 0, cancel = 0;
	CSnode *cstemp = cshead;
	CCnode *cctemp = cchead;
	cout << "Please enter your student ID: ";
	cin >> id;
	while (cstemp != NULL)
	{
		if (cstemp->data.ID == id)
		{
			found = 1;
			break;
		}
		cstemp = cstemp->next;
	}
	if (found != 1)
	{
		cout << "No matched student\n";
		return;
	}
	cstemp = cshead;
	cout << "Please enter the ID(crn) of the course you want to drop: ";
	cin >> crn;
	while (cctemp != NULL)
	{
		if (cctemp->data.CRN == crn)
		{
			found = 1;
			break;
		}
		cctemp = cctemp->next;
	}
	cctemp = cchead;
	if (found != 1)
	{
		cout << "No such course\n";
		return;
	}
	while (cctemp != NULL)
	{
		if (cctemp->data.CRN == crn)
		{
			for (int i = 0; i < 5; i++)
			{
				while (cstemp != NULL)
				{
					if ((cstemp->data.ID) == cctemp->data.StudentIDs[i])
					{
						cstemp->data.EnrolledUnits -= cctemp->data.getUnits();
						cctemp->data.decreaseStudents(1);
						cctemp->data.StudentIDs[i] = "N/A";
						for (int i = 0; i < 4; i++)
						{
							if (cstemp->data.CourseIDs[i] == crn)
							{
								cstemp->data.CourseIDs[i] = "N/A";
								break;
							}
						}
						cout << "Successfully dropped the course.\n";
					}
					cancel = 1;
					cstemp = cstemp->next;
				}
			}
		}
		cctemp = cctemp->next;
	}
}