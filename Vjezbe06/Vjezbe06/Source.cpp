#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "Water.h"

using namespace std;

template<typename T>
T convert(string& in) 
{
	stringstream c(in);
	T n;
	c >> n;
	return n;
}

void load(ifstream& in, list<Water>& l) {
	string line;
	getline(in, line);
	while (getline(in, line)) 
	{
		string temp;
		stringstream ss(line);
		
		getline(ss, temp, ',');
		int year = convert<int>(temp);

		getline(ss, temp, ',');
		double level = convert<double>(temp);
		
		l.emplace_back(year, level);
	}
}

void print(Water& w)
{
	cout << w.to_string() << endl;
}

int main() {

	ifstream dat("LakeHuron.csv");
	if (!dat) 
	{
		throw exception("File not found!");
		return 1;
	}
	list<Water> l;
	load(dat, l);
	dat.close();

	int year;
	cout << "year: ";
	cin >> year;

	l.remove_if([&year](Water& w) {
		return w.get_year() <= year;
		});

	for_each(l.begin(), l.end(), [&year](Water& w) {
		if (w.get_year() <= year) {
			cout << w.to_string() << endl;
		}
		});

	return 0;
}