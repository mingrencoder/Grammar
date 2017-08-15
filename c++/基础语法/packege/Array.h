class Array
{
public:
	Array(int len);
	~Array();
	void setLen(int len);
	int getLen();
	//返回本对象的引用
	Array& getThis();
	//返回this指针
	Array* getThisPointer();
private:
	int len;
};