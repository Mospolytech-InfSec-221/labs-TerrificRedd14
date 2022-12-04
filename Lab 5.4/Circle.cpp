#include "Circle.h"
#include <iostream>

Circle::Circle()
{
}

Circle::~Circle()
{
}

Circle::Circle(double rad)
{
	this->getrandom();
	this->rad = rad;
}

Circle::Circle(double x, double y, double rad)
{
	this->x = x;
	this->y = y;
	this->rad = rad;
}

void Circle::out()
{
	std::cout << '\n' << x << ' ' << y << ' ' << rad << '\n';
}