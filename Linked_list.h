//Definitions of linked list used in Project 4
#ifndef LINKED_LIST
#define LINKED_LIST
#include "CDepartment.h"
using namespace std;

struct CSnode
{
	CStudentInfo data;
	CSnode* next;
};

struct CCnode
{
	CCourse data;
	CCnode* next;
};

struct CDnode
{
	CDepartment data;
	CDnode* next;
};

typedef CCnode* CCp;
typedef CSnode* CSp;
typedef CDnode* CDp;

//CCourse linked list functions
void CC_head_insert(CCp &head, const CCourse& obj);

//CStudentInfo linked list functions
void CS_head_insert(CSp &head, const CStudentInfo& obj);

void CD_head_insert(CDp &head, const CDepartment& obj);

#endif
