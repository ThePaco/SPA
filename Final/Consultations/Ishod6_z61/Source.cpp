#include <iostream>
#include <unordered_set>

using namespace std;

int main() 
{
	unordered_multiset<int> ms;
	bool again;
	do
	{
		for (int i = 1; i <= 22; i++) 
		{
			ms.insert(i);
		}

		for (int i = 0; i < ms.bucket_count(); i++)
		{
			cout << i << " - > " << ms.bucket_size(i) << endl;
		}

		cout << "size: " << ms.size() << endl;
		cout << "nr. of buckets: " << ms.bucket_count() << endl;

		cout << "again(0/1)?";
		cin >> again;
	} while (again);
	return 0;
}