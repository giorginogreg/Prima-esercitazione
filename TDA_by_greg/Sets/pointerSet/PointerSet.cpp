//
// Created by Greg on 07/04/22.
//


#include <iostream>
#include <string>
#include "include/PointerSet.h"
#include "../include/Set.h"
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    cout << "Hello world!" << endl;
    PointerSet<int, 10> p, p2;
    p.insert(1);
    p.insert(2);
    p2.insert(3);
    p2.insert(1);
    auto* unified_set = dynamic_cast<PointerSet<int, 10>*>(p.union_op(&p2)); // Expect 1, 2, 3
    auto* intersected_set = dynamic_cast<PointerSet<int, 10>*>(p.intersect(&p2)); // Expect 1

    return 0;
}
