#include<iostream>
#include<string>
#include"workmanager.h" 
#include"boss.h"
#include"employee.h"
#include"manager.h"
#include"worker.h"
using namespace std;




int main()
{
	unsigned choice = 0;
	//worker* workman = NULL;
	//workman = new Employee(1, "张三", 5);
	//workman->showinfo();
	//delete workman;

	//workman = new manager(2, "李四", 2);
	//workman->showinfo();
	//delete workman;

	//workman = new boss(3, "王五", 6);
	//workman->showinfo();
	//delete workman;
	Workmanager admin;
	while(true)
	{
		admin.showmenu();
		cout << "输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			admin.exitsys();
			break;
		case 1://添加职工
			admin.add_emp();
			break;
		case 2://显示职工
			admin.showall();
			break;
		case 3://删除职工
			admin.del_id();
			break;
		case 4://修改职工
			admin.change_name();
			break;
		case 5://查找职工
			admin.find_name();
			break;
		case 6://排序职工
			admin.sort_emp();
			break;
		case 7://清空文件
			admin.deleteall();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}