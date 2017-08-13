#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
using namespace std;


template <typename T, int keySize, int kVal>
class MyArray
{
public:
	MyArray();
	~MyArray()
	{
		delete []m_pArr;
		m_pArr = NULL;
	}
	void display();
private:
	T *m_pArr;
};

//若将函数的定义写在类的外部，则必须加下面这行代码
template <typename T, int kSize, int kVal>
MyArray<T, kSize, kVal>::MyArray()
{
	m_pArr = new T[kSize];
	for(int i=0; i<kSize; i++)
	{
		m_pArr[i] = kVal;
	}
}

template <typename T, int kSize, int kVal>
void MyArray<T, kSize, kVal>::display()
{
	for(int i=0; i<kSize; i++)
	{
		cout << m_pArr[i] << endl;
	}
}
#endif