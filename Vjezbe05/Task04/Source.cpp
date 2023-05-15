#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	v.reserve(500);
	int c = 0;
	int cap = v.capacity();
	for (size_t i = 0; i < 500; i++)
	{
		v.push_back(i);
		if (v.capacity() != cap)
		{
			c++;
			cap = v.capacity();
		}
	}
	cout << c << endl;
	return 0;
}