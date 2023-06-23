#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

void load(ifstream& in, vector<int>& v)
{
	int n;
	while (in >> n)
	{
		v.push_back(n);
	}
}

void print(int& n)
{
	cout << n << endl;
}
void mul(int& n)
{
	n *= 3;
}

int main()
{
	ifstream in("brojevi.txt");
	if (!in)
	{
		return 1;
	}
	vector<int> v;
	load(in, v);
	in.close();
	list<int> l(v.begin(), v.end());
	for_each(l.begin(), l.end(), mul);

	for (auto it = l.begin(); it != l.end();)
	{
		if (*it % 2 == 0) 
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}

	for_each(l.begin(), l.end(), print);

	//for_each(v.begin(), v.end(), print);
	return 0;
}