#ifndef LINEARLIST_H
#define LINEARLIST_H

#pragma once

template <class T, class P, int S>
class LinearList
{
public:

    typedef T type;
    typedef P position;
    // Constructor
    virtual void initialize() = 0;
    // Distructor

    // Modifiers
    virtual void writeValueAt(position , type) = 0;
    virtual void insertNodeAfter(position, type) = 0;

    virtual void deleteNodeAt(position) = 0;

    // Observers
    virtual type readValueAt(position) = 0;
    virtual bool isEmpty() = 0;
    virtual bool isLastValue( position ) = 0;
    virtual position firstNodeList(  ) = 0;
    virtual position nextPosition(position) = 0;
    virtual position previousPosition(position) = 0;

    virtual position search(type);

};

template<class T, class position, int S>
position LinearList<T, position, S>::search(T v) {
    position p;
    //for(p = firstNodeList(); !isLastValue(p) && readValueAt(p) < v; p = nextPosition(p));
    return p;
}

#endif