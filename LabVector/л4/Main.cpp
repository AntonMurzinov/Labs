#include <cstdlib>
#include <time.h>
#include <clocale>
#include <malloc.h>
#include <vector>
#include<iostream>
#include <iomanip>
#include"Header.h"
#include"Matrix.h"
#include"Vector.h"
using namespace std;
int main()
{
	cout << "Create Vector 1" << endl;
	VECTORr<int> A;
	cin >> A;
	cout << "Return Vector 1" << endl;
	cout << A << "\n";
	int K = 0;
	int arr[] = { 8,2,1,4,8,6,7 };
	int arrr[] = { 2,3,4,5,6,7,8 };
	VECTOR<int> B(7, arr);          //создадим два вектора одинаковой размерности для операций над ними
	VECTOR<int> C(7, arrr);
	VECTOR<int> D;
	cout << "Addition" << endl;
	D = B + C;
	cout << D << "\n";
	cout << "Multiplication" << endl;
	K = B * C;
	cout << K << "\n";
	cout << "Subtraction" << endl;
	D = B - C;
	cout << D << "\n";
	cout << "Division" << endl;
	D = C / B;
	cout << D << "\n";
	cout << "Sorts" << endl << endl;
	cout << "BubbleSort" << endl;
	int t = clock();
	int arrr1[] = { 9,2,3,4,5,6,7 };
	VECTOR<int> AH(7, arrr1);
	t = AH.BubbleSort();
	cout << "Time sort" << t << endl;
	cout << "Sorted vector" << endl;
	cout << AH << endl << endl;
	int arrr2[] = { 9,2,1,4,5,6,3 };
	VECTOR<int> U(7, arrr2);
	cout << "QuickSort" << endl;
	int o = clock();
	o = U.QuickSort(0, B.GetRazmer() - 1);
	cout << "Time sort" << o << endl;
	cout << "Sorted vector" << endl;
	cout << U << "\n" << "\n";

	int arrr3[] = { 9,2,3,2,5,6,4 };
	VECTOR<int> E(7, arrr3);
	cout << "InsertionSort" << endl;
	int w = clock();
	w = E.InsertionSort();
	cout << "Time sort" << w << endl;
	cout << "Sorted vector" << end;;
	cout << E << endl << endl;
	cout << "Matrix 1 " << endl;
	Matrix<int> AB;
	cin >> AB;
	cout << "Square Matrix 1" << AB << endl;
	cout << "Enter dimension";
	cout << "Matrica 2" << endl;
	Matrix<int> AC;
	cin >> AC;
	cout << "Matrix 2" << AB << endl;
	Matrix<int> ABC;

	cout << "Addition" << endl;
	ABC = AB + AC;
	cout << ABC << endl;
	cout << "Multiplication" << endl;
	ABC = AB * AC;
	cout << ABC << endl;
	cout << "Division" << endl;
	ABC = AB - AC;
	cout << ABC << endl;
	cout << "The number of occurrences of the specified value" << endl;
	cout << "Multiplication Vector*Matrix" << endl;
	int arrar[] = { 1,2,3 };
	VECTOR<int> V1(3, arrar);
	Matrix<int> V2;
	Matrix<int> V3;
	cout << "Enter dimention 1*3" << endl;
	cin >> V2;
	V3 = V1 * V2;
	cout << V3 << endl;
	cout << "Multiplication Matrix*Vector" << endl;
	Matrix<int> VV;
	cout << "Enter dimention 3*3" << endl;
	cin >> VV;
	int arrr4[] = { 9,2,1 };
	VECTOR<int> L(3, arrr4);
	VECTOR<int> I;
	I = VV * L;
	cout << I << endl;
	int K;
	K = E.FindVector(3);
	cout << K << endl;

	int F;
	F = AB.FindVector(2);
	cout << F << endl;
	return 0;
}