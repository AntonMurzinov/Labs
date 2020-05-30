#include "HeaderComplex.h"
#include <iostream>

Complex::Complex()
{
	Re = 0;
	Im = 0;
}
void Complex::set(double a, double b)
{
	Re = a;
	Im = b;
}
Complex::Complex(double a, double b)
{
	Re = a;
	Im = b;
}
void Complex::setIm(double _Im)
{
	Im = _Im;
}
void Complex::setRe(double _Re)
{
	Re = _Re;
}
double Complex::getIm()
{
	return Im;
}
double Complex::getRe()
{
	return Re;
}
Complex::Complex(const Complex& H)
{
	Re = H.Re;
	Im = H.Im;
}
Complex operator + (Complex& a, Complex& b)
{
	return Complex(a.Re + b.Re, a.Im + b.Im);
}
Complex operator - (Complex& a, Complex& b)
{
	Complex c;
	c.Re = a.Re - b.Re;
	c.Im = a.Im - b.Im;
	return c;
}
Complex operator * (Complex& a, Complex& b)
{
	Complex c;
	c.Re = a.Re * b.Re - a.Im * b.Im;
	c.Im = a.Re * b.Im + b.Re * a.Im;
	return c;
}
Complex operator / (Complex& a, Complex& b)
{
	Complex c;
	c.Re = (a.Re * b.Re + a.Im * b.Im) / (a.Re * b.Re + a.Im * b.Im);
	c.Im = (a.Re * b.Im - a.Re * b.Im) / (a.Re * b.Re + a.Im * b.Im);
	return c;
}
Complex& Complex:: operator = (const Complex& a)
{
	Re = a.Re;
	Im = a.Im;
	return *this;
}
bool operator == (Complex& a, Complex& b)
{
	return ((a.Re == b.Re) && (a.Im == b.Im));
}
ostream& operator << (ostream& out, Complex& b)
{
	out << b.Re << "+" << b.Im << "i";
	return out;
}
istream& operator >> (istream& in, Complex& b)
{
	in >> b.Im;
	in >> b.Re;
	return in;
}
