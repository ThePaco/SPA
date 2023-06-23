#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void fill(vector<int>& v)
{
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i + 1);
	}
	random_shuffle(v.begin(), v.end());
}

void save(ofstream& out, vector<int>::iterator begin, vector<int>::iterator end)
{
	for (auto it = begin; it != end; ++it)
	{
		out << *it << " ";
	}
	cout << endl;
}

bool cmp(int l, int r)
{
	return l > r;
}

bool even(int n)
{
	return n % 2 == 0
}

int main() 
{
	srand(time(nullptr));
	ofstream asc("asc.txt");
	ofstream desc("desc.txt");
	ofstream even_odd("even_odd.txt");
	if (!asc || !desc || !even_odd)
	{
		return 1;
	}
	vector<int> v;
	fill(v);
	sort(v.begin(), v.end());
	save(asc, v.begin(), v.end());	
	
	sort(v.begin(), v.end(), cmp);
	save(desc, v.begin(), v.end());

	auto it = partition(v.begin(), v.end(), even);
	save(even_odd, v.begin(), it);
	save(even_odd, it, v.end());

	asc.close();
	desc.close();
	even_odd.close();

	return 0;
}