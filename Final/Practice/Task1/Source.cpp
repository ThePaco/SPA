#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()

{
	set<int> s;
	for (int i = 1; i <= 10; i++)
	{
		s.insert(i);
	}
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	s.erase(7);
	s.insert(17);
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	multiset<int> ms;
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		ms.insert(*it);
		ms.insert(*it);
	}
	for (auto it = ms.begin(); it != ms.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	map<int, int> m;
	for (auto it = ms.begin(); it != ms.end(); ++it)
	{
		m.insert(pair<int, int>(*it, (*it)*(*it)));
	}
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << " (" << it->second << ") ";
	}
	cout << endl;

	multimap<int, int> mm;
	for (auto it = m.rbegin(); it != m.rend(); ++it)
	{
		int key = it->first;
		int value = it->second;
		mm.insert(pair<int, int>(key, value));
	}
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " (" << it->second << ") ";
	}
	return 0;
}