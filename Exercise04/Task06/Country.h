#pragma once
#include <string>
#include <vector>
using namespace std;
class Country
{
	string name;
	vector<int> scientists;

public:
	Country(string name);
	void add_scientists(int n);
	double average();
	string get_name();
};

