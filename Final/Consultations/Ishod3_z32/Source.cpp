#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using  namespace std;

int gen_rnd(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void load(vector<int>& v, int length, int min, int max)
{
	for (int i = 0; i < length; i++)
	{
		v.push_back(gen_rnd(min, max));
	}
}

bool desc(int left, int right)
{
	return left > right;
}

void print_asc(vector<int>& v)
{
	make_heap(v.begin(), v.end(), desc);
	while (!v.empty())
	{
		cout << v.front() << " ";
		pop_heap(v.begin(), v.end(), desc);
		v.pop_back();
	}
}

void print_desc(vector<int>& v)
{
	make_heap(v.begin(), v.end());
	while (!v.empty())
	{
		cout << v.front() << " ";
		pop_heap(v.begin(), v.end());
		v.pop_back();
	}
}

int main()
{
	srand(time(nullptr));
	vector<int> v;
	load(v, 100, 1, 100);

	int order;
	cout << "1. asc, 2. desc\n";
	cin >> order;

	switch (order) { case 1: print_asc(v); case 2: print_desc(v); }

	return 0;
}