#pragma once
#include "Position.h"
class Circle :
    virtual public Position
{
public:
    double rad;
public:
    Circle();
    ~Circle();
    Circle(double rad);
    Circle(double x, double y, double rad);
    void out();
};