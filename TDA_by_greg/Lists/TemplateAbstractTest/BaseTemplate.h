//
// Created by Greg on 20/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_BASETEMPLATE_H
#define ALGORITHM_DATA_STRUCTURES_BASETEMPLATE_H


#include <string>

template<class T>
class BaseTemplate {
public:
    BaseTemplate() = default;

    virtual BaseTemplate<T> GetValue() = 0; // a pure virtual method
};


#endif //ALGORITHM_DATA_STRUCTURES_BASETEMPLATE_H
