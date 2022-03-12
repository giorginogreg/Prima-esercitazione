#include "Matrix.h"

int main(int argc, char const *argv[])
{  
    int rows = 1;
    int cols = 3;
    Matrix m(rows, cols);
    m.write_value_at(0, 0, 2);
    m.write_value_at(0, 1, -1);
    m.write_value_at(0, 2, 5);
   
    m.print_matrix();
    Matrix transposed(cols, rows);
    transposed.transpose(m);
    transposed.print_matrix();
    return 0;
}  