#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

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
		out << it->first << ":" << it->second << endl;
	}
}

int main() {
	ifstream in1("yob1901.txt");
	ifstream in2("yob2001.txt");
	ofstream out("out.txt");

	if (!in1 || !in2 || !out)
	{
		cout << "404" << endl;
		return 1;
	}

	unordered_map<string, int> m;
	load(in1, m);
	load(in2, m);
	save(out, m);
	in1.close();
	in2.close();
	out.close();

	return 0;
}