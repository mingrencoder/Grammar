#include <iostream>
#include <stdlib.h>
#include "Circle.cpp"
#include "Rect.cpp"
#include "Shape.cpp"
using namespace std;

#include "./virtualfunction/DustWorker.cpp"
#include "./virtualfunction/Worker.cpp"
#include "./virtualfunction/Person.cpp"

/*****************************************
动态多态、虚函数
	Shape类
	Rect类
	Circle类
*****************************************/

int main(void)
{
	cout << "**********************使用虚函数实现多态**********************" << endl;
	Shape *shape1 = new Rect(3, 6);
	Shape *shape2 = new Circle(5);

	cout << shape1->calcArea() << endl;
	cout << shape2->calcArea() << endl;

	delete shape1;
	delete shape2;

	cout << "———————————多态中存在的问题———————————" << endl;
	// 多态是父类指针指向子类对象，若子类中存在一个对象成员并在子类对象的析构函数中delete掉
	// 但是在delete shape的时候，这里执行的析构函数的父类的，子类的析构函数没有执行，则造成内存泄漏
	// 这里解决方法继承篇也讲了，只需要写成虚析构函数即可

	/*********************************
	virtual使用限制
		1、不能修饰普通函数
		2、不能修饰静态成员函数
		3、不能修饰内敛函数
		4、不能修饰构造函数 
	**********************************/

	cout << "———————————虚函数和虚析构函数实现———————————" << endl;
	/*********************************
	实例化对象时:
		会实例化一个虚函数表，默认为父类的虚函数表
		如果在子类定义了虚函数，则会在虚函数表中关于该虚函数的指针会覆盖掉父类该同名函数的指针 ———— 函数覆盖

	虚析构函数执行前提：
		执行完子类析构函数后，会自动执行父类析构函数
	*********************************/

	cout << "**********************纯虚函数和抽象类**********************" << endl;
	// 纯虚函数： 没有函数体，函数名后加 = 0
	// 抽象类： 含有纯虚函数的类

	/*****************************************
	纯虚函数：
		1、Person类：成员函数：构造函数，虚析构函数，纯虚函数work()
		2、Worker类：成员函数：构造函数，word()
		3、DustWorker类：成员函数：构造函数，work()
	*****************************************/
	Person *p = new DustWorker("Jet", 10);
	p->work();

	delete p;
	p = NULL;

	// 接口类：仅含有纯虚函数的类，不能含有数据成员，也没有构造函数和析构函数

	cout << "**********************RTTI**********************" << endl;
	/*****************************************
	dynamic_cast：
		1、只能用于指针和引用的转换
		2、要转换的类型中必须包含虚函数
		3、转换成功则返回子类的地址，否则返回NULL
	
	type_id
		1、type_id返回一个type_info对象的引用
		2、要如果想通过基类的指针获取派生类的数据类型，基类必须带有虚函数
		3、只能获取对象的数据类型，没办法判断指针是基类或子类
	*****************************************/







	return 0;
}