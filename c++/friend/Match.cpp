#include "Time.h"
#include "Match.h"
#include <iostream>
using namespace std;

// Match::Match()
// {
// }

// Match::Match(int hour, int min, int sec):m_tTimer(hour, min, sec)
// {
// }

void Match::printMatchTime(Time &t)
{
	cout << t.m_iHour << ":" << t.m_iMinute << ":" << t.m_iSecond << endl;
}

// void Match::testTime()
// {
// 	m_tTimer.print();
// 	cout << m_tTimer.m_iHour << ":" << m_tTimer.m_iMinute << ":" << m_tTimer.m_iSecond << endl;
// }