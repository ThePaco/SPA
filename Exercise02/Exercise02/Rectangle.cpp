#include "Rectangle.h"
#include <string>
#include <sstream>

using namespace std;

double Rectangle::get_a()
{
	return a;
}

double Rectangle::get_b()
{
	return a;
}

void Rectangle::set_a(double a)
{
	this->a = a;
}

void Rectangle::set_b(double b)
{
	this->b = b;
}

string Rectangle::tostring()
{
	stringstream ss;
	ss << "a: " << a << " b: " << b << " rectangle has area: " << area();
	return ss.str();
}

double Rectangle::area()
{
	return a*b;
}
