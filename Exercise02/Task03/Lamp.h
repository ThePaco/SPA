#pragma once
#include <string>

using namespace std;

class Lamp
{
	string model, producer;
	int number;
	double power;
public:
	Lamp();
	Lamp(const string model);
	string get_model() const;
	string get_producer() const;
	int get_number() const;
	double get_power() const;
	void set_model(const string model);
	void set_producer(const string producer);
	void set_number(const int number);
	void set_power(const double power);
	string tostring() const;
};

