#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int get_rnd(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		cout << get_rnd(150, 200) << endl;
	}

	auto begin = high_resolution_clock::now();

	auto end = high_resolution_clock::now();

	cout
		<< duration_cast<nanoseconds>(end - begin).count()
		<< "ns"
		<< endl;

	return 0;
}