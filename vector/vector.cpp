#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	vector<int> p;
	p.push_back(10);
	p.push_back(20);
	p.push_back(30);

	
	for (vector<int>::iterator begin = p.begin(); begin != p.end(); begin++)
	{
		cout << *begin << " ";
	}
	cout << endl;

	vector< vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector< vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator itb = (*it).begin();itb != (*it).end(); itb++)
		{
			cout << *itb << " ";
		}
		cout << endl;
	}

	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	return 0;
}