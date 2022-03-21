#ifndef LINEARLIST_H
#define LINEARLIST_H

#pragma once

template <class T, class P, int S>
class LinearList
{
public:
    // Constructor
    virtual void initialize() = 0;
    // Distructor

    // Modifiers
    virtual void writeValueAt(int, T) = 0;
    virtual void insertNodeAfter(P, T) = 0;

    virtual void deleteNodeAt(P) = 0;

    // Observers
    virtual T readValueAt(P) = 0;
    virtual bool isEmpty() = 0;
    virtual bool isLastValue( P ) = 0;
    virtual P firstNodeList(  ) = 0;
    virtual P nextPosition(P) = 0;
    virtual P previousPosition(P) = 0;

};
#endif