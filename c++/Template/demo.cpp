#include <iostream>
#include <stdlib.h>
#include "MyArray.h"
#include <vector>
#include <list>
#include <map>

using namespace std;

/*****************************************/
/*
函数模板

	本身不会在内存中产生代码
	1、class
	template <class T>
	T max(T a, T b)          函数模板
	{
		return (a < b) ? a : b;
	}
	使用：
	int ival = max(100, 99); 模板函数
	char c = max<char>('A', 'B'); 模板函数

	2、typename（也可以是多参数，并且可以与class混用）
	template<typename t>
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
	使用
	int a = 1, b = 2;
	swap<int>(a, b);

	3、变量
	template<int size>
	void display()
	{
		cout << size << endl;
	}
	使用
	display<10>();

 	函数模板可以重载，类型可以不同，参数可以不同

 类模板：
 	template <class T>
 	class MyArray
 	{
	public:
		void display()
		{
			…………
		}
	private:
		T *m_pArr;
 	};
	使用
	MyArray<int> arr;
	arr.display();
*/
/*****************************************/

template <typename T>
void display(T a)
{
	cout << a << endl;
}

template <typename T, class S>
void display(T a, S s)
{
	cout << a << "--" << s << endl;
}

template <typename T, int keySize>
void display(T a)
{
	for(int i=0; i<keySize; i++)
	{
		cout << i+1 << " : " << a << endl;
	}
}


int main(void)
{

	cout << "———————————————函数模板—————————————————" << endl;
	display<int>(10);
	display<double>(10.99);

	display<int, double>(5, 1.3);

	display<int, 5>(7);


	cout << "———————————————类模板—————————————————" << endl;
	MyArray<int, 5, 3> arr;
	arr.display();


	cout << "———————————————stl标准库—————————————————" << endl;
	/********************************
	vector 向量————本质是对数组的封装
	特点：数据读取速度快

	常用方法：
		empty()
		begin() 	返回向量迭代器首元素
		end()		返回向量迭代器末元素的下一个元素
		clear()
		front()		第一个数据
		back()		最后一个数据
		size()
		push_back(elem)	将数据插入向量尾
		pop_back()		删除向量尾部数据


	列表：list 
	特点：数据插入速度快

	map：映射
	********************************/


	cout << "—————vector—————" << endl;
	std::vector<int> v1;
	std::vector<int> v2(v1);

	std::vector<string> sv1;
	std::vector<string> sv2(sv1);

	std::vector<int> iv1(3, -1);
	std::vector<string> sv(10, "hi!");

	iv1.pop_back();
	iv1.push_back(10);
	cout << iv1.size() << endl;
	for(int i=0; i<iv1.size(); i++)
	{
		cout << iv1[i] << endl;
	}

	vector<string> vec;
	vec.push_back("hello");
	vec.push_back("world");

	std::vector<string>::iterator citer = vec.begin();
	for(; citer != vec.end(); citer++)
	{
		cout << *citer << endl;
	}


	cout << "—————list—————" << endl;
	list<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);

	list<int>::iterator litor = list1.begin();
	for(; litor != list1.end(); litor++)
	{
		cout << *litor << endl;
	}

	cout << "—————map—————" << endl;
	std::map<int, string> map;
	pair<int, string> p1(10, "shanghai");
	pair<int, string> p2(20, "beijing");
	pair<int, string> p3(30, "wuhan");
	map.insert(p1);
	map.insert(p2);
	map.insert(p3);
	cout << map[10] << endl;
	cout << map[20] << endl;

	std::map<int, string>::iterator mapitor = map.begin();
	for(; mapitor != map.end(); mapitor++)
	{
		cout << mapitor->first << "-";
		cout << mapitor->second << endl;
	}



	return 0;
}