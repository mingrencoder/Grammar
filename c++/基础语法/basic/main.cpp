#include <iostream>
#include <stdlib.h>
#include "Teacher.cpp"
#include "Array.cpp"

using namespace std;

/************************
命名空间
*************************/
namespace A
{
    int x = 1;
    void fun()
    {
        cout << "A" << endl;
    }
}

namespace B
{
    int x = 2;
    void fun()
    {
        cout << "B" << endl;
    }
    void fun2()
    {
        cout << "B2" << endl;
    }
}

//先定义命名空间，再引用
using namespace B;

int getMaxOrMin(int *arr, int count, bool isMax)
{
    int temp = arr[0];
    for(int i=0; i<count; i++)
    {
        if(isMax)
        {
            if(arr[i]>temp)
            {
                temp = arr[i];
            }
        } else
        {
            if(arr[i]<temp)
            {
                temp = arr[i];
            }
        }
    }
    return temp;
}

//结构体在堆栈中创建，是值类型，而类是引用类型
typedef struct
{
    int x;
    int y;
}Coor;

/************************
声明一些函数
*************************/
//在main函数之前必须要声明函数
void change(int &a, int &b);

//重载
void fun1(int i = 10, int j = 20, int k = 30);
void fun1(double i, double j);

//声明内联函数
inline int max(int a, int b);

/************************
类
*************************/
class Coordinate
{
public:
    Coordinate():x(100),y(200){};
    int x;
    int y;
    void printX()
    {
        cout << x << endl;
    }
    void printY()
    {
        cout << y << endl;
    }

};


//同文件类外定义
//--------------begin---------------
// class Teacher
// {
// public:
// 	void setName(string _name);
// 	string getName();
// 	void setAge(int _age);
// 	int getAge();
// 	void teach();
// private:
// 	string m_strName;
// 	int m_iAge;
// };

// void Teacher::setName(string _name)
// {
// 	m_strName = _name;
// }
// string Teacher::getName()
// {
// 	return m_strName;
// }

// void Teacher::setAge(int _age)
// {
// 	m_iAge = _age;
// }
// int Teacher::getAge()
// {
// 	return m_iAge;
// }

// void Teacher::teach()
// {
// 	cout << "上课了" << endl;
// }

//--------------end---------------


void test(Teacher teacher);

int main()
{
    cout << "请输入一个整数：" << endl;
    int x = 10;
    //cin >> x;
    cout << oct << x << endl; //八进制
    cout << dec << x << endl; //十进制
    cout << hex << x << endl; //十六进制

    cout << "请输入一个布尔值(0,1)：" << endl;
    bool y = false;
    //cin >> y;
    cout << boolalpha << y << endl;

    cout << "--------namespace使用-------" << endl;

    cout << A::x << endl;
    B::fun();
    fun2();

    cout << "-------取最值的函数--------" << endl;

    int arr[] = {15,3,1,6};
    cout << dec<< getMaxOrMin(arr, 4, true) << endl;
    cout << getMaxOrMin(arr, 4, false) << endl;

    cout << "-------基本数据类型引用--------" << endl;
    int a = 3;
    int &b = a;
    b = 10;
    cout << "a = " << a << endl;
    a = 30;
    cout << "b = " << b << endl; //本体变动也会影响别名的指
    cout << "-------结构体类型引用--------" << endl;
    Coor c;
    Coor &c1 = c;
    c1.x = 10;
    c1.y = 20;
    cout << "Coor的变量值：x = " << c.x << " y = " << c.y << endl;

    cout << "-------指针类型引用--------" << endl;
    // 类型 *&指针引用名 = 指针；
    int a1 = 10;
    int *p = &a1; //定义指针变量保存a1的内存地址

    // *为取内容，&为取地址，p为int*指针类型，而p的值为a1的地址，因此*p值即为a的值

    int *&q = p; //q为指针p的别名
    *q = 20;
    cout << a1 << endl;

    //复习一下指针
    cout << "a1的地址:" << &a1 << endl;
    cout << "a1的地址:" << p << endl;
    *p = 1;	//这里*p是将指针p看作为了一个int对象，给这个对象赋值为1，则打印a1的值为1
    cout << a1 << endl;

    cout << "-------引用作为函数参数--------" << endl;
    //没有引用之前的C语言写法
    /*void fun(int *a, int *b)
    {
        int temp = 0;
        c = *a;
        *a = *b;
        *b = c;
    }

    int x = 10, y = 20;
    fun(&x, &y);*/

    //使用引用
    /*void fun(int &a, int &b)
    {
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }

    int x = 10, y = 20;
    fun(x, y);*/
    int m = 10, n = 20;
    change(m, n);
    cout << m << "," << n << endl;

    //注意引用必须有一个实际的对象与之相对应，若没有则会报错



    cout << "***********************const关键字****************************" << endl;

    const int x1 = 3; //x1不可更改
    int x2 = 10;
    int x3 = 5;

    //const与指针类型
    //下面两个写法等价
    const int *p1 = NULL;
    int const *p2 = NULL;


    cout << "-------const与指针的关系--------" << endl;
    //位于栈区，不需要释放
    int *const p3 = &x2; //这里p3指向了x2，且p3的指向不能再更改了,但是x2的值可以由指针*p3去更改
    *p3 = 20;
    cout << x2 << endl;
    //如果交换const和*的位置，则可以修改指针*p4的指向，但是指p4就不能改了
    int const *p4 = NULL;
    p4 = &x2;
    p4 = &x3;
    cout << "p4指针指向可以改变：" << *p4 << endl;

    cout << "-------const与引用的关系--------" << endl;
    //如上面例子，如果y为x的引用，且y为const类型，则y不能直接改变，但是x可以改变————此种情况，指针指向不可变，x本身具有读写权限，而指针只有读权限
    //如果相反，y为可变，x为const类型，由于考虑到通过*y方式改变x的值的风险，因此此做法被编译器禁止
    int const &z = x2;
    x2 = 1;
    cout << "修改后的x2 = " << z << endl;
    //若x1为const类型，则z1这边也为const类型才能编译通过，但是好像没什么用
    int const &z1 = x1;
    //下面这种就是编译器不通过的
    //int &z2 = x1;
    // z = 10;

    cout << "***********************函数特性****************************" << endl;
    //参数规则：一定要将有默认值的参数放在参数列表的最右端
    //根据经验：定义函数的时候，最好不要加入默认值，在声明函数的时候，可以加入默认值

    cout << "-------默认参数，重载函数--------" << endl;
    //注意函数重载要在同一个命名空间下进行
    fun1();
    fun1(5);
    fun1(2,3);
    fun1(1,2,3);

    fun1(1.1, 2.2);

    cout << "-------内联函数--------" << endl;
    //定义关键字 inline
    int i = 1, j = 2;
    int m1 = max(i ,j);
    cout << "最大值为" << m1 << endl;
    //注意几点：
    //1、内联函数的建议性的，由编译器决定
    //2、要求逻辑简单，不能包含循环
    //3、不能是递归函数，若为递归则编译器将其看作为一个普通函数

    cout << "***********************内存管理****************************" << endl;
    //申请
    int *p5 = new int[1000];
    //检查是否成功
    if (NULL == p5)
    {
        //内存分配失败，异常处理
        system("pause");
        return 0;
    }
    p[0] = 10;
    p[1] = 20;
    cout << p[0] << "," << p[1] << endl;

    //释放
    delete p1;
    p1 = NULL;
    delete p2;
    p2 = NULL;
    delete []p5;
    p5 = NULL;

    cout << "***********************实例化对象****************************" << endl;
    //方式1、 栈实例化：不需要手动去释放内存
    Coordinate coordinate;
    // Coordinate coordinate[20];

    coordinate.x = 10;
    coordinate.y = 20;
    coordinate.printX();
    coordinate.printY();

    //方式2、 堆实例化：需要手动去释放内存
    Coordinate *pc = new Coordinate();
    // Coordinate *pc1 = new Coordinate[20];

    if(NULL == pc)
    {
        return 0;
    }
    pc->x = 100;
    pc->y = 200;
    pc->printX();
    pc->printY();


    delete pc;
    pc = NULL;
    // delete []pc1;
    // pc1 = NULL;

    cout << "***********************字符串****************************" << endl;
    string s1 = "hello";
    string s2("world");
    string s3 = s1 + s2;
    string s4 = "hello" + s2;
    string s5 = "hello" + s2 + "world";
    //错误写法
    //string s6 = "hello" + "world;
    cout << s5 << "-" << s5.size() << "-" << s5[0] << endl;

    cout << "***********************类内定义与内联函数****************************" << endl;
    //类内定义的函数，编译器会将其优先编译为内联函数，inline无需写出，但不包括复杂函数
    //类外定义： 1、同文件		2、分文件
    //1、同文件 函数定义与类的定义在同一文件中
    //		成员函数在类中声明，在类外实现
    //2、分文件 定义一个 类名.h文件，里面声明所有的成员函数

    Teacher t;
    cout << "默认姓名：" << t.getName() << "  默认年龄：" << t.getAge() << endl;
    t.setName("张三");
    t.setAge(30);
    cout << "姓名：" << t.getName() << "  年龄：" << t.getAge() << endl;
    t.teach();

    Teacher t1("James", 25);
    cout << "姓名：" << t1.getName() << "  年龄：" << t1.getAge() << "  默认学生人数：" << t1.getCount() << endl;

    cout << "***********************初始化列表****************************" << endl;
    //可以放在构造函数后面 和 拷贝构造函数后面
    //初始化列表先于构造函数执行
    //初始化列表智能用于构造函数，可以用来同时初始化多个数据成员
    Coordinate coordinate1;
    // Coordinate coordinate[20];
    cout << "初始化列表中x的值=" << coordinate1.x << "		初始化列表中y的值=" << coordinate1.y <<endl;

    //必要性
    //若一个类中有一个const常量，但该常量不能在构造函数中被赋值，因此智能在初始化列表中进行
    Teacher t2 = Teacher("James", 25, 150);
    cout << "姓名：" << t2.getName() << "  年龄：" << t2.getAge() << "  学生人数：" << t2.getCount() << endl;

    cout << "***********************拷贝构造函数****************************" << endl;
    //不能重载
    //定义格式：  类名(const 类名 &变量名)
    //若没有定义，则系统会自动生成一个默认的拷贝构造函数
    //采用直接初始化或复制初始化实例对象时， 系统会自动调用拷贝构造函数
    Teacher t3 = t2;
    Teacher t4(t3);
    test(t4);
    cout << "***********************析构函数****************************" << endl;
    //对象销毁时调用，作用是释放内存等等操作
    //如果没有自定义，则系统自动生成
    //没有返回值，参数，也不能重载
    Teacher *t5 = new Teacher("李四", 24);
    delete t5;//此时打印析构函数
    t5 = NULL;

    cout << "***********************对象成员和对象数组****************************" << endl;
    Coordinate coor[3];
    coor[0].x = 0;
    coor[0].y = 0;

    Coordinate *p6 = new Coordinate[3];
    p6->x = 11; //指第一个元素
    p6[0].y = 21;

    p6++;
    p6->x = 12;
    p6[0].y = 22; //指针加一， 这里访问的相当于第二个元素

    p6[1].x = 13; //第二个元素
    p6++; //指针再次加一
    p6->y = 23; //访问到第三个元素

    // p6--;
    // p6--;
    // cout << p6[0].x << "," << p6[0].y << endl;
    // cout << p6[1].x << "," << p6[1].y << endl;
    // cout << p6[2].x << "," << p6[2].y << endl;

    for(int i=0; i<3; i++)
    {
        cout << "p_x " << p6->x << endl;
        cout << "p_y " << p6->y << endl;
        //每次循环将指针减一，这样相当于倒序遍历
        p6--;
    }

    //释放内存时，由于此时指针p6已经是移到初始的前一位，因此这里应该再加一恢复到初始状态
    p6++;
    delete[] p6; //如果之类不加中括号，则只回收数组的第一个元素


    cout << "***********************深拷贝和浅拷贝****************************" << endl;
    //浅拷贝：两个对象的参数直接复制，指向同一个内存
    // //若被拷贝对象释放内存后，拷贝对象再次释放，则会出现异常
    // Array arr1(5);

    // Array arr2(arr1);
    // arr1.printAddr();
    // arr2.printAddr();

    // 深拷贝: 在拷贝构造函数中首先分配相应的内存，再去复制内容
    Array arr1(5);

    Array arr2(arr1);
    arr1.printAddr();
    arr2.printAddr();

    arr1.printArr();
    arr2.printArr();

    cout << "***********************对象指针****************************" << endl;
    /**********************************************
    指针的方式：			 p ——————-→ m_iX ←—————— p->m_iX
    将p转化为一个对象：	(*p) ————→ m_iY ←—————— p->m_iY
                                    堆区
    **********************************************/
    Teacher *t6 = new Teacher();
    cout << "指针符号取值：" << t6->getCount() << endl;
    cout << "对象方式取值：" << (*t6).getCount() << endl;
    delete t6;
    t6 = NULL;

    Teacher t7;
    Teacher *t8 = &t7;
    t8->setAge(30);
    cout << "通过指针指向的方式操作t7的内存" << t7.getAge() << endl;

    //system("pause");
    return 0;
}

void change(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void fun1(int i, int j, int k)
{
    cout << i << "," << j << "," << k << endl;
}

void fun1(double i, double j)
{
    cout << i << "," << j <<  endl;
}

int max(int i, int j)
{
    int m = 0;
    if (i<j)
    {
        m = j;
    } else
    {
        m = i;
    }
    return m;
}

void test(Teacher Teacher)
{

}