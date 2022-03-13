#ifndef MATRIX_H
#define MATRIX_H

#pragma once

class Matrix
{
public:
    typedef double type_elem;
    Matrix(const int, const int);
    Matrix(const int rows, const int cols, const type_elem initial_value);
    ~Matrix();
    Matrix::type_elem read_value_at(const int, const int) const;
    void write_value_at(const int, const int, const type_elem);
    void scalar_product(type_elem const scalar);

    void transpose(const Matrix &m);

    void print_matrix();

    Matrix operator*(const Matrix &m);

    int rows() const { return _rows; }
    void setRows(int rows) { _rows = rows; }

    int cols() const { return _cols; }
    void setCols(int cols) { _cols = cols; }

private:
    int _rows;
    int _cols;
    type_elem **_matrix;
    bool out_of_bound(int const row, int const col) const;
    bool is_multiplication_valid(const Matrix &m) const;
};

#endif