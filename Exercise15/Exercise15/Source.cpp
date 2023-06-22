#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void fill(unordered_map<int, string>& m) {
	m.insert(pair<int, string>(1, "Kol"));
	m.insert({ 3, "Mol" });
	m.insert({ {4, "Foo"},{5, "Bar"} });
	m.emplace(2, "Zec");
	m[6] = "Temp";
}

void search(unordered_map<int, string>& m) {
	int key;
	cout << "key: ";
	cin >> key;
	auto it = m.find(key);
	if (it != m.end())
	{
		cout << it->first << " : " << it->second << endl;
	}
	else
	{
		cout << "Ne postoji" << endl;
	}
}

int main()
{
	unordered_map<int, string> m;
	fill(m);
	search(m);

	unordered_multimap<int, string> mm;
	for (auto it = m.begin(); it != m.end() ; ++it)
	{
		if (it->first % 2 != 0) {
			mm.insert(*it);
		}
	}

	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	unordered_set<string> s;
	for (auto it = mm.begin(); it != mm.end(); ++it)
	{
		if (it->second.length()>3)
		{
			s.insert(it->second);
		}
	}
	s.erase(s.begin());
	unordered_multiset<string> ms;

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		ms.insert(*it);
	}

	for (auto it = ms.begin(); it != ms.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}