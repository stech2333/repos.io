#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->name = name;
	this->m_DeptId = did;
}
void boss::showinfo()
{
	cout << "职工编号：" << this->m_id << endl;
	cout << "\t职工姓名：" << this->name << endl;
	cout << "\t岗位：" << this->getDeptname();
	cout << "\t岗位职责：管理公司所有任务" << endl;
}
string boss::getDeptname()
{
	return string("老板");
}