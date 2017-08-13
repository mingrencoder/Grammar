#include <iostream>
#include "Time.cpp"
#include "Match.cpp"
using namespace std;

/********************************************************/
/* 
友元函数
	1、友元全局函数
	2、友元成员函数

友元类
	注意：需要首先声明该友元类，并定义进来
	1、友元关系不可传递
	2、友元关系的单向性
	3、友元声明的形式及数量不受限制
	最好不要使用友元，会破坏封装性
*/
/********************************************************/

void printTime(Time &t);

int main(void)
{
	Time t(3, 10, 13);

	// 全局函数
	printTime(t);

	//成员函数
	Match m;
	m.printMatchTime(t);

	//友元类
	// Match m1(3, 4, 1);
	// m1.testTime();


	return 0;
}

void printTime(Time &t)
{
	cout << t.m_iHour << ":" << t.m_iMinute << ":" << t.m_iSecond << endl;
}