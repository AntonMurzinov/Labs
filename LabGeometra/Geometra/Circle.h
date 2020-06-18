#pragma once
#include"Template.h"
#include<iostream>
using namespace std;
template <class T>
class Circle :public Template
{
protected:
    int radius;
    T** array;
public:
    Circle();
    Circle(int _radius, T fill);
    Circle(const Circle& circle);
    ~Circle();
    int Get_Radius();
    T Get_Fill();
    void Set_Radius(int _radius);
    float Area() override;
    ostream& print(ostream& os) override;
    bool operator ==(const Circle& other);
    Circle<T> operator=(const Circle<T>& other);
    void Function(T _fill);
};

template<class T>
inline Circle<T>::Circle()
{
    radius = 2;
    this->Function('*');
}
template<class T>
void Circle<T>::Function(T _fill)
{
    array = new T * [2 * radius - 1];
    for (int i = 0; i < 2 * radius - 1; i++)
        array[i] = new T[2 * radius];

    for (int i = 0; i < radius; i++)
        for (int j = radius - 1 - i; j < radius + i + 1; j++)
            array[i][j] = _fill;

    for (int i = radius; i < 2 * radius - 1; i++)
        for (int j = 1 + i - radius; j < 3 * radius - 1 - i; j++)
            array[i][j] = _fill;
}

template<class T>
inline Circle<T>::Circle(int _radius, T fill)
{
    radius = _radius;
    this->Function(fill);
}

template<class T>
inline Circle<T>::Circle(const Circle& circle)
{
    radius = circle.radius;
    if (array != 0)
    {
        for (int i = 0; i < 2 * radius - 1; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    this->Function(circle.Get_Fill());
}

template<class T>
inline Circle<T>::~Circle()
{
    if (array != 0)
    {
        for (int i = 0; i < 2 * radius - 1; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    radius = 0;
}

template<class T>
inline int Circle<T>::Get_Radius()
{
    return radius;
}

template<class T>
inline T Circle<T>::Get_Fill()
{
    if (array != 0)
    {
        return this->array[0][0];
    }
    else throw - 1;
}

template<class T>
inline void Circle<T>::Set_Radius(int _radius)
{
    radius = _radius;
}

template<class T>
inline float Circle<T>::Area()
{
    return (radius * radius * 3.14);
}

template<class T>
inline ostream& Circle<T>::print(ostream& os)
{
    for (int i = 0; i < 2 * radius - 1; i++)
    {
        for (int j = 0; j < 2 * radius; j++)
        {
            if ((i < radius && j >= (radius - 1 - i) && j < (radius + i + 1)) || (i >= radius && i < (2 * radius - 1) && j >= (1 + i - radius) && j < (3 * radius - 1 - i)))
                os << array[i][j];
            else os << " ";
        }
        os << endl;
    }
    return os;
}

template<class T>
inline bool Circle<T>::operator==(const Circle& other)
{
    if (radius == other.Get_Radius)
    {
        if (array[radius][radius] == other.array[radius][radius])
        {
            return true;
        }
    }
    return false;
}

template<class T>
inline Circle<T> Circle<T>::operator=(const Circle<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    if (array != 0)
    {
        for (int i = 0; i < 2 * radius - 1; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    radius = other.radius;
    this->Function(other.Get_Fill());
    return *this;
}
