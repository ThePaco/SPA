#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main() {

	list<int> l = { 1,2,3,4,5,6,7,8,9,10 };
	stack<int, list<int>> s(l);

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

	queue<string> q;

	return 0;
}