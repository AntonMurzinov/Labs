#pragma once
#include"Point.h"
#include"Template.h"
#include"Line.h"
#include"Circle.h"
#include"Square.h"
#include"Rectangle.h"
#include"triangle.h"
#include<iostream>
#include<stdlib.h>
#include"Cube.h"

class Container
{
protected:
    Template** array;
    int size;
public:
    Container();
    ~Container();
    Template* operator[](const int i);
    template <class T>
    void Add(T& other);  
    template <class T>
    void Delete(T& other);  
    void out_object(int i); 
    friend ostream& operator<<(ostream& out, Container& other);
};

Container::Container()
{
    array = 0;
    size = 0;
}
Container::~Container()
{
    if (array != 0)
    {
        array = 0;
        delete[] array;
    }
    size = 0;
}

Template* Container::operator[](const int i)
{
    return array[i];
}

void Container::out_object(int i)
{
    cout << *(array[i]);
}

ostream& operator<<(ostream& out, Container& other)
{
    for (int i = 0; i < other.size; i++)
    {
        out << *(other[i]) << endl;
    }
    return out;
}



template<class T>
inline void Container::Add(T& other)
{
    Template** objects = new Template * [size];
    for (int i = 0; i < size; i++)
    {
        objects[i] = array[i];
    }
    array = 0;
    delete[]array;
    size++;
    array = new Template * [size];
    for (int i = 0; i < size - 1; i++)
    {
        array[i] = objects[i];
    }
    array[size - 1] = (&other);
    objects = 0;
    delete[]objects;
}

template<class T>
inline void Container::Delete(T& other)
{
    Template** objects = new Template * [size];
    int j = 0;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == &other)
        {
            k = 1;
        }
        else
        {
            objects[j] = array[i];
            j++;
        }
    }
    if (k == 0)
        throw - 1;
    delete[] array;
    array = new Template * [size - 1];
    size = size - 1;
    for (int i = 0; i < size; i++)
        array[i] = objects[i];
    delete objects;
}
