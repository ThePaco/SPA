#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "Table.h"

using namespace std;
using namespace std::chrono;

void load(vector<int>& v, int length)
{
	for (int i = 1; i <= length; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

void fill(vector<int>& v, int length, Table& t)
{
	for (int i = 1; i < length; i++)
	{
		int key = v[i];
		unsigned long long value = key * key;
		t.insert(key, value);
	}
}

void search(Table& t, int key)
{
	auto t1 = high_resolution_clock::now();
	auto value = t.search(key);
	auto t2 = high_resolution_clock::now();
	cout
		<< duration_cast<nanoseconds>(t2 - t1).count()
		<< "ns \n";
	cout << value;
}

void main() 
{
	srand(time(nullptr));
	vector<int> v;
	const int L = 1000000;
	load(v, L);

	Table t(L + 1);
	fill(v, L, t);

	search(t, 5);
}