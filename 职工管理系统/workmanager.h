#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Workmanager
{
public:
	Workmanager();
	~Workmanager();


	int m_num;//��¼ְ������
	bool m_fileisempty;//�ж��ļ��Ƿ�Ϊ��
	worker** m_emparray;//ְ������ָ��

	int isexist(int id);//����idְ���Ƿ����
	void showmenu();//�˵�����
	void exitsys();//�򵥵��˳�ϵͳ����
	void save();//�洢���ļ���
	int get_num();//ͳ������
	void init_emp();//��ʼ�������ļ��ж�ȡ����ʼ����������
	void showall();//��ʾְ����Ϣ
	void add_emp();//���ְ������
	void find_name();//����ְ��
	void del_id();//ɾ��ָ��id��Ա��
	void change_name();//�޸�ְ����Ϣ
	void sort_emp();//�����������
	void deleteall();//����ļ�
};