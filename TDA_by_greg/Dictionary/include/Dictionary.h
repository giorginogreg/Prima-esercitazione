//
// Created by Greg on 10/04/22.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class K_T, class V_T>
class Dictionary {
    virtual void create() = 0;
    virtual bool isEmpty() = 0;
    virtual bool belongsTo(K_T) = 0;
    virtual void put(K_T, V_T) = 0;
    virtual void remove(K_T) = 0;
    virtual V_T getValue(K_T) = 0;
};

#endif //DICTIONARY_H
