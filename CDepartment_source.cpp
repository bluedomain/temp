#include "CDepartment.h"

CDepartment::CDepartment() {}

CDepartment::~CDepartment () {}

CDepartment::CDepartment(string id, string depart)
{
	ID = id;
	Depart = depart;
}

ostream& operator << (ostream& output, const CDepartment& obj)
{
	output << obj.ID << "  " << obj.Depart << endl;
	return output;
}