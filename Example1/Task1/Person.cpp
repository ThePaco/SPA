#include "Person.h"
#include <sstream>

Person::Person(string fname, string lname)
{
    this->fname = fname;
    this->lname = lname;
}

Person::Person(string fname, string lname, int oib) : Person(fname, lname)
{
    set_oib(oib);
}

void Person::set_oib(int oib)
{
    this->oib = oib;
}

string Person::to_string()
{
    stringstream ss;
    ss << "Name: " << fname << " Last name: " << lname << " OIB: " << oib;
    return ss.str();
}
