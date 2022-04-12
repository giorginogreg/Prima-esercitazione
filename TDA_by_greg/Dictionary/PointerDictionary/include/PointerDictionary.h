//
// Created by Greg on 10/04/22.
//

#ifndef POINTERDICTIONARY_H
#define POINTERDICTIONARY_H

#include "../../include/Dictionary.h"
#include "../../../include/Node.h"
#include "../../../Lists/pointer_implementation/Pointer List/include/PointerList.h"

template<class K_T, class V_T>
class PointerDictionary: public Dictionary<K_T, V_T> {
public:
    PointerDictionary();

    void create();
    virtual bool isEmpty() const;
    virtual bool belongsTo(K_T key) const;
    virtual void put( Pair<K_T, V_T> pair);
    virtual void remove(K_T t);
    virtual V_T getValue(K_T t) const;
    virtual void updatePair(Pair<K_T, V_T> pair);

    // Accessory methods
    virtual Pair<K_T, V_T> find(K_T) const;
    virtual Node<Pair<K_T, V_T>>* findNode(K_T) const;
private:
    PointerList< Pair<K_T, V_T>, 0>* p = new PointerList< Pair<K_T,V_T>, 0>();
};

#include "../src/PointerDictionary.tpp"

#endif //POINTERDICTIONARY_H
