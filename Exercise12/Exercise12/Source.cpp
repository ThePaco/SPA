#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int>& v)
{
	for (auto& n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}

bool sorted(vector<int>& v) 
{
	for (size_t i = 0; i < v.size()-1; i++)
	{
		if (v[i] > v[i + 1]) {
			return false;
		}
	}
}

int main() {
	
	vector<int> v{ 2, 1, 4, 3, 10, 8, 9, 6, 7, 5 };

	while (next_permutation(v.begin(), v.end()));

	print(v);

	return 0;
}