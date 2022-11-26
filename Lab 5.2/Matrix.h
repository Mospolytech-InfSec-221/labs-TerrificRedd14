#pragma once
class Matrix
{
private:
	int size_col, size_row;
	double* elem;
	int i1, j1;
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(int row, int col, const double*arr);
	Matrix(int size);
	Matrix(const Matrix& temp);
	~Matrix();

	void output();
	void sum_matrix(const Matrix& temp);
	Matrix sum_matrix(const double* arr);
	void mult_number(int number);
	void mult_matrix(const Matrix& temp);
	Matrix mult_matrix(const double* arr);
	double get_elem(int i, int j) { return elem[i * size_col + j]; }
	int get_row() const { return size_row; }
	int get_col() const { return size_col; }
	double trase();
	void input(int row, int col);
	void input(int row, int col, double* arr);
};
