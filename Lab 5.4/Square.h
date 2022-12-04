#pragma once
#include "Position.h"
class Square :
    virtual public Position
{
public:
    double c1[2];
    double c2[2];
    double c3[2];
    double c4[2];
    Square();
    ~Square();
    Square(double x, double y, double side);
    Square(double side);
    void out();
};
