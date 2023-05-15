#include <iostream>
#include "Lamp.h"

using namespace std;

int main() {
	Lamp l;
	l.set_model("Korejska");
	l.set_producer("Samsung");
	l.set_number(100);
	l.set_power(25.5);
	cout << l.tostring() << endl;
	return 0;
}