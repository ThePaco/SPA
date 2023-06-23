#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

void print_asc(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<>> pq(v.begin(), v.end());
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void print_desc(vector<int>& v)
{
	priority_queue<int> pq(v.begin(), v.end());
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	srand(time(nullptr));
	vector<int> v;
	load(v, 10, 1, 100);

	int order;
	cout << "1. asc, 2. desc\n";
	cin >> order;

	switch (order) { case 1: print_asc(v); case 2: print_desc(v); }

	return 0;
}