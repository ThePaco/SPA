#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	bool again;
	int current = 1;
	int limit = 20;
	unordered_set<int> s;
	do
	{
		for (int i = current; i <= limit; i++)
		{
			s.insert(i);
		}
		limit += 20;
		for (auto i = 0; i < s.bucket_count(); i++)
		{
			cout << i << " : " << s.bucket_size(i) << endl;
		}

		cout << "size: " << s.size() << endl;
		cout << "buckets: " << s.bucket_count() << endl;
		cout << "again: ";
		cin >> again;
	} while (again);
}