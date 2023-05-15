#include "Point.h"
#include <sstream>

Point::Point()
{
    set_x(0);
    set_y(0);
}

Point::Point(int x, int y)
{
    set_x(x);
    set_y(y);
}

int Point::get_x()
{
    return x;
}

int Point::get_y()
{
    return y;
}

void Point::set_x(int x)
{
    if (x < 0)
    {
        x = 0;
    }
    this->x = x;
}

void Point::set_y(int y)
{
    if (y < 0)
    {
        y = 0;
    }
    this->y = y;
}


string Point::to_string()
{
    stringstream ss;
    ss << "P(" << x << ", " << y << ")";
    return ss.str();
}

double Point::distance()
{
    return sqrt(pow(x,2)+pow(y,2));
}
