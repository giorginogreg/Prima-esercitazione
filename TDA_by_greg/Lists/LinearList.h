#ifndef LINEARLIST_H
#define LINEARLIST_H

#pragma once

template <class T, class P, int S>
class LinearList
{
public:
    // Constructor
    virtual LinearList() = 0;
    virtual void create() = 0;
    // Distructor
    virtual ~LinearList() = 0;

    // Modifiers
    virtual LinearList<T,S> writeValueAt(LinearList<T,S>, P pos, T) = 0;
    virtual LinearList<T,S> insertNodeAfter(LinearList<T,S>, P pos, T) = 0;

    virtual LinearList<T,S> deleteNodeAt(LinearList<T,S>, P pos) = 0;

    // Observers
    virtual T readValueAt(LinearList<T,S>, P pos) = 0;
    virtual bool isEmpty(LinearList<T,S>) = 0;
    virtual bool isLastValue( LinearList<T,S>, P ) = 0;
    virtual P firstNodeList( LinearList<T,S> ) = 0;
    virtual P nextValue( LinearList<T,S>, P ) = 0;
    virtual P prevValue( LinearList<T,S>, P ) = 0;

private:

};

#endif