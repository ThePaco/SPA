#include "Table.h"

int Table::h(int key)
{
	return key & M;
}

Table::Table(unsigned n)
{
	array = new list<Entry>[M];
}

void Table::insert(int key, unsigned long long value)
{
	int bucket = h(key);
	array[bucket].emplace_back(key, value);
}

unsigned long long Table::search(int key)
{
	int bucket = h(key);
	list<Entry> l = array[bucket];
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		if (it->key == key)
		{
			return it->value;
		}
	}
	return 0;
}

Table::~Table()
{
	delete[] array;
}
