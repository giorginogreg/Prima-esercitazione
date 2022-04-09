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
    virtual void writeValueAt(position, type) = 0;
    virtual void insertNodeAfter(position, type) = 0;

    virtual void deleteNodeAt(position) = 0;

    // Observers
    virtual type readValueAt(position) const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isLastPosition(position ) const = 0;
    virtual position firstNodeList( ) const = 0;
    virtual position nextPosition(position) const = 0;
    virtual position previousPosition(position) const = 0;

    //virtual position search(type);

    virtual int getElementsInside() const { return _elems_inside; }
    virtual void setElementsInside(int elementsInside) { _elems_inside = elementsInside; }
protected:
    int _elems_inside;
};
/*

template<class T, class position, int S>
position LinearList<T, position, S>::search(T v) {
    position p;
    //for(p = firstNodeList(); !isLastPosition(p) && readValueAt(p) < v; p = nextPosition(p));
    return p;
}
*/

#endif