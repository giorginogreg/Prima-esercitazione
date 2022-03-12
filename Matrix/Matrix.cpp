#include "Matrix.h"
#include <string>

Matrix::Matrix(int rows, int cols)
{
    _rows = rows;
    _cols = cols;

    _matrix = new type_elem* [rows];
    for (int i = 0; i < rows; i++)
    {
        _matrix[i] = new type_elem[cols];
        for (int j = 0; j < cols; j++) {
            _matrix[i][j] = 0;
        }
    }
}
Matrix::Matrix(int rows, int cols, type_elem initial_value)
{
    _rows = rows;
    _cols = cols;

    _matrix = new type_elem* [rows];
    for (int i = 0; i < rows; i++)
    {
        _matrix[i] = new type_elem[cols];
        for (int j = 0; j < cols; j++) {
            _matrix[i][j] = initial_value;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < _cols; i++)
    {
        delete[] _matrix[i];
    }
    delete[] _matrix;
    
}

void Matrix::write_value_at(int row, int col, type_elem val) {
    if(Matrix::out_of_bound(row, col))
        throw std::string("Error: out of index");

    _matrix[row][col] = val;
}

Matrix::type_elem Matrix::read_value_at(int row, int col) {
    if(Matrix::out_of_bound(row, col))
        throw std::string("Error: out of index");
    return _matrix[row][col];
}

bool Matrix::out_of_bound(int row, int col) {
    return (row < 0 || row > _rows - 1 || col < 0 || col > _cols - 1);
}

void Matrix::scalar_product(type_elem scalar) {
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            write_value_at(i,j, read_value_at(i,j) * scalar);
        }
    }
}


/* int main(int argc, char const *argv[])
{
    Matrix m(3,3);
    m.scalar_product(5);
    return 0;
}  */