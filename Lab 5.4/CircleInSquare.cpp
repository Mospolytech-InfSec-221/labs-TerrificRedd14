#include "CircleInSquare.h"

CircleInSquare::CircleInSquare()
{
}

CircleInSquare::~CircleInSquare()
{
}

CircleInSquare::CircleInSquare(double x, double y, double rad)
{
	this->x = x;
	this->y = y;
	double side = 2 * rad;
	c1[0] = x - side / 2;
	c1[1] = y + side / 2;
	c2[0] = x + side / 2;
	c2[1] = y + side / 2;
	c3[0] = x - side / 2;
	c3[1] = y - side / 2;
	c4[0] = x + side / 2;
	c4[1] = y - side / 2;
	this->rad = rad;
}

CircleInSquare::CircleInSquare(double side)
{
	this->getrandom();
	rad = side / 2;
	c1[0] = x - side / 2;
	c1[1] = y + side / 2;
	c2[0] = x + side / 2;
	c2[1] = y + side / 2;
	c3[0] = x - side / 2;
	c3[1] = y - side / 2;
	c4[0] = x + side / 2;
	c4[1] = y - side / 2;
}