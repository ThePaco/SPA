#pragma once
#include <string>
using namespace std;
class Person
{
	int oib;
	string fname;
	string lname;

public:
	Person(string fname, string lname);
	Person(string fname, string lname, int oib);
	void set_oib(int oib);
	string to_string();

};

