#include"employee.h"
Employee::Employee(int id, string name, int did)
{
	this->m_id = id;
	this->name = name;
	this->m_DeptId = did;
}
void Employee::showinfo()
{
	cout << "职工编号：" << this->m_id << endl;
	cout << "\t职工姓名：" << this->name << endl;
	cout << "\t岗位：" << this->getDeptname();
	cout << "\t岗位职责：完成经理给的任务" << endl;
}
string Employee::getDeptname()
{
	return string("员工");
}