#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void make25()
{
	ofstream out("brojevi.txt");
	if (!out) {
		return;
	}
	for (size_t i = 0; i < 25; i++)
	{
		out << i << " ";
	}
	out << endl;
	out.close();
}

void process(ifstream& in, ofstream& out, queue<int>& q)
{
	int n;
	while (in >> n)
	{
		q.push(n);
		if (q.size() == 5) 
		{
			while (!q.empty())
			{
				out << q.front() << " ";
				q.pop();
			}
		}
	}
}

int main()
{	
	//make25();
	ifstream in("brojevi.txt");
	ofstream out("results.txt");
	if (!in || !out) {
		return 1;
	}

	queue<int> q;
	process(in, out, q);
	in.close();
	out.close();
	return 0;
}