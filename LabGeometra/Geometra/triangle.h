#pragma once
#include"Template.h"
#include"Line.h"
#include<iostream>
using namespace std;
template <class T>
class Triangle :public Template
{
protected:
    int height;
    T** array;

public:
    Triangle();
    Triangle(int _height, T fill);
    Triangle(const Triangle& triangle);
    ~Triangle();
    int GetHeight();
    T GetFill();
    void SetHeight(int _height);
    float Area() override;
    ostream& print(ostream& os) override;
    bool operator ==(const Triangle& other);
    Triangle<T> operator=(const Triangle<T>& other);
    void Function(T fill);
};


inline Triangle<char>::Triangle()
{
    height = 3;
    this->Function('*');
}

template<class T>
inline Triangle<T>::Triangle(int _height, T fill)
{
    height = _height + 1;
    this->Function(fill);
}

template<class T>
inline Triangle<T>::Triangle(const Triangle& triangle)
{
    if (array != 0)
    {
        for (int i = 0; i < height; i++)
            delete[] array[i];
        delete[] array;
    }
    height = triangle.height;
    this->Function(triangle.GetFill());
}

template<class T>
inline Triangle<T>::~Triangle()
{
    if (array != 0)
    {
        for (int i = 0; i < height; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
        height = 0;
    }
}

template<class T>
inline int Triangle<T>::GetHeight()
{
    return height - 1;
}

template<class T>
inline T Triangle<T>::GetFill()
{
    if (array != 0)
    {
        return array[0][0];
    }
    else throw - 1;
}

template<class T>
inline void Triangle<T>::SetHeight(int _height)
{
    height = _height;
}

template<class T>
inline float Triangle<T>::Area()
{
    return ((height - 1) * (height - 1)) / 2;
}

template<class T>
inline ostream& Triangle<T>::print(ostream& os)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i; j++)
            os << array[i][j];
        os << endl;
    }
    return os;
}

template<class T>
inline bool Triangle<T>::operator==(const Triangle& other)
{
    if (height == other.height && array[0][0] == other.array[0][0])
        return true;
    return false;
}

template<class T>
inline Triangle<T> Triangle<T>::operator=(const Triangle<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    if (array != 0)
    {
        for (int i = 0; i < height; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    height = other.height;
    this->Function(other.GetFill());
    return *this;
}

template<class T>
inline void Triangle<T>::Function(T fill)
{
    array = new T * [height];
    for (int i = 0; i < height; i++)
        array[i] = new T[height];


    for (int i = 0; i < height; i++)
        for (int j = 0; j < i; j++)
            array[i][j] = fill;
}