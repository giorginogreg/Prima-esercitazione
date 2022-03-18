#ifndef MATRIX_H
#define MATRIX_H

#pragma once

class Matrix
{
public:
    typedef double type_elem;
    Matrix(const Matrix &m);
    Matrix(const int, const int);
    Matrix(const int rows, const int cols, const type_elem initial_value);
    // Destructor knows only how to deallocate private variables, but if there are
    // any complex types like pointers ecc. with some allocated value, i need to
    // update this method instructing destructor on how does it have to do
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