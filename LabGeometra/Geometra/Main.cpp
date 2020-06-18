#include"Point.h"
#include"Template.h"
#include"Line.h"
#include"Circle.h"
#include"Square.h"
#include"Rectangle.h"
#include"triangle.h"
#include<iostream>
#include<stdlib.h>
#include"Cube.h"
#include"Conteiner.h"
//#include "Windows.h"


using namespace std;
int main()
{
	system("color 0B");
	//HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | BACKGROUND_RED);
	cout << "Poin" << endl;
	Point<char> A;
	cout << A << endl;
	cout << "Line" << endl;
	Line<char> C(15, '-');
	cout << C << endl;


	cout << "Circle" << endl;
	Circle<int> D(5, 0);
	cout << D << endl;
	cout << "Square" << endl;
	Square<int> AB(5, 0);
	cout << AB << endl;
	cout << "Rectangle" << endl;
	Rectangle<int> ABC(8, 2, 0);
	cout << ABC << endl;
	cout << "Triangle" << endl;
	Triangle<int> ABCDE(7, 0);
	cout << ABCDE << endl;
	Cube<char> ABCD(5, '*');
	cout << "Cube Projection (*)" << endl;
	cout << ABCD << endl;

	cout << "Repository" << endl;
	Container Repository;
	Repository.Add(A);
	Repository.Add(C);
	Repository.Add(D);
	Repository.Add(AB);
	Repository.Add(ABC);
	Repository.Add(ABCDE);
	cout << Repository;
	cout << "Withdraw 3 object, its a square!" << endl << endl;
	Repository.out_object(3);
	cout << "Delete object 1,3" << endl << endl;
	cout << "Repository" << endl;
	Repository.Delete(C);
	Repository.Delete(AB);
	cout << Repository;
	return 0;
}