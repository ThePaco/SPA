#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

void load(ifstream& in, stack<string>& s)

{
	string line;
	while (getline(in, line))
	{
		s.push(line);
	}
}

void save(ofstream& out, stack<string>& s)
{
	while (!s.empty())
	{
		out << s.top() << endl;
		s.pop();
	}
}

int main()
{
	ifstream in("Tekst.txt");
	ofstream out("Output.txt");
	if (!in || !out)
	{
		cout << "File not found" << endl;
		return 1;
	}
	stack<string> s;
	load(in, s);
	save(out, s);
	in.close();
	out.close();

	return 0;
}