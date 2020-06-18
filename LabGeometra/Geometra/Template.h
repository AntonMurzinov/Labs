#pragma once
#include <iostream>
using namespace std;
class Template
{
public:
    virtual float Area() = 0;
    virtual ostream& print(ostream& os) = 0;
    friend ostream& operator<<(ostream& os, Template& other)
    {
        return other.print(os);
    }
    bool operator > (Template& other)
    {
        if (Area() > other.Area())
            return true;
        return false;
    }
    bool operator < (Template& other)
    {
        if (Area() < other.Area())
            return true;
        return false;
    }
};
