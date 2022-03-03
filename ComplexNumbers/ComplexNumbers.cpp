#include <stdio.h> 
#include "ComplexNumbers.h"

ComplexNumber::ComplexNumber(double first_real, double second_real)
{
    this->first_real = first_real;
    this->second_real = second_real;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber c)
{
    ComplexNumber c3(0,0);
    
    c3.first_real = this->first_real + c.first_real;
    c3.second_real = this->second_real + c.second_real;
    return c3;
}

ComplexNumber* ComplexNumber::operator=(ComplexNumber c)
{
    this->first_real = c.first_real;
    this->second_real = c.second_real;  
    return this;  
}

ComplexNumber::~ComplexNumber()
{

}

int main(int argc, char const *argv[])
{

    ComplexNumber c1(1, 2);
    ComplexNumber c2(32, 21);

    ComplexNumber c3(0,0);
    c3 = c1 + c2;
    return 0;
}