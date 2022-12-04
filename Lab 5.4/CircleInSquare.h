#pragma once
#include "Circle.h"
#include "Square.h"
class CircleInSquare :
    public Circle, public Square
{
public:
    CircleInSquare();
    ~CircleInSquare();
    CircleInSquare(double x, double y, double rad);
    CircleInSquare(double seide);
};