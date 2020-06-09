#include <iostream>
#include <clocale>
#include <iomanip>
#include"Matrix.h"

using namespace std;
template <class VECTOR>
class VECTOR
{
protected:
    int size;
    Vector* array;
public:
    VECTOR();
    VECTOR(int r, Vector* A);
    VECTOR(VECTOR& B);
    ~VECTOR();
    Vector* GetVector();
    int GetSize();
    void SetVector(Vector* C);
    void SetSize(int e);
    VECTOR<Vector> operator=(const VECTOR<Vector>& other);
    bool operator ==(const VECTOR<Vector>& other);
    Vector operator [](const int i);
    VECTOR<Vector> operator + (const VECTORr& other);
    VECTOR<Vector> operator - (const VECTOR<Vector>& other);
    Vector operator*(const VECTOR<Vector>& other);
    VECTOR<Vector> operator /(VECTOR<Vector>& other);
    template <class Vector>
    friend ostream& operator<<(ostream& os, const VECTOR<Vector>& vec);
    template <class Vector>
    friend istream& operator>>(istream& in, VECTOR<Vector>& vec);
    clock_t BubbleSort();
    clock_t InsertionSort();
    clock_t QuickSort(int first, int last);
    int FindVector(Vector a);                         //количество вхождений указанного значени€
};


template<class Vector>
VECTOR<Vector>::VECTOR(int r, Vector* A)
{
    array = nullptr;
    try {
        if (r > 0)
        {
            size = r;
            array = new Vector[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = A[i];
            }
        }
        else throw 1;
    }
    catch (int i)
    {
        cout << "Imput error array = 0 " << endl;
        exit(0);
    }
}

template<class Vector>
VECTOR<Vector>::VECTOR(VECTOR& B)
{
    array = nullptr;
    size = B.GetSize();
    array = new Vector[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = B.array[i];
    }
}

template<class Vector>
Vector* VECTOR<Vector>::GetVector()
{
    return array;
}

template<class Vector>
int VECTOR<Vector>::GetSize()
{
    return size;
}

template<class Vector>
void VECTOR<Vector>::SetVector(Vector* C)
{
    int i = strlen(C);
    if (array != 0)
    {
        array = 0;
        delete[] array;
    }
    size = i;
    array = new Vector[size];
    for (int k = 0; k < i; k++)
    {
        array[k] = C[k];
    }
}

template<class Vector>
VECTOR<Vector>::VECTOR()
{
    size = 1;
    array = new Vector[1];
    Vector a = 0;
    array[0] = a;
}

template<class Vector>
VECTOR<Vector>::~VECTOR()
{
    if (array != 0)
    {
        array = 0;
        delete[] array;
    }
    size = 0;
}
template<class Vector>
VECTOR<Vector> VECTOR<Vector>::operator=(const VECTOR<Vector>& other)
{
    if (*this == other)
        return *this;
    delete[] array;
    this->size = other.size;
    array = new Vector[size];
    for (int i = 0; i < size; i++)
        array[i] = other.array[i];
    return *this;
}

template<class Vector>
bool VECTOR<Vector>::operator==(const VECTOR<Vector>& other)
{
    int k = 0;
    if (size == other.size)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == other.array[i])
            {
                k = k + 1;
            }
        }
        if (k == size)
        {
            return true;
        }
        else return false;
    }
    else
        return false;
}
template<class Vector>
Vector VECTOR<Vector>::operator[](const int i)
{
    return array[i];
}

template<class Vector>
VECTOR<Vector> VECTOR<Vector>::operator + (const VECTOR& other)
{
    if (size == other.size)
    {
        VECTOR<Vector> vector(size, other.array);
        for (int i = 0; i < size; i++)
            vector.array[i] = array[i] + other.array[i];
        return vector;
    }
    else
        throw - 1;
}

template<class Vector>
void VECTOR<Vector>::SetSize(int e)
{
    size = e;
}

template<class Vector>
VECTOR<Vector> VECTOR<Vector>::operator-(const VECTOR<Vector>& other)
{
    if (size == other.size)
    {
        MyVector<Vector> vector(size, other.array);
        for (int i = 0; i < size; i++)
            vector.array[i] = array[i] - other.array[i];
        return vector;
    }
    else
        throw - 1;
}

template<class Vector>
Vector VECTOR<Vector>::operator *(const VECTOR<Vector>& other)
{
    Vector res = 0;
    if (size== other.size)
    {
        for (int i = 0; i < size; i++)
            res = res + (array[i] * other.array[i]);
        return res;
    }
    else
        throw - 1;
}

template<class Vector>
VECTOR<Vector> VECTOR<Vector>::operator /(VECTOR<Vector>& other)
{

    if (size != other.GetSize())throw length_error("Imput error");
    VECTOR<Vector> K;
    K = *this;
    for (int i = 0; i < size; i++)
    {
        if (K.array[i] != 0)
        {
            K.array[i] = K.array[i] / other.array[i];
        }

    }
    return K;

}

template<class Vector>
ostream& operator<<(ostream& os, const VECTOR<Vector>& vec)
{
    os << "(";
    for (int i = 0; i < vec.size; i++)
    {
        os << vec.array[i];
        if (i < vec.size - 1)
            os << " ";
    }
    os << ")^T";
    return os;
}

template<class Vector>
istream& operator>>(istream& in, VECTOR<Vector>& vec)
{
    cout << "Enter size" << endl;
    in >> vec.size;
    Vector* mas;
    mas = new Vector[vec.size];
    for (int i = 0; i < vec.size; i++)
    {
        cout << "[" << i << "]" << endl;
        in >> mas[i];
    }
    MyVector<Vector> V(vec.size, mas);
    vec = V;
    mas = 0;
    delete[] mas;
    return in;
}
template<class Vector>
clock_t VECTOR<Vector>::BubbleSort()
{
    clock_t start, finish;
    start = clock();
    Vector tmp = 0;
    int i, j = 0;
    start = clock();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    finish = clock();
    return (finish - start);
}
template<class Vector>
int VECTOR<Vector>::FindVector(Vector a)      //количество вхождений указанного значени€
{
    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == a)
        {
            amount = amount + 1;
        }
    }
    return amount;
}

template<class Vector>
clock_t VECTOR<Vector>::InsertionSort()
{
    int k = 0;
    clock_t start, finish;
    start = clock();
    Vector tmp;

    for (int i = 1; i < size; i++)
    {
        tmp = array[i];
        k = i - 1;
        while (k >= 0 && array[k] > tmp)
        {
            array[k + 1] = array[k];
            k = k - 1;
        }
        array[k + 1] = tmp;
    }
    finish = clock();
    return (finish - start);
}

template<class Vector>
clock_t VECTOR<Vector>::QuickSort(int first, int last)
{
    clock_t t1, t2, t3;
    t1 = clock();
    int i = first, j = last;
    Vector tmp;
    Vector x = array[(first + last) / 2];

    do {
        while (array[i] < x)
            i++;
        while (array[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        t3 = QuickSort(i, last);
    if (first < j)
        t3 = QuickSort(first, j);
    t2 = clock();
    return t2 - t1;
}

template<class Vector>
inline int VECTOR<Vector>::FindVector(Vector a)
{
    return 0;
}
