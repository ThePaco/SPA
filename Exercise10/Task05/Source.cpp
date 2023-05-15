#include <iostream>
#include <queue>
#include "Message.h"

using namespace std;

int main()
{
	priority_queue<message, vector<message>, cmp> pq;
	pq.emplace(message("javi se", 3));
	pq.emplace(message("uci", 5));
	pq.emplace(message("rad", 6));
	pq.emplace(message("promet", 2));
	pq.emplace(message("odmor", 1));

	while (!pq.empty())
	{
		cout << pq.top().to_string() << endl;
		pq.pop();
	}
	return 0;
}