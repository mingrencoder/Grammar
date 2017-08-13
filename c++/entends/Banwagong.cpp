#include <iostream>
#include "Banwagong.h"
using namespace std;

Banwagong::Banwagong()
{
	cout << "Banwagong()" << endl;
}
void Banwagong::net()
{
	m_strName = "Wade";
	cout << m_strName << endl;
	cout << "Banwagong -- net" << endl;
}