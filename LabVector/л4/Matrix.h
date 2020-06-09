#include<iostream>
#include <clocale>
#include <iomanip>
#include"Vector.h"
using namespace std;

template<class M>
class Matrix
{
private:
    void MemorySize(int width, int length)       //выделение памяти
    {
        array = new M * [m];
        for (int i = 0; i < width; i++) this->array[i] = new M[length];
    }
protected:
    int m;   //строки
    int n;   //столбцы
    M** array;
public:
    Matrix();
    Matrix(int a, int b);      //пустая матрица нужной размерности
    Matrix(int c, int d, M** arr);
    Matrix(const Matrix<M>& other);
    ~Matrix();
    M** GetMatrix();           //массив матрицы
    int GetM();               //количество строк
    int GetN();              //количество столбцов
    void SetDimension(int width, int length);       //установить размерность
    void SetMatrix(M** e);           //переписать значение полей в матрице уже созданной размерности
    Matrix<M> operator=(const Matric<M>& other);
    bool operator ==(const Matric<M>& other);
    M*& operator [](const int i);
    Matrix<M> operator+(const Matric<M>& other);
    Matrix<M> operator-(const Matric<M>& other);
    Matrix<M> operator*(const Matric<M>& other);
    template<class M>
    friend ostream& operator<<(ostream& os, const Matric<M>& mat);
    template<class M>
    friend istream& operator>>(istream& in, Matric<M>& mat);
    int FindVector(M a);         //количество вхождений указанного значения
};

template<class M>
Matrix<M>::Matrix()
{
    m = 1;
    n = 1;
    MemorySize(m, n);
    array[0][0] = 0;
}
template<class M>
Matric<M>::Matrix(int a, int b)      
{
    m = a;
    n = b;
    MemorySize(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = 0;
        }
    }
}

template<class M>
Matrix<M>::Matrix(int c, int d, M** arr)
{
    m = c;
    n = d;
    MemorySize(c, d);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = arr[i][j];
}

template<class M>
Matrix<M>::Matrix(const Matrix<M>& other)
{
    m = other.n;
    n = other.m;
    MemorySize(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = other.array[i][j];
}

template<class M>
Matrix<M>::~Matrix()
{
    if (array != 0)
    {
        for (int i = 0; i < m; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
        n = 0;
        m = 0;
    }
}
template<class M>
int Matrix<M>::FindVector(M a)      //количество вхождений указанного значения
{
    int amount = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (massiv[i][j] == a)
            {
               amount = amount + 1;
            }
        }
    }
    return kol;
}

template<class M>
int Matric<M>::GetM()
{
    return m;
}

template<class M>
int Matrix<M>::GetN()
{
    return n;
}

template<class M>
M** Matrix<M>::GetMatrix()
{
    return array;
}

template<class M>
void Matrix<M>::SetDimention(int width, int length)   //установить размерность
{
    m = width;
    n = length;
}

template<class M>
void Matrix<M>::SetMatrix(M** e)       //переписать значение полей в матрице уже созданной размерности
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = e[i][j];        //переписываем массив новых значений
}

template<class M>
Matrix<M> Matrix<M>::operator=(const Matrix<M>& other)
{
    if (*this == other)
        return *this;
    for (int i = 0; i < m; i++)      //удаляем старый массив, чтобы можно было присваивать матрицу другой размерности
    {
        array[i] = 0;
        delete[] array[i];
    }
    delete[] array;
    array = 0;
    m = other.m;
    n = other.n;
    MemorySize(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = other.array[i][j];
        }
    }
    return *this;
}

template<class M>
M*& Matrix<M>::operator [](const int i)
{
    return array[i];
}

template<class M>
bool Matrix<M>::operator==(const Matrix<M>& other)
{
    if (m == other.m && n == other.n)
    {

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (array[i][j] != other.array[i][j])
                    return false;
        return true;
    }
    else
        return false;
}

template<class M>
Matrix<M> Matrix<M>::operator+(const Matrix<M>& other)
{
    if (n == other.n && m == other.m)
    {
        Matrix<M> F(m, n, other.array);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                F.array[i][j] = other.array[i][j] + array[i][j];
            }
        }
        return F;
    }
    else
        throw - 1;
}

template<class M>
Matrix<M> Matrix<M>::operator-(const Matrix<M>& other)
{
    if (n == other.n && m == other.m)
    {
        Matrix<M> F(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                F.array[i][j] = array[i][j] - other.array[i][j];
        return F;
    }
    else
        throw - 1;
}

template<class M>
Matrix<M> Matrix<M>::operator*(const Matrix<M>& other)
{
    if (n == other.m)
    {
        Matrix<M> mas(m, (other.n));        //Делаю пустой массив нужной размерности
        for (int i = 0; i < mas.m; i++)
            for (int j = 0; j < mas.n; j++)
            {
                mas.array[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    mas.array[i][j] = mas.array[i][j] + (array[i][k] * other.array[k][j]);
                }
            }
        return mas;
    }
    else
        throw - 1;

}

template<class M>
ostream& operator<<(ostream& os, const Matrix<M>& mas)
{
    cout << endl;
    for (int i = 0; i < mas.m; i++)
    {
        if (i > 0) os << endl;
        os << "|";
        for (int j = 0; j < mas.n; j++)
            os << mas.array[i][j] << " ";
        os << "|";
    }
    return os;
}

template<class M>
istream& operator>>(istream& in, Matrix<M>& mas)
{
    if ((mas.GetM() != 0) || (mas.GetN() != 0))
    {
        for (int i = 0; i < mas.m; i++)
            delete[] mat.array[i];
        delete[] mat.array;
    }
    cout << "Enter size" << endl;
    cout << "m = " << endl;
    cout << "n = " << endl;
    in >> mas.n;
    mas.MemorySize(mas.m, mas.n);
    for (int i = 0; i < mas.m; i++)
    {
        cout << "Enter " << i + 1 << " line" << endl;
        for (int j = 0; j < mas.n; j++)
            in >> mas.array[i][j];
    }
    return in;
}
