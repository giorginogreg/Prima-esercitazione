#ifndef VECTORLIST_H
#define VECTORLIST_H

#include "../../pointer_implementation/Linear List/LinearList.h"

#pragma once

template <class T, int S>
class VectorList: public LinearList<T, int, S>
{
public:
    typedef int position;

    VectorList();
    VectorList(const VectorList&);
    ~VectorList();

    void initialize();

    void writeValueAt(position i, T t);

    void insertNodeAfter(position, T);
    void deleteNodeAt(position);

    T readValueAt(position) const;
    bool isEmpty() const;

    bool isLastPosition(position) const;
    int firstNodeList() const;

    position nextPosition(position) const;
    position previousPosition(position) const;

    // Getters and setters

    int getDimension() const;
    void setDimension(int dimension);



    T *getList() const;
    void setList(T *list);

    void shiftElementsToRight(position = 0);
    void shiftElementsToLeft(position);

private:
    int _dimension;
    T *_list;

    void change_list_size(int new_dimension);
    bool outOfBound(int desired_position) const;
};

#include "../src/VectorList.tpp"

#endif