#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;


#define MAX_length 100


//��ϵ�˽ṹ��
typedef struct Person
{
	string m_name;//����
	int m_sex;//�Ա�
	int m_age;//����
	string m_phone;//�绰
	string m_addr;//��ַ
}Person;

//ͨ��¼�ṹ��
typedef struct Addressbooks
{
	Person personarray[MAX_length];
	int m_size;//ͨ��¼��Ա����
}books;

int isexist(books* book, string name);

//�˵�����
void showmenu()
{
	cout << "********************" << "************" << endl;
	cout << "\t1.�����ϵ��" << endl;
	cout << "\t2.��ʾ��ϵ��" << endl;
	cout << "\t3.ɾ����ϵ��" << endl;
	cout << "\t4.������ϵ��" << endl;
	cout << "\t5.�޸���ϵ��" << endl;
	cout << "\t6.�����ϵ��" << endl;
	cout << "\t0.�˳�ͨѶ¼" << endl;
	cout << "********************" << "************" << endl;
}



//����ϵ�˽���
void addperosn(books* book)
{
	system("cls");
	if (book->m_size == MAX_length)
	{
		cout << "ͨ��¼�����Ѵﵽ���ֵ���޷����" << endl;
		exit(0);
	}
	cout << "������������" << endl;
	cin >> book->personarray[book->m_size].m_name;
	cout << "�������Ա�" << endl;
	cout << "1-----��" << endl;
	cout << "2-----Ů" << endl;
	int sex = 0;
	
	while (1)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
			{
			book->personarray[book->m_size].m_sex = sex;
			break;
			}
		else
		{
			cout << "����ֵ�������������룺" << endl;
		}
	}
	cout << "���������䣺" << endl;
	cin >> book->personarray[book->m_size].m_age;
	cout << "������绰��" << endl;
	cin >> book->personarray[book->m_size].m_phone;
	cout << "�������ַ��" << endl;
	cin >> book->personarray[book->m_size].m_addr;
	cout << "�����ɹ���" << endl;
	book->m_size++;
}



//������ϵ�˽���
void findperson(books *book)
{
	system("cls");
	string input_name;
	cout << "��������Ҫ������������" << endl;
	cin >> input_name;
	int i = isexist(book, input_name);
	if (i != -1)
	{
		cout << "������\t" << book->personarray[i].m_name << endl;
		if (book->personarray[i].m_sex == 1)
		{
			cout << "�Ա�\t��"  << endl;
		}
		else if (book->personarray[i].m_sex == 2)
		{
		    cout << "�Ա�\tŮ" << endl;
		}
		cout << "���䣺\t" << book->personarray[i].m_age << endl;
		cout << "�绰��\t" << book->personarray[i].m_phone << endl;
		cout << "��ַ��\t" << book->personarray[i].m_addr<< endl;
	}
	else if (i == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
}

//��ʾ��ϵ��
void showperson(books* const book)
{
	if (book->m_size == 0)
	{
		cout << "ͨ��¼����ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < book->m_size; i++)
		{
			cout << "������\t" << book->personarray[i].m_name << endl;
			if (book->personarray[i].m_sex == 1)
			{
				cout << "�Ա�\t��" << endl;
			}
			else if (book->personarray[i].m_sex == 2)
			{
				cout << "�Ա�\tŮ" << endl;
			}
			cout << "���䣺\t" << book->personarray[i].m_age << endl;
			cout << "�绰��\t" << book->personarray[i].m_phone << endl;
			cout << "��ַ��\t" << book->personarray[i].m_addr << endl;
		}
	}
}

//ɾ����ϵ��
void deleteperson(books *book)
{
	string name;
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	cin >> name;
	int flag = 0;
	flag = isexist(book, name);
	if (flag != -1)
	{
		for (int j = flag; j < book->m_size ; j++)
		{
			book->personarray[j] = book->personarray[j + 1];
		}
		book->m_size--;
		cout << name << "��Ϣɾ���ɹ�" << endl;
	}
	else if (flag == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
}

//�޸���ϵ��
void changeperson(books* book)
{
	string name;
	cout << "��������Ҫ�޸���ϵ��������" << endl;
	cin >> name;
	int flag = isexist(book, name);
	if (flag == -1)
	{
		cout << "���޴��ˣ������²���" << endl;
	}
	else
	{
		cout << "������������" << endl;
		cin >> book->personarray[flag].m_name;
		cout << "�������Ա�" << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		int sex = 0;

		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				book->personarray[flag].m_sex = sex;
				break;
			}
			else
			{
				cout << "����ֵ�������������룺" << endl;
			}
		}
		cout << "���������䣺" << endl;
		cin >> book->personarray[flag].m_age;
		cout << "������绰��" << endl;
		cin >> book->personarray[flag].m_phone;
		cout << "�������ַ��" << endl;
		cin >> book->personarray[flag].m_addr;
		cout << "�޸ĳɹ���" << endl;
	}
}



//���ͨѶ¼
void deleteall(books* book)
{
	char a;
	cout << "�Ƿ���ո�ͨѶ¼?(Y/N)" << endl;
	cin >> a;
	switch (a)
	{
	case 'Y':
	case 'y':
		for (int i = 0; i < book->m_size; i++)
		{
			book->personarray[i] = book->personarray[book->m_size];
		}
		book->m_size = 0;
		cout << "��ճɹ���" << endl;
		break;
	case 'N':
	case 'n':
		cout << "ȡ����գ�" << endl;
		break;
	}
}


//�����Ƿ��ҵ���ϵ��
int isexist(books* book,string name)
{
	for (int i = 0; i < book->m_size;i++)
	{
		if (name == book->personarray[i].m_name)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	//����ͨ��¼
	books abs;
	abs.m_size = 0;
	while (1)
	{
		system("cls");
		showmenu();
		int select(0);//ѡ�����

		cout << "���û�ѡ�����:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addperosn(&abs);//�����ϵ��
			Sleep(1000);
			break;
		case 2:
			//��ʾ��ϵ��
			showperson(&abs);
			system("pause");
			break;
		case 3:
			deleteperson(&abs);
			system("pause");
			//ɾ����ϵ��
			break;
		case 4:
			findperson(&abs);//������ϵ��
			system("pause");
			break;
		case 5:
			changeperson(&abs);//�޸���ϵ��
			system("pause");
			break;
		case 6:
			deleteall(&abs);
			system("pause");
			//�����ϵ��
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}