#include <iostream>
#include "Person.cpp"
#include "Worker.cpp"
#include "Banwagong.cpp"
#include "Soldier.cpp"
using namespace std;


void test1(Person p);

void test2(Person &p);

void test3(Person *p);

int main(void)
{

	cout << "**********************继承的方式**********************" << endl;
	/*****************************************
	继承：
		1、public
			private成员   —————————— 无法访问
			protected成员 —————————— protected
			public成员	  —————————— public
		2、protected
			private成员   —————————— 无法访问
			protected成员 —————————— protected
			public成员	  —————————— protected
		3、private
			private成员   —————————— 无法访问
			protected成员 —————————— private
			public成员	  —————————— private

	案例：
		Person
		Worker:protected Person
		Banwagong:public Worker
	*****************************************/
	// 堆实例化和栈实例化都是一样的效果
	Worker *p = new Worker;
	p->work();

	delete p;
	p = NULL;

	cout << "————————————————————" << endl;

	Banwagong banwagong;
	banwagong.net();
	// 不能直接访问protected成员，但是可以在其自身成员函数中调用
	// p->m_strName = "Bob";
	// p->m_iAge = 15;
	// p->m_iSalary = 5000;
	// p->printInfo();

	cout << "***********************隐藏**********************" << endl;

	/*****************************************
	继承：

	父类A ———————————————— void ABC()
	  |	
	  |
	子类B ———————————————— void ABC()

	实例化B的对象时，该对象只能访问到B中的ABC()函数，但是A中的ABC()函数并未消失，只是被隐藏
	*****************************************/

	Soldier *p1 = new Soldier;
	p1->eat();
	p1->Person::eat();

	delete p1;
	p1 = NULL;

	cout << "***********************isA**********************" << endl;

	cout << "———————————传值———————————" << endl;

	Soldier s;
	Person p2 = s; //将Soldier中的m_strName值传给Person
	p2.play();
	// 利用指针有相同的效果
	// Person *p3 = &s;
	// p3->play();

	//自身方法： 这里只能用s去调用Soldier的方法，但是不能用p2和p3去调用
	s.fight();

	cout << "———————————虚析构函数———————————" << endl;

	Person *p4 = new Soldier;
	p4->play();
	delete p4;
	p4 = NULL;
	/**********************
	初始打印结果为：
		Person()
		Soldier()
		SoldierName
		~Person()
	并没有Soldier的析构函数打印
	
	加入虚析构函数后：
		Person()
		Soldier()
		SoldierName
		~Soldier()
		~Person()
	**********************/
	
	cout << "———————————测试———————————" << endl;
	Person p5;
	Soldier s1;

	test3(&p5);
	test3(&s1);
	//test1要产生临时变量，而test2和test3不产生，效率更高

	cout << "***********************多继承和多重继承**********************" << endl;
	//多继承，用逗号”，“隔开

	cout << "***********************虚继承**********************" << endl;
	
	/*****************************************
	虚继承：
					人
				工人		农民
					农民工
				（菱形继承）

	class Workder:virtual public Person
	{
	};

	class Farmer:virtual public Person
	{
	};

	class MigrantWorker:virtual public Person
	{
		//只含有一份Person的数据
	};
	*****************************************/







	return 0;
}

//这里的参数是临时对象p，使用后则会自动销毁
void test1(Person p)
{
	p.play();
}

void test2(Person &p)
{
	p.play();
}

void test3(Person *p)
{
	p->play();
}
