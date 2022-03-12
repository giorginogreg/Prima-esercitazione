#ifndef MATRIX_H
#define MATRIX_H

#pragma once

class Matrix
{
public:
    typedef double type_elem;
    Matrix(int, int);
    Matrix(int, int, type_elem);
    ~Matrix();
    type_elem read_value_at(int, int);
    void write_value_at(int, int, type_elem);
    void scalar_product(type_elem);

private:
    int _rows;
    int _cols;
    type_elem **_matrix;

    bool out_of_bound(int row, int col);
};

#endif