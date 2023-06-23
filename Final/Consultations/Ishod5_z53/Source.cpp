#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

void load(ifstream& in, vector<string>& v)
{
	string name;
	while (in >> name)
	{
		v.push_back(name);
	}
}

void print(string s)
{
	cout << s << endl;
}

bool len(string l, string r)
{
	return l.length() > r.length();
}

int main()
{
	ifstream in("osobe.txt");
	if (!in)
	{
		return 1;
	}

	vector<string> v;
	load(in, v);
	in.close();

	sort(v.begin(), v.end()); //sort alphabeticaly 
	sort(v.begin(), v.end(), len); //sort by length

	for_each(v.begin(), v.end(), print);

	return 0;
}