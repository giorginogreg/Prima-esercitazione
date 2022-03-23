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
    bool isLastPosition(position);
    int firstNodeList();

    position nextPosition(position);
    position previousPosition(position);

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


#endif