#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void load(ifstream& in, map<char, int>& m)
{
	string line;
	while (getline(in, line))
	{
		for (int i = 0; i < line.length(); ++i)
		{
			char c = line[i];
			m[c]++;
		}
	}
}
int main()
{
	ifstream in("Sifre_drzava.csv");

	if (!in)
	{
		return 1;
	}
	map<char, int> m;
	load(in, m);
	in.close();

	for(auto it = m.begin(); it != m.end(); ++it)
	{
		cout << "'" << it->first << "'" << " appears " << it->second << " times" << endl;
	}

	return 0;
}