#ifndef TIME_H
#define TIME_H
#include "Match.h"
// class Match;
class Time
{
	// 友元类
	// friend Match;
	// 推荐写在前面的位置
	// 声明友元全局函数
	friend void printTime(Time &t);
	// 声明友元成员函数
	friend void Match::printMatchTime(Time &t);

public:
	Time(int hour, int min, int sec);
private:
	// void print();
	int m_iHour;
	int m_iMinute;
	int m_iSecond;
};

#endif