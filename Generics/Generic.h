#ifndef GENERIC_H
#define GENERIC_H

#pragma once

// Also with the generic type, i can declare a generic parameter like a function param.
template <typename T, int exprParam>
class Generic
{
public:
    Generic(): T (T[exprParam]) {};
    ~Generic();
    void print();
    void print<int>(); // Specialization of print method for int type in input
private:
    T val;
};

#endif