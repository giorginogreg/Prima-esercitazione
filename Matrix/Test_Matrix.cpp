#include "Matrix.h"

int main(int argc, char const *argv[])
{  
    int rows = 2;
    int cols = 3;
    Matrix m(rows, cols);
    m.write_value_at(0, 0, 1);
    m.write_value_at(0, 1, 0);
    m.write_value_at(0, 2, 2);
    
    m.write_value_at(1, 0, 0);
    m.write_value_at(1, 1, 3);
    m.write_value_at(1, 2, -1);
  
    m.print_matrix();

    Matrix m2(cols, rows);
    m2.write_value_at(0, 0, 4);
    m2.write_value_at(0, 1, 1);
    
    m2.write_value_at(1, 0, -2);
    m2.write_value_at(1, 1, 2);
    
    m2.write_value_at(2, 0, 0);
    m2.write_value_at(2, 1, 3);
    
    m2.print_matrix();

    Matrix multiplied(rows, rows);
    multiplied = m * m2;
    
    multiplied.print_matrix();
    return 0;
}