#include <string>
using namespace std;

class Person
{
public:
	Person();
	virtual ~Person();
	void eat();

	void play();
protected:
	string m_strName;
	int m_iAge;	
private:
};