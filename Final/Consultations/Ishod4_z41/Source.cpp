#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void load(ifstream& in, map<string, string>& m)
{
	string line, temp;
	getline(in, temp);
	while (getline(in, line))
	{
		//value; key --> Afghanistan;AFG
		stringstream ss(line);
		string key, value;
		getline(ss, value, ';');
		ss >> key;
		m[key] = value;
	}
}

void search(map<string, string>& m, string key)
{
	auto it = m.find(key);
	if(it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
	}
	else
	{
		cout << "Item does not exist" << endl;
	}
	
}

int main()
{
	ifstream in("Sifre_drzava.csv");

	if(!in)
	{
		return 1;
	}
	map<string, string> m;
	load(in, m);
	in.close();

	bool again;
	do
	{
		string key;
		cout << "key:";
		cin >> key;
		search(m, key);
		cout << "again(1/0)?";
		cin >> again;
	}
	while (again);
	return 0;
}