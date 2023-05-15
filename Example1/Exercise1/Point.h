#pragma once
#include <string>

using namespace std;

class Point
{
	int x, y;

public:

	Point();
	Point(int x, int y);
	int get_x();
	int get_y();
	void set_x(int x);
	void set_y(int y);
	string to_string();
	double distance();

};

