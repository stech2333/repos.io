#pragma once
#include<iostream>
#include<string>
using namespace std;


//ְ���������
class worker
{
public:
	int m_id;//ְ�����
    int m_DeptId;//ְ�����ڲ��ű��
	string name;//ְ������

	virtual void showinfo() = 0;
	//��ʾ������Ϣ
	virtual string getDeptname() = 0;
	//ְ������
};