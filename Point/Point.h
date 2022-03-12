#ifndef POINT_H
#define POINT_H

#pragma once
#include <iostream>

class Point
{
public:
    using coord_t = float;

    Point(coord_t x, coord_t y);
    Point(const Point &p1);
    ~Point();
    Point operator+(const Point &p);
    Point operator=(const Point &p);
    friend std::ostream& operator<<(std::ostream&, const Point);

    coord_t getX() const;
    void setX(const coord_t);

    coord_t getY() const;
    void setY(const coord_t);
    
private:
    coord_t _x;
    coord_t _y;

};

#endif