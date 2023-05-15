#include "Lamp.h"
#include <sstream>

using namespace std;

Lamp::Lamp()
{
    set_model("");
    set_producer("");
    set_number(0);
    set_power(0);
}

Lamp::Lamp(const string model) : Lamp ()
{
    set_model(model);
}

string Lamp::get_model() const
{
    return model;
}

string Lamp::get_producer() const
{
    return producer;
}

int Lamp::get_number() const
{
    return number;
}

double Lamp::get_power() const
{
    return power;
}

void Lamp::set_model(const string model)
{
    this->model = model;
}

void Lamp::set_producer(const string producer)
{
    this->producer = producer;
}

void Lamp::set_number(const int number)
{
    this->number = number;
}

void Lamp::set_power(const double power)
{
    this->power = power;
}

string Lamp::tostring() const
{
    stringstream ss;
    ss << "Model: " << model << " Producer: " << producer << " Number: " << number << " Power: " << power;
    return ss.str();
}
