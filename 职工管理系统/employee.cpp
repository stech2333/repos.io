#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->name = name;
	this->m_DeptId = did;
}
void Employee::showinfo()
{
	cout << "ְ����ţ�" << this->m_id << endl;
	cout << "\tְ��������" << this->name << endl;
	cout << "\t��λ��" << this->getDeptname();
	cout << "\t��λְ����ɾ����������" << endl;
}
string Employee::getDeptname()
{
	return string("Ա��");
}