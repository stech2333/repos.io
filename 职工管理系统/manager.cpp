#include"manager.h"
manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->name = name;
	this->m_DeptId = did;
}
void manager::showinfo()
{
	cout << "ְ����ţ�" << this->m_id << endl;
	cout << "\tְ��������" << this->name << endl;
	cout << "\t��λ��" << this->getDeptname();
	cout << "\t��λְ������ϰ��������" << endl;
}
string manager::getDeptname()
{
	return string("����");
}