#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool prime(int n){
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void print_if_prime(int& n) {
	if (prime(n)) {
		cout << n << endl;
	}
}

int main() {

	vector<int> vec;

	for_each(vec.begin(), vec.end(), print_if_prime);

	return 0;
}