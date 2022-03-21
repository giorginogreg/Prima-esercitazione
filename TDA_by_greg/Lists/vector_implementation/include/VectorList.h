#ifndef VECTORLIST_H
#define VECTORLIST_H

#include "../../include/LinearList.h"

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

    T readValueAt(position);
    bool isEmpty();
    bool isLastValue(position);
    int firstNodeList();

    position nextPosition(position);
    position previousPosition(position);

    // Getters and setters

    int getDimension() const;
    void setDimension(int dimension);

    int getElementsInside() const;
    void setElementsInside(int elementsInside);

    T *getList() const;
    void setList(T *list);

    void shiftElementsToRight(const position = 0);
    void shiftElementsToLeft(const position);

private:
    int _dimension;
    int _elements_inside;
    T *_list;

    bool outOfBound(int desired_position);

    void change_list_size( const int new_dimension);
};


#endif