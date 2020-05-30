#include<iostream>

using namespace std;
class Complex
{
public:
	Complex();
	void set(double a, double b);
	Complex(double a, double b);
	void setIm(double _Im);
	void setRe(double _Re);
	double getIm();
	double getRe();
	Complex(const Complex& H);
	friend  Complex operator + (Complex& a, Complex& b);
	friend Complex operator - (Complex& a, Complex& b);
	friend Complex operator * (Complex& a, Complex& b);
	friend Complex operator / (Complex& a, Complex& b);
	Complex& operator = (const Complex& a);
	friend bool operator == (Complex& a, Complex& b);
	friend ostream& operator << (ostream& out, Complex& b);
	friend istream& operator >> (istream& in, Complex& b);

private:
	double Im;
	double Re;
};

