#include <iostream>
#include "Plane.cpp"
#include "Bird.cpp"
#include <typeinfo>
using namespace std;

void doSometing(Flyable *obj)
{
	cout << typeid(*obj).name() << endl;
	cout << typeid(obj).name() << endl;
	obj -> takeoff();
	if(typeid(*obj) == typeid(Bird))
	{
		Bird *bird = dynamic_cast<Bird *>(obj);
		bird -> froaging();
	}

	if(typeid(*obj) == typeid(Plane))
	{
		Plane *plane = dynamic_cast<Plane *>(obj);
		plane -> carry();
	}
	obj -> land();
}

int main(void)
{
	Bird b;
	doSometing(&b);
	cout << "---------------------" << endl;
	double i = 0.0;
	cout << typeid(i).name() << endl; 

	return 0;
}