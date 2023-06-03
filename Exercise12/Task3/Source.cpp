#include <iostream>
#include <fstream>
#include "merge_sort.h"
#include "selection_sort.h"

using namespace std;

void load(ifstream& in, rect* arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		in >> arr[i].a >> arr[i].b;
	}
}

void save(ofstream& out, rect* arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		out << arr[i].area() << endl;
	}
}


int main() 
{
	ifstream in("pravokutnici.txt");
	ofstream out("output.txt");
	if (!in)
	{
		cout << "File not found!" << endl;
		return 1;
	}
	const int L = 1000;
	rect* arr = new rect[L];
	load(in, arr, L);
	selection_sort(arr, L);
	save(out, arr, L);
	
	in.close();
	out.close();
	return 0;
}