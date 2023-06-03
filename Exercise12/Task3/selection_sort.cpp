#include <iostream>
#include "selection_sort.h"
using namespace std;

void selection_sort(rect data[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j].area() < data[min_index].area()) {
				min_index = j;
			}
		}

		swap(data[min_index], data[i]);
	}
}