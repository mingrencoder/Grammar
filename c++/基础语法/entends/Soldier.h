class Soldier:public Person
{
public:
	Soldier();
	virtual ~Soldier();
	void fight();
	//同名函数
	void eat();	
};