#pragma once
#include"Template.h"
#include<iostream>
using namespace std;
template <class T>
class Rectangle :public Template
{
protected:
    int length;
    int width;
    T** array;
public:
    Rectangle();
    Rectangle(int _length, int _width, T fill);
    Rectangle(const Rectangle& rectangle);
    ~Rectangle();
    int Get_Length();
    int Get_Width();
    T Get_Fill();
    void Set_Size(int _length, int _width);
    void Set_Fill(T fill);
    float Area() override;
    ostream& print(ostream& os) override;
    bool operator ==(const Rectangle& other);
    Rectangle<T> operator=(const Rectangle<T>& other);
    void Function(T fill);
};

template<class T>
inline Rectangle<T>::Rectangle()
{
    length = 2;
    width = 3;
    this->Function('*');

}

template<class T>
inline Rectangle<T>::Rectangle(int _length, int _width, T fill)
{
    length = _length;
    width = _width;
    this->Function(fill);
}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle& rectangle)
{
    length = rectangle.length;
    width = rectangle.width;
    if (array != 0)
    {
        for (int i = 0; i < width; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    this->Function(rectangle.Get_Fill());
}

template<class T>
inline Rectangle<T>::~Rectangle()
{
    if (array != 0)
    {
        for (int i = 0; i < width; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
        length = 0;
        width = 0;
    }
}

template<class T>
inline int Rectangle<T>::Get_Length()
{
    return length;
}

template<class T>
inline int Rectangle<T>::Get_Width()
{
    return width;
}

template<class T>
inline T Rectangle<T>::Get_Fill()
{
    if (array != 0)
    {
        return (array[0][0]);
    }
    else throw - 1;
}

template<class T>
inline void Rectangle<T>::Set_Size(int _length, int _width)
{
    length = _length;
    width = _width;
}

template<class T>
inline void Rectangle<T>::Set_Fill(T fill)
{
    if (array != 0)
    {
        for (int i = 0; i < width; i++)
            for (int j = 0; j < length; j++)
                array[i][j] = fill;
    }
    else throw - 1;
}

template<class T>
inline float Rectangle<T>::Area()
{
    return (width * length);
}

template<class T>
inline ostream& Rectangle<T>::print(ostream& os)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            os << array[i][j];
        os << endl;
    }
    return os;
}

template<class T>
inline bool Rectangle<T>::operator==(const Rectangle& other)
{
    if (length == other.length && width == other.width && array[0][0] == other.array[0][0])
        return true;
    return false;
}

template<class T>
inline Rectangle<T> Rectangle<T>::operator=(const Rectangle<T>& other)
{
    if (*this == other)
    {
        return *this;
    }
    if (array != 0)
    {
        for (int i = 0; i < width; i++)
        {
            array[i] = 0;
            delete[] array[i];
        }
        array = 0;
        delete[] array;
    }
    length = other.length;
    width = other.width;
    this->Function(other.Get_Fill());
    return *this;
}

template<class T>
inline void Rectangle<T>::Function(T fill)
{
    array = new T * [width];
    for (int i = 0; i < width; i++)
        array[i] = new T[length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = fill;
}
