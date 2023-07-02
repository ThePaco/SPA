#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	vector<int> v;
	set<int> s;
	multiset<int> ms;
	map<int, int> m;
	multimap<int, int> mm;

	for (int i = 1; i <= 100000; i++)
	{
		v.push_back(i);
		s.insert(i);
		ms.insert(i);
		m.insert(pair<int, int>(i, i));
		mm.insert(pair<int, int>(i, i));
	}

	auto t1 = high_resolution_clock::now();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (*it == 100000) break;
	}
	auto t2 = high_resolution_clock::now();
	cout << "time to find in vector: " << duration_cast<microseconds>(t2 - t1).count() << "ms" << endl;

	t1 = high_resolution_clock::now();
	s.find(100000);
	t2 = high_resolution_clock::now();
	cout << "time to find in set: " << duration_cast<microseconds>(t2 - t1).count() << "ms" << endl;	
	
	t1 = high_resolution_clock::now();
	ms.find(100000);
	t2 = high_resolution_clock::now();
	cout << "time to find in multiset: " << duration_cast<microseconds>(t2 - t1).count() << "ms" << endl;	
	
	t1 = high_resolution_clock::now();
	m.find(100000);
	t2 = high_resolution_clock::now();
	cout << "time to find in map: " << duration_cast<microseconds>(t2 - t1).count() << "ms" << endl;

	t1 = high_resolution_clock::now();
	mm.find(100000);
	t2 = high_resolution_clock::now();
	cout << "time to find in multimap: " << duration_cast<microseconds>(t2 - t1).count() << "ms" << endl;
}