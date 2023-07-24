#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;


#define MAX_length 100


//联系人结构体
typedef struct Person
{
	string m_name;//姓名
	int m_sex;//性别
	int m_age;//年龄
	string m_phone;//电话
	string m_addr;//地址
}Person;

//通信录结构体
typedef struct Addressbooks
{
	Person personarray[MAX_length];
	int m_size;//通信录人员个数
}books;

int isexist(books* book, string name);

//菜单界面
void showmenu()
{
	cout << "********************" << "************" << endl;
	cout << "\t1.添加联系人" << endl;
	cout << "\t2.显示联系人" << endl;
	cout << "\t3.删除联系人" << endl;
	cout << "\t4.查找联系人" << endl;
	cout << "\t5.修改联系人" << endl;
	cout << "\t6.清空联系人" << endl;
	cout << "\t0.退出通讯录" << endl;
	cout << "********************" << "************" << endl;
}



//增联系人界面
void addperosn(books* book)
{
	system("cls");
	if (book->m_size == MAX_length)
	{
		cout << "通信录人数已达到最大值，无法添加" << endl;
		exit(0);
	}
	cout << "请输入姓名：" << endl;
	cin >> book->personarray[book->m_size].m_name;
	cout << "请输入性别：" << endl;
	cout << "1-----男" << endl;
	cout << "2-----女" << endl;
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
			cout << "输入值有误，请重新输入：" << endl;
		}
	}
	cout << "请输入年龄：" << endl;
	cin >> book->personarray[book->m_size].m_age;
	cout << "请输入电话：" << endl;
	cin >> book->personarray[book->m_size].m_phone;
	cout << "请输入地址：" << endl;
	cin >> book->personarray[book->m_size].m_addr;
	cout << "创建成功！" << endl;
	book->m_size++;
}



//查找联系人界面
void findperson(books *book)
{
	system("cls");
	string input_name;
	cout << "请输入想要查找人姓名：" << endl;
	cin >> input_name;
	int i = isexist(book, input_name);
	if (i != -1)
	{
		cout << "姓名：\t" << book->personarray[i].m_name << endl;
		if (book->personarray[i].m_sex == 1)
		{
			cout << "性别：\t男"  << endl;
		}
		else if (book->personarray[i].m_sex == 2)
		{
		    cout << "性别：\t女" << endl;
		}
		cout << "年龄：\t" << book->personarray[i].m_age << endl;
		cout << "电话：\t" << book->personarray[i].m_phone << endl;
		cout << "地址：\t" << book->personarray[i].m_addr<< endl;
	}
	else if (i == -1)
	{
		cout << "查无此人！" << endl;
	}
}

//显示联系人
void showperson(books* const book)
{
	if (book->m_size == 0)
	{
		cout << "通信录无联系人" << endl;
	}
	else
	{
		for (int i = 0; i < book->m_size; i++)
		{
			cout << "姓名：\t" << book->personarray[i].m_name << endl;
			if (book->personarray[i].m_sex == 1)
			{
				cout << "性别：\t男" << endl;
			}
			else if (book->personarray[i].m_sex == 2)
			{
				cout << "性别：\t女" << endl;
			}
			cout << "年龄：\t" << book->personarray[i].m_age << endl;
			cout << "电话：\t" << book->personarray[i].m_phone << endl;
			cout << "地址：\t" << book->personarray[i].m_addr << endl;
		}
	}
}

//删除联系人
void deleteperson(books *book)
{
	string name;
	cout << "请输入想要删除的联系人：" << endl;
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
		cout << name << "信息删除成功" << endl;
	}
	else if (flag == -1)
	{
		cout << "查无此人！" << endl;
	}
}

//修改联系人
void changeperson(books* book)
{
	string name;
	cout << "请输入想要修改联系人姓名：" << endl;
	cin >> name;
	int flag = isexist(book, name);
	if (flag == -1)
	{
		cout << "查无此人，请重新操作" << endl;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> book->personarray[flag].m_name;
		cout << "请输入性别：" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
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
				cout << "输入值有误，请重新输入：" << endl;
			}
		}
		cout << "请输入年龄：" << endl;
		cin >> book->personarray[flag].m_age;
		cout << "请输入电话：" << endl;
		cin >> book->personarray[flag].m_phone;
		cout << "请输入地址：" << endl;
		cin >> book->personarray[flag].m_addr;
		cout << "修改成功！" << endl;
	}
}



//清空通讯录
void deleteall(books* book)
{
	char a;
	cout << "是否清空该通讯录?(Y/N)" << endl;
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
		cout << "清空成功！" << endl;
		break;
	case 'N':
	case 'n':
		cout << "取消清空！" << endl;
		break;
	}
}


//检验是否找到联系人
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
	//创建通信录
	books abs;
	abs.m_size = 0;
	while (1)
	{
		system("cls");
		showmenu();
		int select(0);//选择变量

		cout << "请用户选择操作:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			addperosn(&abs);//添加联系人
			Sleep(1000);
			break;
		case 2:
			//显示联系人
			showperson(&abs);
			system("pause");
			break;
		case 3:
			deleteperson(&abs);
			system("pause");
			//删除联系人
			break;
		case 4:
			findperson(&abs);//查找联系人
			system("pause");
			break;
		case 5:
			changeperson(&abs);//修改联系人
			system("pause");
			break;
		case 6:
			deleteall(&abs);
			system("pause");
			//清空联系人
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}