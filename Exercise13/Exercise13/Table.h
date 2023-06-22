#pragma once
#include <list>

using namespace std;

struct Entry
{
	int key;
	unsigned long long value;
	Entry(int key, unsigned long long value)
	{
		this->key = key;
		this->value = value;
	}
};

class Table
{
private:
	list<Entry>* array;
	int h(int key);
	const int M = 100003;

public:
	Table(unsigned n);
	void insert(int key, unsigned long long value);
	unsigned long long search(int key);
	~Table();
};

