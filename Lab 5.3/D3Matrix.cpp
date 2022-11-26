#include "D3Matrix.h"

#include <iostream>

D3Matrix::D3Matrix()
{
	rows = 0;
	cols = 0;
}

D3Matrix::~D3Matrix()
{
	if (elem != nullptr)
		delete[]elem;
}

D3Matrix::D3Matrix(const int size_rows)
{
	rows = size_rows;
	cols = size_rows;
	if (elem != nullptr)
		delete[]elem;
	elem = new double[size_rows * 3];
	std::cout << "Enter the elements of matrix ";
	for (int i = 0; i < cols * 3; i++)
	{
		std::cin >> elem[i];
	}
	elem[rows - 1] = 0;
	elem[rows * 2] = 0;
}

double D3Matrix::get_elem(int i, int j) const
{
	if (i == j) return elem[rows + i];
	else if (i == j + 1) return elem[rows * 2 + i];
	else if (i + 1 == j) return elem[i];
	else return 0;
}

void D3Matrix::output() const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << '\n';
	}
}

double D3Matrix::trase()
{
	double out = 0;
	for (int i = 0; i < this->cols; i++) {
		out += this->get_elem(i, i);
	}
	return out;
}

int D3Matrix::columns()
{
	return rows;
}

void D3Matrix::input(int size)
{
	rows = size;
	cols = size;
	if (elem != nullptr)
		delete[]elem;
	std::cout << "Enter the matrix ";
	elem = new double[size * 3];
	for (int i = 0; i < size * 3; i++)
	{
		if (i != rows - 1 or i != rows * 2)
			std::cin >> elem[i];
		else elem[i] = 0;
	}
}

void D3Matrix::copy(const D3Matrix& temp)
{
	if (elem != nullptr)
		delete[]elem;
	elem = new double[temp.cols * 3];
	this->cols = temp.cols;
	this->rows = temp.rows;
	for (int i = 0; i < temp.cols * 3; i++) this->elem[i] = temp.elem[i];
}

void D3Matrix::operator+=(D3Matrix& temp)
{
	for (int i = 0; i < temp.rows * 3; i++) {
		this->elem[i] += temp.elem[i];
	}
}

void D3Matrix::operator-=(D3Matrix& temp)
{
	for (int i = 0; i < temp.rows * 3; i++) {
		this->elem[i] -= temp.elem[i];
	}
}

void D3Matrix::operator=(const D3Matrix& temp)
{
	this->copy(temp);
}

void D3Matrix::operator+(D3Matrix& right)
{
	D3Matrix out;
	out = right;
	for (int i = 0; i < right.cols * 3; i++)
	{
		out.elem[i] = this->elem[i] + right.elem[i];
	}
	std::cout << out;
}

void D3Matrix::operator-(D3Matrix& right)
{
	D3Matrix out;
	out = right;
	for (int i = 0; i < right.cols * 3; i++)
	{
		out.elem[i] = this->elem[i] - right.elem[i];
	}
	std::cout << out;
}


void D3Matrix::operator*(double k)
{
	for (int i = 0; i < rows * 3; i++) elem[i] *= k;
}


void D3Matrix::input()
{
	int size;
	std::cout << "Enter the size of matrix ";
	std::cin >> size;
	this->input(size);
}

std::istream& operator>>(std::istream& input, D3Matrix& temp)
{
	int size;
	std::cout << "Enter the size of matrix ";
	input >> size;
	temp.input(size);
	return input;
}

void operator-(D3Matrix& left)
{
	for (int i = 0; i < left.cols * 3; i++) left.elem[i] *= -1;
	left.output();
}


std::ostream& operator<<(std::ostream& out, const D3Matrix& temp)
{
	for (int i = 0; i < temp.rows; i++) {
		for (int j = 0; j < temp.rows; j++) {
			out << temp.get_elem(i, j) << " ";
		}
		out << '\n';
	}
	return out;
}