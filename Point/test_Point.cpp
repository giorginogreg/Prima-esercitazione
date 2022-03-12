#include "Point.h"
#include <stdio.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    Point p = Point(5,1);

    float x1 = 10.50;
    float y1 = 50.17;
    
    Point p2 = Point(x1, y1);

    // Expecting now that if i change the values of x1 and y1, also p2 will change his values.
    x1 = 204.10;
    y1 = 104.22;

    Point p3 = p + p2;

    std::cout << p3 << std::endl;
    return 0;
}
