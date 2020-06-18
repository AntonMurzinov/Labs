#pragma once
#include"Template.h"
#include"Square.h"
#include <iostream>
using namespace std;
template <class T>
class Cube : public Template
{
protected:
    int side;
    T*** array;
public:
    Cube();
    Cube(int _side, T stil);
    Cube(const Cube& cube);
    ~Cube();

    int GetSide();
    T GetFill();
    void Set_Side(int _side);

    float Area() override;
    ostream& print(ostream& os) override;

    bool operator ==(const Cube& other);
    Cube<T> operator=(const Cube<T>& other);
    void Function(T Stil); 
};

template<class T>
inline Cube<T>::Cube()
{
    side = 1;
    this->Function('*');
}

template<class T>
inline Cube<T>::Cube(int _side, T fill)
{
    side = _side;
    this->Function(fill);
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
            for (int j = 0; j < side; j++)
            {
                array[i][j] = 0;
                delete[] array[i][j];
            }
        for (int i = 0; i < side; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    side = cube.side;
    this->Function(cube.GetFill());
}

template<class T>
inline Cube<T>::~Cube()
{
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
            for (int j = 0; j < side; j++)
            {
                array[i][j] = 0;
                delete[] array[i][j];
            }
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
inline int Cube<T>::GetSide()
{
    return side;
}

template<class T>
inline T Cube<T>::GetFill()
{
    if (array != 0)
    {
        return (array[0][0][0]);
    }
    else throw - 1;
}

template<class T>
inline void Cube<T>::Set_Side(int _side)
{
    side = _side;
}

template<class T>
inline float Cube<T>::Area()
{
    return (side * side * 6);
}

template<class T>
inline ostream& Cube<T>::print(ostream& os)
{
    Square<T> tmp(side, array[0][0][0]);
    tmp.print(os);
    return os;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& other)
{
    if (side == other.side && array[0][0][0] == other.array[0][0][0])
        return true;
    return false;
}

template<class T>
inline Cube<T> Cube<T>::operator=(const Cube<T>& other)
{
    if (this == other)
    {
        return *this;
    }
    if (array != 0)
    {
        for (int i = 0; i < side; i++)
            for (int j = 0; j < side; j++)
            {
                array[i][j] = 0;
                delete[] array[i][j];
            }
        for (int i = 0; i < side; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    side = other.side;
    this->Function(other.GetFill());
    return *this;
}

template<class T>
inline void Cube<T>::Function(T Fill)
{
    array = new T * *[side];
    for (int i = 0; i < side; i++)
    {
        array[i] = new T * [side];
        for (int j = 0; j < side; j++)
            array[i][j] = new T[side];
    }
    for (int i = 0; i < side; i++)
        for (int j = 0; j < side; j++)
            for (int l = 0; l < side; l++)
                array[i][j][l] = Fill;
}
