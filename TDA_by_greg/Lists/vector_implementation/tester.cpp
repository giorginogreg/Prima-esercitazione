#include <iostream>
#include "./include/VectorList.h"
#include "src/VectorList.cpp"

int main(int argc, char const *argv[])
{
    const int size = 0;
    VectorList<int, size> vectorList;
    vectorList.insertNodeAfter(0, 1);
    vectorList.deleteNodeAt(0);
    return 0;
}
