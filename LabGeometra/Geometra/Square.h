#pragma once
#include"Template.h"
#include<iostream>
using namespace std;
template <class T>
class Square :public Template
{
protected:
    int side;
    T** array;
public:
    Square();
    Square(int _side, T fill);
    Square(const Square& Square);
    ~Square();
    int Get_Side();
    T Get_Fill();
    void Set_Side(int _side);
    void Set_Fill(T stil);
    float Area() override;
    ostream& print(ostream& os) override;
    bool operator ==(const Square& other);
    Square<T> operator=(const Square<T>& other);
    void Function(T stil);
};

template<class T>
inline Square<T>::Square()
{
    side = 2;
    this->Function('*');

}

template<class T>
inline Square<T>::Square(int _side, T stil)
{
    side = _side;
    this->Function(stil);
}

template<class T>
inline Square<T>::Square(const Square& Square)
{
    side = Square.side;
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    this->Function(Square.Get_Fill());
}

template<class T>
inline Square<T>::~Square()
{
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
        side = 0;
    }
}

template<class T>
inline int Square<T>::Get_Side()
{
    return side;
}

template<class T>
inline T Square<T>::Get_Fill()
{
    if (array != 0)
    {
        return (array[0][0]);
    }
    else throw - 1;
}

template<class T>
inline void Square<T>::Set_Side(int _side)
{
    side = _side;
}

template<class T>
inline void Square<T>::Set_Fill(T fill)
{
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
            for (int j = 0; j < side; j++)
                array[i][j] = fill;
    }
    else throw - 1;
}

template<class T>
inline float Square<T>::Area()
{
    return (side * side);
}

template<class T>
inline ostream& Square<T>::print(ostream& os)
{
    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
            os << array[i][j];
        os << endl;
    }
    return os;
}

template<class T>
inline bool Square<T>::operator==(const Square& other)
{
    if (side == other.side && array[0][0] == other.array[0][0])
    {
        return true;
    }
    return false;
}

template<class T>
inline Square<T> Square<T>::operator=(const Square<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    side = other.side;
    this->Function(other.Get_Fill());
    return *this;
}

template<class T>
inline void Square<T>::Function(T fill)
{
    array = new T * [side];
    for (int i = 0; i < side; i++)
        array[i] = new T[side];

    for (int i = 0; i < side; i++)
        for (int j = 0; j < side; j++)
            array[i][j] = fill;
}