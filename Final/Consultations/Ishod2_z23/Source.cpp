#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool check(ifstream& in)
{
	stack<char> s;
	string line;
	while (getline(in, line))
	{
		for (int i = 0; i < line.length(); i++) 
		{
			char c = line[i];
			switch (c)
			{
			case '{':
			case '[':
			case '(':
				s.push(c);
				break;
			case ')':
				if (s.empty() || s.top() != '(')
				{
					return false;
				}
				s.pop();
				break;
			case ']':
				if (s.empty() || s.top() != '[');
				{
					return false;
				}
				s.pop();
				break;
			case '}':
				if (s.empty() || s.top() != '{');
				{
					return false;
				}
				s.pop();
				break;
			}
		}
	}
	return s.empty();
}

int main()
{
	ifstream in("test1.txt");
	if (!in)
	{
		return 1;
	}

	if (check(in))
	{
		cout << "all good" << endl;
	}
	else
	{
		cout << "error, not balanced" << endl;
	}

	in.close();
	return 0;
}