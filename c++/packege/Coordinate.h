class Coordinate
{
public:
	Coordinate(int x, int y);
	~Coordinate();
	void setX(int x);
	void setX(int x) const;
	int getX() const; //相当于 int getX(const Coordinate *this);
	void setY(int y);
	int getY() const;
	void printInfo() const;
private:
	int m_iX;
	int m_iY;
};