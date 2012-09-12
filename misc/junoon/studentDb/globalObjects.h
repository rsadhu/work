#ifndef GLOBALOBJECTS_H
#define GLOBALOBJECTS_H
class student
{
 public:
	student ():m_name(0),m_age(0),m_address(0),m_class(0),m_rollno(0){}
 private:
	char *m_name;
	int m_age;
	char *m_address;
	int m_class;
	int m_rollno;
};

#endif// GLOBALOBJECTS_H
