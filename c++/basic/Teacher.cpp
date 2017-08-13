#include "Teacher.h"
#include <iostream>
using namespace std;


Teacher::Teacher():m_count(100)
{
	m_strName = "Jim";
	m_iAge = 20;
	cout << "无参构造函数:Teacher()" << endl;
}
// Teacher::Teacher(string _name, int _age)
// {
// 	m_strName = _name;
// 	m_iAge = _age;
// 	cout << "Teacher(string _name, int _age)" << endl;
// }
//以初始化列表进行
Teacher::Teacher(string _name, int _age, int _count):m_strName(_name), m_iAge(_age), m_count(_count)
{
	cout << "有参构造函数：Teacher(string _name, int _age, int _count)" << endl;
}

//拷贝构造函数
Teacher::Teacher(const Teacher &teacher):m_count(100)
{
	cout << "拷贝构造函数：Teacher(const Teacher &teacher)" << endl;
}

//析构函数
Teacher::~Teacher()
{
	cout << "析构函数 ~Teacher()" << endl;
}

void Teacher::setName(string _name)
{
	m_strName = _name;
}
string Teacher::getName()
{
	return m_strName;
}

void Teacher::setAge(int _age)
{
	m_iAge = _age;
}
int Teacher::getAge()
{
	return m_iAge;
}

void Teacher::teach()
{
	cout << "上课了" << endl;
}

int Teacher::getCount()
{
	return m_count;
}