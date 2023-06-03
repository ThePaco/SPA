#include <iostream>
#include <fstream>
#include <chrono>
#include <functional>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"

using namespace std;

void load(ifstream& in, int* orig, int* copy, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		in >> orig[i];
		copy[i] = orig[i];
	}
}

void copy_arr(int* orig, int* copy, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		copy[i] = orig[i];
	}
}

void sort(int* copy, int lenght, string text, function<void(int*, int)> f)
{
	auto begin = chrono::high_resolution_clock::now();
	f(copy, lenght);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< text
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms"
		<< endl;
}

int main() {

	ifstream in("puno_brojeva3.txt");
	if (!in) 
	{
		cout << "File not found!" << endl;
		return 1;
	}
	
	const int L = 20000;
	int* orig = new int[L];
	int* copy = new int[L];
	load(in, orig, copy, L);
	in.close();

	sort(copy, L, "bubble: ", bubble_sort);

	copy_arr(orig, copy, L);
	sort(copy, L, "selection: ", selection_sort);

	copy_arr(orig, copy, L);
	sort(copy, L, "insertion: ", insertion_sort);

	copy_arr(orig, copy, L);
	sort(copy, L, "shell: ", shell_sort);

	copy_arr(orig, copy, L);
	sort(copy, L, "merge: ", merge_sort);

	delete[] orig;
	delete[] copy;

	return 0;
}