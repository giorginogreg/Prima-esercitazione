//
// Created by Greg on 10/04/22.
//

#include "../include/PointerDictionary.h"

template<class K_T, class V_T>
PointerDictionary<K_T, V_T>::PointerDictionary(int maxElemsInside) {
    p = new PointerList< Pair<K_T,V_T>>(10);
    create();
}

template<class K_T, class V_T>
void PointerDictionary<K_T, V_T>::create() {
    p->setElementsInside(0);

    // Post conds: D = { }
}

template<class K_T, class V_T>
bool PointerDictionary<K_T, V_T>::isEmpty() const {
    return p->isEmpty();
}

template<class K_T, class V_T>
bool PointerDictionary<K_T, V_T>::belongsTo(K_T key) const {
    auto iterator = p->getHead();
    if(!isEmpty()) {
        do {
            iterator = iterator->getNextPos();
            Pair<K_T, V_T> elem = iterator->getElem();
            if(elem._key == key)
                return true;
        } while (!p->isLastPosition(iterator));
    }
    return false;
}

template<class K_T, class V_T>
void PointerDictionary<K_T, V_T>::put( Pair<K_T, V_T> pair) {
    if(!belongsTo(pair._key))
        p->insertNodeAfter(p->getHead(), pair);
    else
        updatePair(pair);
}

template<class K_T, class V_T>
void PointerDictionary<K_T, V_T>::remove(const K_T t) {
    auto _pos = findNode(t);
    p->deleteNodeAt(_pos);
}

template<class K_T, class V_T>
V_T PointerDictionary<K_T, V_T>::getValue(const K_T t) const {
    auto _pos = find(t);
    return _pos._value;
}

template<class K_T, class V_T>
void PointerDictionary<K_T, V_T>::updatePair(const Pair<K_T, V_T> pair) {
    auto node = findNode(pair._key);
    Pair<K_T, V_T> elem = node->getElem();
    elem._value = pair._value;
    node->setElem(elem);
}

template<class K_T, class V_T>
Pair<K_T, V_T> PointerDictionary<K_T, V_T>::find(K_T key ) const {
    // Pre-conds: The element exists already in the dictionary
    auto iterator = p->getHead();
    do {
        iterator = iterator->getNextPos();
        Pair<K_T, V_T> elem = iterator->getElem();
        if(elem._key == key)
            return elem;
    } while (!p->isLastPosition(iterator));

}

template<class K_T, class V_T>
Node<Pair<K_T, V_T>>* PointerDictionary<K_T, V_T>::findNode(K_T key) const {
    // Pre-conds: The element exists already in the dictionary
    auto iterator = p->firstNodeList();
    while (!p->isLastPosition(iterator)) {
        Pair<K_T, V_T> elem = iterator->getElem();
        if(elem._key == key)
            return iterator;
        iterator = iterator->getNextPos();
    }
}
