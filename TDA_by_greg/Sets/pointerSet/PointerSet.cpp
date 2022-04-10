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
    p.insert(3);
    p.insert(4);
    p.insert(5);

    cout << p << endl;

    p2.insert(3);
    p2.insert(1);
    p2.insert(33);
    cout << p2 << endl;

    auto* unified_set = dynamic_cast<PointerSet<int, 10>*>(p.union_op(&p2)); // Expect 1, 2, 3
    cout << *unified_set << endl;

    auto* intersected_set = dynamic_cast<PointerSet<int, 10>*>(p.intersect(&p2)); // Expect 1
    cout << *intersected_set << endl;

    auto* differenced_set = dynamic_cast<PointerSet<int, 10>*>(p.difference(&p2)); // Expect 2
    cout << *differenced_set << endl;

    return 0;
}
