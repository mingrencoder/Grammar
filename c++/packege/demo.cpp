#include <iostream>
#include "Line.cpp"
#include "Array.cpp"
using namespace std;

/********************************************************/
/* 
在定义成员函数时，会自动向它传递一个隐藏的函数，即一个指向这个函数所在对象的指针， 即——类型 *this
1、对象成员
要求：
	定义两个类：
		坐标类：Coordinate
		数据成员：横坐标m_iX， 纵坐标m_iY
		成员函数：构造函数，析构函数，数据封装函数

		线段类：Line
		数据成员：点A m_coorA， 点B m_coorB
		成员函数：构造函数，析构函数，数据封装函数，信息打印函数

2、对象成员指针
3、常对象成员、常函数、常对象
*/
/********************************************************/

int main(void)
{
	cout << "*****************成员对象和成员对象指针******************" << endl;

	Line *p = new Line(1,2,3,4,11,22,33,44);

	p->printInfo();
	(*p).printPointerInfo();
	//64位操作系统下，指针占8个单元，32位操作系统下，指针占4个单元
	cout << "内存单元数量：" << sizeof(p) << endl; //每个类型占4个内存单元
	cout << "内存单元数量：" << sizeof(Line) << endl; 

	delete p;
	p = NULL;


	cout << "*****************this的使用******************" << endl;
	//对象各自的this指针指向各自对象的首地址
	Array array(10);
	cout << "———————返回引用———————" << endl;
	//每次操作的Array的引用
	array.getThis().setLen(20);

	cout << "操作的是其本身:" << array.getLen() << endl;

	cout << "———————返回指针———————" << endl;
	Array *array1 = array.getThisPointer(); //只是将指针返回，没有创建新的对象
	array1->setLen(30);
	cout << "操作的是另外一个指针:" << array1->getLen() << endl;
	cout << "原来的array的值也改变:" << array.getLen() << endl; 

	cout << "array的地址为：" << &array << endl;
	cout << "array的地址为：" << array1 << endl;
	

	cout << "*****************常对象成员、常成员函数******************" << endl;
	//常对象成员 const 类型 对象名
	//常成员函数 void 函数名() const

	//注意：常成员函数可以使用普通的数据成员，但是不能改变对象成员的值！！

	//使用常对象可以合法地调用常成员函数
	const Line line(1,2,3,4,5,6,7,8);
	line.printInfo();

	cout << "*****************对象常指针、对象常引用******************" << endl;
	//常引用和常指针只能调用常成员函数！！
	//普通对象能够调用常成员函数， 也可以调用普通成员函数
	cout << "———————————————" << endl; 
	Coordinate coor1(3, 5);
	Coordinate coor2(6, 9);
	Coordinate * const pCoor = &coor1;//可读可选，但是不能改变指向
	pCoor->getY();
	pCoor->printInfo();
	cout << "———————————————" << endl; 


	return 0;
}