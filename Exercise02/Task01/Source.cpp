#include <iostream>

using namespace std;

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	if (b == 0) {
		throw exception("Can't divide by zero");
	}
	return a / b;
}

double square_root(int a) {
	
	if (a < 0) {
		throw exception("Number is negative");
	}
	return sqrt(a);
}

int main() {

	int a;
	cout << "a: ";
	cin >> a;
	int b;
	cout << "b: ";
	cin >> b;

	cout << a << "*" << b << "=" << multiply(a,b) << endl;

	try {
		cout << a << "/" << b << "=" << divide(a, b) << endl;
		cout << square_root(a) << endl;
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}	

	return 0;
}