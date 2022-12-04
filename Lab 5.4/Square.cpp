#include "Square.h"
#include <iostream>

Square::Square()
{
}

Square::~Square()
{
}

Square::Square(double x, double y, double side)
{
	c1[0] = x - side / 2;
	c1[1] = y + side / 2;
	c2[0] = x + side / 2;
	c2[1] = y + side / 2;
	c3[0] = x - side / 2;
	c3[1] = y - side / 2;
	c4[0] = x + side / 2;
	c4[1] = y - side / 2;
}

Square::Square(double side)
{
	this->getrandom();
	c1[0] = x - side / 2;
	c1[1] = y + side / 2;
	c2[0] = x + side / 2;
	c2[1] = y + side / 2;
	c3[0] = x - side / 2;
	c3[1] = y - side / 2;
	c4[0] = x + side / 2;
	c4[1] = y - side / 2;
}

void Square::out()
{
	std::cout << '\n' << c1[0] << ' ' << c1[1] << '\t' << c2[0] << ' ' << c2[1] << '\n' << c3[0] << ' ' << c3[1] << '\t' << c4[0] << ' ' << c4[1] << '\n';
}