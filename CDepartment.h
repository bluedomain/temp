#ifndef CDEPART
#define CDEPART
#include <string>
class CDepartment
{
public:
	CDepartment();
	CDepartment(string, string);
	~CDepartment();
	string ID, Depart;
	friend ostream& operator << (ostream& output, const CDepartment& obj);
};

#endif
