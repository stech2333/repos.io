#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->name = name;
	this->m_DeptId = did;
}
void boss::showinfo()
{
	cout << "ְ����ţ�" << this->m_id << endl;
	cout << "\tְ��������" << this->name << endl;
	cout << "\t��λ��" << this->getDeptname();
	cout << "\t��λְ�𣺹���˾��������" << endl;
}
string boss::getDeptname()
{
	return string("�ϰ�");
}