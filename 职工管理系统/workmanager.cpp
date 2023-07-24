#include"workmanager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"
#include<fstream>


#define FILENAME "empfile.txt"

Workmanager::Workmanager()
//���캯��
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		this->m_num = 0;
		this->m_fileisempty = true;
		this->m_emparray = NULL;
		ifs.close();
		return;
	}

	char ch;//�ļ�����
	ifs >> ch;
	if (ifs.eof())
	//�ļ����ڣ������ļ�Ϊ��
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_num = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	int num = this->get_num();//��ȡ�ļ�������
	this->m_num = num;
	this->m_emparray = new worker * [num];
	this->init_emp();
	//���Դ���
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
//��ʾ�˵�����
{
	cout << "************************************************" << endl;
	cout << "**********��ӭʹ��ְ������ϵͳ******************" << endl;
	cout << "             0.�˳��������                                   " << endl;
	cout << "             1.����ְ����Ϣ                                   " << endl;
	cout << "             2.��ʾְ����Ϣ                                  " << endl;
	cout << "             3.ɾ����ְԱ��                                   " << endl;
	cout << "             4.�޸�ְ����Ϣ                                   " << endl;
	cout << "             5.����ְ����Ϣ                                   " << endl;
	cout << "             6.���ձ������                                   " << endl;
	cout << "             7.�˳��������                                   " << endl;
	cout << "************************************************" << endl;
}

void Workmanager::exitsys()
{
	cout << "��ӭ�ٴ�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void Workmanager::add_emp()
//���ְ�������ȶ�ȡ��Ա����������Ա�����Ҵ洢���ļ���
{
	int add_num = 0;
	cout << "���������ְ��������" << endl;
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
				cout << "�������" << i  + 1 <<"��Ա������"<<endl;
				cout << "������ְ�����:" << endl;
				cin >> id;
				cout << "������ְ������:" << endl;
				cin >> name;
				cout << "��ѡ��Ա�����:\n" << "\t1. ְ��\n\t2. ����\n\t3. �ϰ�\n";
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
					cout << "���ѡ�����" << endl;
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
			cout << "�ڴ濪��ʧ�ܣ�" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "��������" << endl;
	}
	this->save();
	this->m_fileisempty = false;
	system("pause");
	system("cls");
}

void Workmanager::save()
//�洢ְ���������ļ���
{
	ofstream savefile;
	savefile.open(FILENAME, ios::in);
	if (!savefile.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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
//��ʾ���е�ְ����Ϣ
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
//����������Ԫ�ظ���������Ӧ��ְ������
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
//���ļ��ж�ȡְ�������ҳ�ʼ������
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
//�ж�ְ��id�Ƿ����
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
//����ĳλְ��
{
	int id;
	cout << "���������ְ��id" << endl;
	cin >> id;
	int flag = this->isexist(id);
	if (flag == -1)
	{ 
		cout << "���޴��ˣ�" << endl;
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
	cout << "��������Ҫɾ����Ա��id��" << endl;
	cin >> id;
	int index = this->isexist(id);
	if (index == -1)
	{
		cout << "�ó�Ա������!" << endl;
	}
	else
	{
		for (int i = index; i < this->m_num-1; i++)
		{
			this->m_emparray[i] = this->m_emparray[i + 1];
		}
		this->m_num--;
		cout << "ɾ���ɹ���" << endl;
		this->save();
		system("pause");
		system("cls");
	}
}


void Workmanager::change_name()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else {
		int index;
		cout << "��������Ҫ�޸ĵĳ�Ա���:" << endl;
		cin >> index;
		int ret = this->isexist(index);
		if (ret == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else {
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "��������Ҫ�޸ĵĳ�Ա���ݣ�" << endl;
			cout << "��������ְ��id��" << endl;
			cin >> newid;
			cout << "��������ְ��������" << endl;
			cin >> newname;
			cout << "��������ְ�����\n" << "\t1. ְ��\n\t2. ����\n\t3. �ϰ�\n";
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
		cout << "�ļ������ڻ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������" << endl;
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
	cout << "�Ƿ�����ļ�����Y/N��" << endl;
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
			cout << "����ɹ���" << endl;
		}
		system("pause");
		system("cls");
	}
	else if (a == 'N')
	{
		return;
	}
}