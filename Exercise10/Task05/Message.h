#pragma once
#include <string>
#include <sstream>

using namespace std;

struct message
{
	string text;
	int priority;
	message(string text, int priority)
	{
		this->text = text;
		this->priority = priority;
	}
	string to_string() const
	{
		stringstream ss;
		ss << priority << "->" << text;
		ss.str();
	}
};

struct cmp
{
	bool operator()(const message& l, const message& r)
	{
		return l.priority > r.priority;
	}
};