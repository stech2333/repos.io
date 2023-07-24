#pragma once
#include<iostream>
#include<string>
using namespace std;


//职工抽象基类
class worker
{
public:
	int m_id;//职工编号
    int m_DeptId;//职工所在部门编号
	string name;//职工姓名

	virtual void showinfo() = 0;
	//显示个人信息
	virtual string getDeptname() = 0;
	//职工部门
};