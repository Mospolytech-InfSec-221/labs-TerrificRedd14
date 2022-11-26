#pragma once
#include <iostream>
class D3Matrix
{
private:
	int rows, cols;
	double* elem;
public:
	D3Matrix();
	~D3Matrix();
	D3Matrix(const int size_rows);
	double get_elem(int i, int j) const;
	void output() const;
	double trase();
	int columns();
	void input();
	void input(int size);
	void copy(const D3Matrix& temp);
	void operator+=(D3Matrix& temp);
	void operator=(const D3Matrix& temp);
	void operator+(D3Matrix& right);
	void operator-(D3Matrix& right);
	void operator*(double k);
	void operator-=(D3Matrix& temp);

	friend void operator-(D3Matrix& left);
	friend std::istream& operator>>(std::istream& input, D3Matrix& temp);
	friend std::ostream& operator<<(std::ostream& out, const D3Matrix& temp);
};