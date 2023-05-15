#include <iostream>
#include <chrono>
#include <ctime>
#include "funkcije_za_sortiranje.h"


using namespace std;
using namespace std::chrono;

int generate_rnd(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int* prepare(int length) {
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = generate_rnd(1, 1000);
	}
	return arr;
}

int* copy_array(int* orig, int length) {
	int* arr = new int[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = orig[i];
	}
	return arr;
}

int main() {
	srand(time(nullptr));
	int n = 20000;
	int* arr = prepare(n);
	int* arr_copy = copy_array(arr, n);

	auto begin = high_resolution_clock::now();
	quick_sort(arr, n);
	auto end = high_resolution_clock::now();
	cout <<
		duration_cast<nanoseconds>(end - begin).count()
		<< " ns" 
		<< endl;

	begin = high_resolution_clock::now();
	bubble_sort(arr_copy, n);
	end = high_resolution_clock::now();
	cout <<
		duration_cast<nanoseconds>(end - begin).count()
		<< " ns"
		<< endl;

	delete[] arr;
	delete[] arr_copy;
	return 0;
}