#include "Water.h"
#include <sstream>

Water::Water(int year, double level)
{
    this->year = year;
    this->level = level;
}

int Water::get_year()
{
    return year;
}

string Water::to_string()
{
    stringstream ss;
    ss << year << ": " << level;
    return string();
}
