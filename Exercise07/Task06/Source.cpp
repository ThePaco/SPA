#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

template<typename T>
T convert(string& s)
{
	stringstream c(s);
	T n;
	c >> n;
	return n;
}

int calculate(string& exp)
{
	stack<int> s;
	stringstream ss(exp);
	string temp;

	while (ss >> temp)
	{
		if (temp == "+" || temp == "*" || temp == "-" || temp == "/")
		{
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			switch (temp[0])
			{
			case '+':
				s.push(a + b);
				break;
			case '*':
				s.push(a * b);
				break;
			case '-':
				s.push(a - b);
				break;
			case '/':
				s.push(a / b);
				break;
			}
		}
		else
		{
			int n = convert<int>(temp);
			s.push(n);
		}
	}
	return s.top();
}

int main()
{
	string exp = "4 2 5 * + 1 3 2 * + / ";
	cout << calculate(exp);
	return 0;
}