#include "Linked_list.h"

void CC_head_insert(CCp &head, const CCourse& obj)
{
	CCp temp = new CCnode;
	temp->data = obj;
	temp->next = head;
	head = temp;
}

void CS_head_insert(CSp &head, const CStudentInfo& obj)
{
	CSp temp = new CSnode;
	temp->data = obj;
	temp->next = head;
	head = temp;
}

void CD_head_insert(CDp &head, const CDepartment& obj)
{
	CDp temp = new CDnode;
	temp->data = obj;
	temp->next = head;
	head = temp;
}