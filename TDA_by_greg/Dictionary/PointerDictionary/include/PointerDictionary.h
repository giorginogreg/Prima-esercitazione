//
// Created by Greg on 10/04/22.
//

#ifndef POINTERDICTIONARY_H
#define POINTERDICTIONARY_H

#include "../../include/Dictionary.h"

template<class K_T, class V_T>
class PointerDictionary: public Dictionary<K_T, V_T>{
    virtual void create();
    virtual bool isEmpty();
    virtual bool belongsTo(K_T);
    virtual void put(K_T, V_T);
    virtual void remove(K_T t);
    virtual V_T getValue(K_T t);
};

#endif //POINTERDICTIONARY_H
