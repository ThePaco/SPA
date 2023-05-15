#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

void input(stack<string>& s)
{
	string line;
	string cmd;
	string arg;
	do {
		cout << "command:";
		getline(cin, line);
		stringstream ss(line);
		ss >> cmd;
		ss >> arg;
		if (cmd == "ADD")
		{
			s.push(arg);
		}
		else if (cmd == "UNDO" && !s.empty())
		{
			s.pop();
		}
	} while (cmd != "EXIT");
}

void output(stack<string>& s)
{
	stack<string> output;
	while (!s.empty())
	{
		output.push(s.top());
		s.pop();
	}
	while (!output.empty())
	{
		cout << output.top() << " ";
		output.pop();
	}
}

int main()
{
	stack<string> s;
	input(s);
	output(s);
	return 0;
}