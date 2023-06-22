#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "counting_sort.h"

using namespace std;

bool len_desc(string& first, string& second)
{
	return first.size() > second.size();
}

int main()
{
	ifstream dat("osobe.txt");
	if (!dat)
	{
		return -1;
	}
	vector<string> v;
	string s;
	while (getline(dat, s))
	{
		v.push_back(s);
	}
	sort(v.begin(), v.end(), len_desc);
	dat.close();

	return 0;
}