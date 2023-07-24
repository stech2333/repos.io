#include"workmanager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"
#include<fstream>


#define FILENAME "empfile.txt"

Workmanager::Workmanager()
//构造函数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		this->m_num = 0;
		this->m_fileisempty = true;
		this->m_emparray = NULL;
		ifs.close();
		return;
	}

	char ch;//文件存在
	ifs >> ch;
	if (ifs.eof())
	//文件存在，但是文件为空
	{
		cout << "文件为空" << endl;
		this->m_num = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	int num = this->get_num();//获取文件中数量
	this->m_num = num;
	this->m_emparray = new worker * [num];
	this->init_emp();
	//测试代码
	//for (int i = 0; i < num; i++)
	//{
	//	cout<< this->m_emparray[i]->m_id << " "
	//		<< this->m_emparray[i]->name << " "
	//		<< this->m_emparray[i]->m_DeptId << endl;
	//}
}


Workmanager::~Workmanager(){
	if (this->m_emparray != NULL)
	{
		delete[]m_emparray;
		this->m_emparray = NULL;
	}
}

void Workmanager::showmenu()
//显示菜单函数
{
	cout << "************************************************" << endl;
	cout << "**********欢迎使用职工管理系统******************" << endl;
	cout << "             0.退出管理程序                                   " << endl;
	cout << "             1.增加职工信息                                   " << endl;
	cout << "             2.显示职工信息                                  " << endl;
	cout << "             3.删除离职员工                                   " << endl;
	cout << "             4.修改职工信息                                   " << endl;
	cout << "             5.查找职工信息                                   " << endl;
	cout << "             6.按照编号排序                                   " << endl;
	cout << "             7.退出管理程序                                   " << endl;
	cout << "************************************************" << endl;
}

void Workmanager::exitsys()
{
	cout << "欢迎再次使用！" << endl;
	system("pause");
	exit(0);
}

void Workmanager::add_emp()
//添加职工，首先读取老员工，增加新员工并且存储在文件中
{
	int add_num = 0;
	cout << "请输入添加职工数量：" << endl;
	cin >> add_num;
	if (add_num > 0)
	{
		int newsize = add_num + this->m_num;
		worker** newspace = new worker*[newsize];
		if (newspace != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
			for (int i = 0; i < add_num; i++)
			{
				int id;
				string name;
				cout << "请输入第" << i  + 1 <<"号员工数据"<<endl;
				cout << "请输入职工编号:" << endl;
				cin >> id;
				cout << "请输入职工姓名:" << endl;
				cin >> name;
				cout << "请选择员工类别:\n" << "\t1. 职工\n\t2. 经理\n\t3. 老板\n";
				int flag = 0;
				cin >> flag;
				worker* workman = NULL;
				switch (flag)
				{
				case 1:
					workman = new Employee(id, name, flag);
					break;
				case 2:
					workman = new manager(id, name, flag);
					break;
				case 3:
					workman = new boss(id, name, flag);
					break;
				default:
					cout << "类别选择错误：" << endl;
					break;
				}
				newspace[i + this->m_num] = workman;
			}
			this->m_num = newsize;
			delete[] m_emparray;
			this->m_emparray = newspace;
		}
		else
		{
			cout << "内存开辟失败！" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "输入有误" << endl;
	}
	this->save();
	this->m_fileisempty = false;
	system("pause");
	system("cls");
}

void Workmanager::save()
//存储职工数组在文件中
{
	ofstream savefile;
	savefile.open(FILENAME, ios::in);
	if (!savefile.is_open())
	{
		cout << "文件打开失败！" << endl;
		exit(0);
	}
	for (int i = 0; i < this->m_num; i++)
	{
		savefile << this->m_emparray[i]->m_id << " " 
			<< this->m_emparray[i]->name << " " 
			<< this->m_emparray[i]->m_DeptId << endl;
	}
	savefile.close();
}

void Workmanager::showall()
//显示所有的职工信息
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_num; i++)
		{
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}



int Workmanager::get_num()
//返回数组中元素个数，即对应的职工人数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		exit(0);
	}
	int id;
	string name;
	int did;

	int num(0);

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}

void Workmanager::init_emp()
//从文件中读取职工，并且初始化数组
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	
	int index(0);
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* workman = NULL;
		switch (did)
		{
		case 1:
			workman = new Employee(id, name, did);
			break;
		case 2:
			workman = new manager(id, name, did);
			break;
		case 3:
			workman = new boss(id, name, did);
			break;
		}
		this->m_emparray[index] = workman;
		index++;
	}
	ifs.close();
}

int Workmanager::isexist(int id)
//判断职工id是否存在
{
	int index = -1;
	for (int i = 0; i < m_num; i++)
	{
		if (this->m_emparray[i]->m_id == id)
		{
			return i;
			break;
		}
	}
	return index;
}

void Workmanager::find_name()
//查找某位职工
{
	int id;
	cout << "请输入查找职工id" << endl;
	cin >> id;
	int flag = this->isexist(id);
	if (flag == -1)
	{ 
		cout << "查无此人！" << endl;
	}
	else 
	{ 
		this->m_emparray[flag]->showinfo(); 
	}
	system("pause");
	system("cls");
}

void Workmanager::del_id()
{
	int id;
	cout << "请输入索要删除的员工id：" << endl;
	cin >> id;
	int index = this->isexist(id);
	if (index == -1)
	{
		cout << "该成员不存在!" << endl;
	}
	else
	{
		for (int i = index; i < this->m_num-1; i++)
		{
			this->m_emparray[i] = this->m_emparray[i + 1];
		}
		this->m_num--;
		cout << "删除成功！" << endl;
		this->save();
		system("pause");
		system("cls");
	}
}


void Workmanager::change_name()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else {
		int index;
		cout << "请输入需要修改的成员编号:" << endl;
		cin >> index;
		int ret = this->isexist(index);
		if (ret == -1)
		{
			cout << "查无此人！" << endl;
		}
		else {
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "请输入想要修改的成员数据：" << endl;
			cout << "重新输入职工id：" << endl;
			cin >> newid;
			cout << "重新输入职工姓名：" << endl;
			cin >> newname;
			cout << "重新输入职工类别：\n" << "\t1. 职工\n\t2. 经理\n\t3. 老板\n";
			cin >> newdid;
			worker* workman = NULL;
			switch (newdid)
			{
			case 1:
				workman = new Employee(newid, newname, newdid);
				break;
			case 2:
				workman = new manager(newid, newname, newdid);
				break;
			case 3:
				workman = new boss(newid, newname, newdid);
				break;
			}
			this->m_emparray[ret] = workman;
		}
		this->save();
		system("pause");
		system("cls");
	}
}



void Workmanager::sort_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "进行升序排序：" << endl;
		for (int i = 0; i < this->m_num; i++)
		{
			int xuanze = i;
			for (int j = i + 1; j < this->m_num; j++)
			{
				if (this->m_emparray[j]->m_id > this->m_emparray[i]->m_id)
				{
					xuanze = j;
				}
			}
			if (i != xuanze)
			{
				worker* workman = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[xuanze];
				this->m_emparray[xuanze] = workman;
			}
		}
	this->save();
	}
}


void Workmanager::deleteall()
{
	char a;
	cout << "是否清空文件？（Y/N）" << endl;
	cin >> a;
	if (a == 'Y')
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				delete this->m_emparray[i];
				this->m_emparray[i] = NULL;
			}
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_num = 0;
			this->m_fileisempty = true;
			cout << "清除成功！" << endl;
		}
		system("pause");
		system("cls");
	}
	else if (a == 'N')
	{
		return;
	}
}