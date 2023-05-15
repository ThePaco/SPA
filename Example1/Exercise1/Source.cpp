#include <iostream>
#include "Point.h"	

using namespace std;

int main()
{
	Point p;
	p.set_x(-1);
	p.set_y(2);
	cout << p.to_string() << endl;

	return 0;
}