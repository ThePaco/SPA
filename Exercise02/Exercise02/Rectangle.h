#pragma once
#include <string>

using namespace std;

class Rectangle
{
	double a,b;
public:
	double get_a();
	double get_b();
	void set_a(double a);
	void set_b(double b);
	string tostring();
	double area();
};

