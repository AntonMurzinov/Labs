#include "HeaderComplex.h"
#include <iostream>
#include <windows.h>


using namespace std;

int main()
{
	Complex a;
	Complex b(3, 4);
	Complex c(b);
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << a << " " << b << " " << c << " Constructors" << endl;
	SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
	c.set(4, 5);
	cout << c.getRe() << " + " << c.getIm() << "i" << " - SET&&GET" << endl;
	Complex d;
	d = a + b;
	cout << d << " Operator + " << endl;
	d = d - b;
	cout << d << " Operator - " << endl;
	d = c / b;
	cout << d << "Ooperator * " << endl;
	d = b;
	cout << " Operator / " << d << endl;
	d = c * b;
	cout << d << " Operator = " << endl;
	cout << (d == b) << " Operator == " << endl;
	cout << (a == b) << " Operator == " << endl;
	SetConsoleTextAttribute(hOUTPUT, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	Complex r;
	cin >> r;
	cout << r << " Operator cin>> " << endl;
	return 0;
}