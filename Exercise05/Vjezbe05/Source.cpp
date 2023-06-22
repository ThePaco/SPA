#include <iostream>
#include <vector>

using namespace std;

int gen_rnd(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	srand(time(nullptr));
	vector<int> v;

	v.reserve(100);

	for (size_t i = 0; i < v.capacity(); i++)
	{
		v.insert(v.begin(), gen_rnd(1, 100));
	}

	for (size_t i = 0; i < v.capacity(); i++)
	{
		cout << v.at(i) << " ";
	}

	cout << endl;

	v.resize(50);

	for (auto it = v.begin(); it != v.end(); ++it) 
	{
		cout << *it << " ";
	}

	cout << endl;	
	
	v.reserve(30);

	for (auto it = v.rbegin(); it != v.rend(); ++it) 
	{
		cout << *it << " ";
	}

	cout << endl;

	vector<int> v2(v);

	v.clear();

	v2.erase(v2.begin(), v2.begin() + 10);

	for (auto it = v2.begin(); it != v2.end();)
	{
		it = v2.erase(it);
	}

	cout << v2.capacity() << endl;
	cout << v2.size() << endl;

	return 0;
}