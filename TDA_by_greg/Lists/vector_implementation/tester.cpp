#include <iostream>
#include "./include/VectorList.h"
#include "src/VectorList.cpp"

int main()
{
    const int size = 0;
    VectorList<int, size> vectorList;
    vectorList.insertNodeAfter(0, 1);
    vectorList.deleteNodeAt(0);
    return 0;
}
