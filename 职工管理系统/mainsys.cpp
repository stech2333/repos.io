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
	//workman = new Employee(1, "����", 5);
	//workman->showinfo();
	//delete workman;

	//workman = new manager(2, "����", 2);
	//workman->showinfo();
	//delete workman;

	//workman = new boss(3, "����", 6);
	//workman->showinfo();
	//delete workman;
	Workmanager admin;
	while(true)
	{
		admin.showmenu();
		cout << "�������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			admin.exitsys();
			break;
		case 1://���ְ��
			admin.add_emp();
			break;
		case 2://��ʾְ��
			admin.showall();
			break;
		case 3://ɾ��ְ��
			admin.del_id();
			break;
		case 4://�޸�ְ��
			admin.change_name();
			break;
		case 5://����ְ��
			admin.find_name();
			break;
		case 6://����ְ��
			admin.sort_emp();
			break;
		case 7://����ļ�
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