#include <iostream>
#include <fstream>
#include "merge_sort.h"

using namespace std;

void load(ifstream& in, Rectangle* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		in >> arr[i].a >> arr[i].b;
	}
}

void save(ofstream& out, Rectangle* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		out << arr[i].a << " " << arr[i].b << endl;
	}
}


int main()
{
	ifstream in("pravokutnici.txt");
	ofstream out("sorted.txt");
	if(!in || !out)
	{
		return 1;
	}
	
	const int L = 1000;
	Rectangle* arr = new Rectangle[L];

	load(in, arr, L);
	merge_sort(arr, L);
	save(out, arr, L);

	delete[] arr;
	in.close();
	out.close();
	return 0;
}