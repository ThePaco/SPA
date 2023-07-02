#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void load(ifstream& in, map<int, vector<string>>& m)
{
	string line;
	while (getline(in, line))
	{
		stringstream ss(line);
		int key;
		string key_s,value;
		getline(ss, key_s, '\t');
		ss >> value;
		key = stoi(key_s);
		m[key].push_back(value);
	}
}

void search(map<int, vector<string>>& m, string key)
{
	//auto it = m.at(key);
	if (it != m.end())
	{
		cout << "Key: " << it->first << " Values: ";
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}

}

int main()
{
	map<int, vector<string>> m;
	
	ifstream in("Racuni.csv");
	if (!in) { return 1; };
	load(in, m);
 	in.close();


	//ispis svih računa
	//for (auto it = m.begin(); it != m.end(); ++it)
	//{
	//	cout << "Key: " << it->first << " Values: ";
	//	for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
	//	{
	//		cout << *it2 << " ";
	//	}
	//	cout << endl;
	//}

	string key;
	cout << "key:";
	cin >> key;
	search(m, key);

	return 0;
}