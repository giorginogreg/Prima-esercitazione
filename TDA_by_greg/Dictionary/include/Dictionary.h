//
// Created by Greg on 10/04/22.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class K_T, class V_T>
struct Pair {
    K_T _key;
    V_T _value;
};

template<class K_T, class V_T>
class Dictionary {
public:
    virtual void create() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool belongsTo(K_T) const = 0;
    virtual void put( Pair<K_T, V_T> ) = 0;
    virtual void remove(K_T) = 0;
    virtual V_T getValue(K_T) const = 0;
    virtual void updatePair(Pair<K_T, V_T> pair) = 0;

private:
};

#endif //DICTIONARY_H
