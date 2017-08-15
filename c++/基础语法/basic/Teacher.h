#include <string>
using namespace std;

class Teacher
{
public:
	Teacher();
	Teacher(string _name, int _age, int _count = 100);
	//拷贝构造函数
	Teacher(const Teacher &teacher);
	//析构函数
	~Teacher();

	void setName(string _name);
	string getName();
	void setAge(int _age);
	int getAge();
	void teach();

	int getCount();
private:
	string m_strName;
	int m_iAge;
	//定义常量
	const int m_count;
};