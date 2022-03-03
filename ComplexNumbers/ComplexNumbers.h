#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

#pragma once

class ComplexNumber
{
public:
    ComplexNumber(double first_real, double second_real);
    ComplexNumber operator +(ComplexNumber c2); // Extending sum algebra
    ComplexNumber* operator =(ComplexNumber c2); 
    // Equivalente di operator +(ComplexNumber c1, ComplexNumber c2);
    ~ComplexNumber();

private:
    double first_real;
    double second_real;
};

#endif