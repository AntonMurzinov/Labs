#pragma once
#include "Template.h"
#include<iostream>
using namespace std;
template <class T>
class Line :public Template
{
protected:
    int size;
    T* array;
public:
    Line();
    Line(int _size, T* _array);
    Line(int _size, T form);
    Line(const Line& _Line);
    ~Line();
    int Get_Size();
    T Get_Array();
    void Set_Size(int _size);
    void Set_Array(int _size, T* _array);
    float Area() override;
    ostream& print(ostream& os) override;
    bool operator ==(const Line& other);
    Line<T> operator=(const Line<T>& other);
};

template<class T>
Line<T>::Line()
{
    size = 2;
    array = new char[2];
    for (int i = 0; i < size; i++)
    {
        array[i] = "*";
    }
}

template<class T>
inline Line<T>::Line(int _size, T* _array)
{
    size = _size;
    array = new char[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = _array[i];
    }
}

template<class T>
inline Line<T>::Line(int _size, T form)
{
    size = _size;
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = form;
    }
}

template<class T>
inline Line<T>::Line(const Line& _Line)
{
    size = _Line.size;
    if (array != 0)
    {
        array = 0;
        delete[] array;
    }
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = _Line.array[i];
    }
}

template<class T>
inline Line<T>::~Line()
{
    if (this->array != 0)
    {
        size = 0;
        array = 0;
        delete[] array;
    }
}

template<class T>
inline int Line<T>::Get_Size()
{
    return size;
}

template<class T>
inline T Line<T>::Get_Array()
{
    return array;
}

template<class T>
inline void Line<T>::Set_Size(int _size)
{
    size = _size;
}

template<class T>
inline void Line<T>::Set_Array(int _size, T* _array)
{
    size = _size;
    if (array != 0)
    {
        array = 0;
        delete[] array;
    }
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = _array[i];
    }
}

template<class T>
Line<T> Line<T>::operator=(const Line<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    array = 0;
    delete[] array;
    size = other.size;
    array = new T[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
    return *this;
}

template<class T>
inline float Line<T>::Area()
{
    return 0.0f;
}

template<class T>
inline ostream& Line<T>::print(ostream& os)
{
    for (int i = 0; i < size; i++)
    {
        os << array[i];
    }
    os << endl;
    return os;
}

template<class T>
inline bool Line<T>::operator==(const Line& other)
{
    int kol = 0;
    if (size = other.size)
    {
        for (int i = 0; i < size; i++)
        {
            kol = kol + 1;
        }
    }
    if (kol == size)
    {
        return true;
    }
    else return false;
}
