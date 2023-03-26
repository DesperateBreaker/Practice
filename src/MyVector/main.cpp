#include<iostream>
#include<vector>
#include"MyVector.h"

using namespace std;

int main()
{
	vector<int> m1;
	cout << m1.capacity() << endl;
	cout << m1.size() << endl;
	cout << m1.empty() << endl;
	cout << m1.front() << endl;
	
	m1.push_back(1);
	cout << m1[0];
	m1[0] = 5;
	cout << m1[0];
	m1.push_back(2);
	cout << m1[1];
	cout << m1.capacity() << endl;
	cout << m1.size() << endl;
	cout << m1.empty() << endl;

	m1.pop_back();
	cout << m1[1];
	m1.pop_back();
	cout << m1.capacity() << endl;
	cout << m1.size() << endl;
	cout << m1.empty() << endl;




	
	system("pause");
}