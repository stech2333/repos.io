#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Workmanager
{
public:
	Workmanager();
	~Workmanager();


	int m_num;//记录职工人数
	bool m_fileisempty;//判断文件是否为空
	worker** m_emparray;//职工数组指针

	int isexist(int id);//查找id职工是否存在
	void showmenu();//菜单函数
	void exitsys();//简单的退出系统函数
	void save();//存储在文件中
	int get_num();//统计人数
	void init_emp();//初始化，从文件中读取，初始化对象数组
	void showall();//显示职工信息
	void add_emp();//添加职工函数
	void find_name();//查找职工
	void del_id();//删除指定id的员工
	void change_name();//修改职工信息
	void sort_emp();//按照序号排列
	void deleteall();//清空文件
};