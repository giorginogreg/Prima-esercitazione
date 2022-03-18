#include "Matrix.h"
#include <string>
#include <iostream>
using namespace std;

Matrix::Matrix(const int rows, const int cols)
{
    setRows(rows);
    setCols(cols);

    _matrix = new type_elem *[rows];
    for (int i = 0; i < rows; i++)
    {
        _matrix[i] = new type_elem[cols];
        for (int j = 0; j < cols; j++)
        {
            _matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const int rows, const int cols, const type_elem initial_value)
{
    setRows(rows);
    setCols(cols);

    _matrix = new type_elem *[rows];
    for (int i = 0; i < rows; i++)
    {
        _matrix[i] = new type_elem[cols];
        for (int j = 0; j < cols; j++)
        {
            write_value_at(i, j, initial_value);
        }
    }
}

Matrix::~Matrix()
{
    /*  for (int i = 0; i < _cols; i++)
     {
         delete[] _matrix[i];
     }
     delete[] _matrix; */
}

void Matrix::write_value_at(int const row, const int col, const type_elem val)
{
    if (Matrix::out_of_bound(row, col))
        throw std::string("Error: out of index");

    _matrix[row][col] = val;
}

Matrix::type_elem Matrix::read_value_at(int const row, int const col) const
{
    if (Matrix::out_of_bound(row, col))
        throw std::string("Error: out of index");
    return _matrix[row][col];
}

bool Matrix::out_of_bound(int const row, int const col) const
{
    return (row < 0 || row > _rows - 1 || col < 0 || col > _cols - 1);
}

bool Matrix::is_multiplication_valid(const Matrix &m) const
{
    return (this->rows() == m.cols());
}

void Matrix::scalar_product(type_elem const scalar)
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            write_value_at(i, j, read_value_at(i, j) * scalar);
        }
    }
}

void Matrix::transpose(const Matrix &m)
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            write_value_at(i, j, m.read_value_at(j, i));
        }
    }
}

void Matrix::print_matrix()
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            cout << read_value_at(i, j) << " ";
        }

        // Newline for new row
        cout << endl;
    }
    cout << "-------------" << endl;
}

Matrix Matrix::operator*(const Matrix &m)
{
    if (!this->is_multiplication_valid(m))
        throw string("No. cols differs from no. rows of other matrix.");

    Matrix m_r(this->rows(), m.cols());

    for (int cols_second_m = 0; cols_second_m < m.cols(); cols_second_m++)
    {
        for (int i = 0; i < _rows; i++)
        {
            type_elem sum = 0;
            for (int j = 0; j < cols(); j++)
            {
                type_elem first_matrix_val = read_value_at(i, j);
                type_elem second_matrix_val = m.read_value_at(j, cols_second_m);
                sum += first_matrix_val * second_matrix_val;
            }
            m_r.write_value_at(i, cols_second_m, sum);
        }
    }

    return m_r;
}

// Copy constructor
Matrix::Matrix(const Matrix &m)
    : _rows(m.rows()),
      _cols(m.cols())
{
    _matrix = new type_elem *[m.rows()];
    for (int i = 0; i < m.rows(); i++)
    {
        _matrix[i] = new type_elem[m.cols()];
        for (int j = 0; j < m.cols(); j++)
        {
            write_value_at(i,j, m.read_value_at(i,j));
        }
    }
    
}
