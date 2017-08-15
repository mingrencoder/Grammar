#include "Coordinate.cpp"

class Line
{
public:
	Line(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	~Line();
	void setA(int x, int y);
	void setB(int x, int y);
	//对象成员信息打印
	void printInfo();
	//对象成员指针信息打印
	void printPointerInfo();

	//两个printInfo函数互为重载
	void printInfo() const; 
private:
	//对象成员
	const Coordinate m_coorA; //常对象成员
	Coordinate m_coorB;
	//对象成员指针
	Coordinate *m_pCoorA;
	Coordinate *m_pCoorB;
};