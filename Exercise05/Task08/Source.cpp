#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "IPadress.h"

using namespace std;

int convert(string& s)
{
	istringstream c(s);
	int n;
	c >> n;
	return n;
}

int count_occ(char c, vector<IPadress>& v)
{
	int counter = 0;

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (it->which() == c) {
			counter++;
		}
	}

	return counter;
}

void load(ifstream& in, vector<IPadress>& v)
{
	string line;
	while (getline(in, line))
	{
		stringstream ss(line);
		string temp;

		getline(ss, temp, '.');
		int a = convert(temp);		
		
		getline(ss, temp, '.');
		int b = convert(temp);		
		
		getline(ss, temp, '.');
		int c = convert(temp);		
		
		getline(ss, temp);
		int d = convert(temp);

		v.emplace_back(a, b, c, d);
	}
}

void print(char c, int n)
{
	cout << "Klasa " << c << ": ";
	for (size_t i = 0; i < n; i++)
	{
		cout << "#";
	}
	cout << " (" << n << ")" << endl;

}
int main()
{
	ifstream in("ip_adrese.txt");
	if (!in) {
		cout << "no can do" << endl;
		return 1;
	}
	vector<IPadress> v;
	load(in, v);
	in.close();

	char classes[] = { 'A', 'B', 'C', 'D', 'E' };
	int length = sizeof(classes) / sizeof(char);
	for (size_t i = 0; i < length; i++)
	{
		print(classes[i], count_occ(classes[i], v));
	}

	return 0;
}