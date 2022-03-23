//
// Created by Greg on 20/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_DERIVEDCLASS_H
#define ALGORITHM_DATA_STRUCTURES_DERIVEDCLASS_H


#include "BaseTemplate.h"

template<class T>
class DerivedClass: public BaseTemplate<T> {
public:
    BaseTemplate<T> GetValue() override {
        return BaseTemplate<T>();
    }

};


#endif //ALGORITHM_DATA_STRUCTURES_DERIVEDCLASS_H
