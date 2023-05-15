#pragma once
#include <string>

using namespace std;

class Water
{
	int year;
	double level;
public:
	Water(int year, double level);
	int get_year();
	string to_string();
};

