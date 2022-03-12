#include "Point.h"

#include "stdio.h"
#include <iostream>
// This constructor copies the references of the object (addresses).
Point::Point(coord_t x, coord_t y)
{
    _x = x;
    _y = y;
}

Point::Point(const Point &p1) noexcept
{
    _x = p1._x;
    _y = p1._y;
}

Point::~Point()
{
}

Point::coord_t Point::getX() const
{
    return _x;
}

void Point::setX(const Point::coord_t x)
{
    _x = x;
}

Point::coord_t Point::getY() const
{
    return _y;
}

void Point::setY(const Point::coord_t y)
{
    _y = y;
}

Point Point::operator+(const Point &p)
{
    return Point(p.getX() + _x, p.getY() + getY());
}

Point* Point::operator=(const Point &p)
{   
    this->setX(p.getX());
    this->setY(p.getY());
    return this;
}

std::ostream &operator<<(std::ostream &o, const Point p)
{
    o << "X coord: " << p.getX() << std::endl;
    o << "Y coord: " << p.getY() << std::endl;
    return o;
}
