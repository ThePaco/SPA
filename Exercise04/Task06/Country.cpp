#include "Country.h"

Country::Country(string name)
{
	this->name = name;
}

void Country::add_scientists(int n)
{
	scientists.push_back(n);
}

double Country::average()
{
	if (scientists.size() == 0)
	{
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < scientists.size(); i++)
	{
		sum += scientists[i];
	}
	return sum;
}

string Country::get_name()
{
	return name;
}
