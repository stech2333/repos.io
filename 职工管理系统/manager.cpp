#include"manager.h"
manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->name = name;
	this->m_DeptId = did;
}
void manager::showinfo()
{
	cout << "职工编号：" << this->m_id << endl;
	cout << "\t职工姓名：" << this->name << endl;
	cout << "\t岗位：" << this->getDeptname();
	cout << "\t岗位职责：完成老板给的任务" << endl;
}
string manager::getDeptname()
{
	return string("经理");
}