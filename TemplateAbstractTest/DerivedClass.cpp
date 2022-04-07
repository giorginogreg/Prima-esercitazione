//
// Created by Greg on 20/03/22.
//

#include "DerivedClass.h"

template <>
BaseTemplate<int> DerivedClass<int>::GetValue() {
    return *this;
}

int main() {
    new DerivedClass<int>();
}