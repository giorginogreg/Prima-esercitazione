//
// Created by Greg on 10/04/22.
//

#include <iostream>
#include <string>
#include "include/PointerDictionary.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    auto* p = new PointerDictionary<int, int>();
    Pair<int, int> pair {
        ._key = 0,
        ._value = 10
    };
    p->put(pair);


    Pair<int, int> pair2 {
            ._key = 1,
            ._value = 20
    };
    p->put(pair2);

    cout << p->getValue(1) << endl; // Expect 20

    p->updatePair(Pair<int, int> { ._key = 1, ._value = 50 });

    cout << p->getValue(1)<< endl; // Expect 50
    Pair<int, int> pair3 {
            ._key = 1,
            ._value = 100
    };
    p->put(pair3);

    cout << p->getValue(1) << endl; // Expect 100

    return 0;
}
