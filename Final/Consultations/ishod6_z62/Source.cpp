#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void load(ifstream& in, unordered_map<string, int>& m)
{
	string line;
	while (getline(in, line))
	{
		stringstream ss(line);
		string key, temp;
		int value;
		getline(ss, key, ',');
		getline(ss, temp, ',');
		ss >> value;
		m[key] += value;
	}
}

void save(ofstream& out, unordered_map<string, int>& m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		out << it->first << " - > " << it->second << endl;
	}
}

int main()
{
	ifstream in("yob1891.txt");
	ofstream out("report.txt");
	if (!in)
	{
		return 1;
	}
	unordered_map<string, int> m;
	load(in, m);
	save(out, m);
	in.close();
	out.close();
	return 0;
}
