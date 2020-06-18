#pragma once
#include<iostream>
#include"Template.h"
using namespace std;
template<class T>
class Point : public Template
{
protected:
    T point;
public:
    Point();
    Point(T _point);
    Point(const Point& _Point);
    ~Point();
    T Get();
    void Set(T _point);
    float Area() override;
    ostream& print(ostream& os) override;
    bool operator ==(const Point& other);
    Point<T> operator=(const Point<T>& other);
};
template<class T>
Point<T>::Point()
{
    point = '.';
}
template<class T>
Point<T>::Point(T _point)
{
    point = _point;
}
template<class T>
Point<T>::Point(const Point& _Point)
{
    point = _Point.point;
}
template<class T>
T Point<T>::Get()
{
    return point;
}
template<class T>
Point<T>::~Point()
{
    point = 0;
}
template<class T>
void Point<T>::Set(T _point)
{
    point = _point;
}
template<class T>
float Point<T>::Area()
{
    return 0;
}
template<class T>
bool Point<T>::operator ==(const Point& other)
{
    if (point == other.point)
    {
        return true;
    }
    else false;
}

template<class T>
Point<T> Point<T>::operator=(const Point<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    point = other.point;
    return *this;
}
template<class T>
ostream& Point<T>::print(ostream& os)
{
    os << this->Get();
    return os;
}
