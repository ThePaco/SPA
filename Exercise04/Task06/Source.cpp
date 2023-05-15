#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	
	ifstream in("Broj_znanstvenika_na_milijun_stanovnika.csv");
	if (!in) {
		cout << "404" << endl;
		return 1;
	}

	//Zadatak 5
	string line;
	getline(in, line);
	while (getline(in,line))
	{
		stringstream ss(line);
		string name;
		getline(ss, name, ';');
		bool no_data = true;
		for (int i = 0; i < 10; i++)
		{
			string temp;
			getline(ss, temp, ';');
			stringstream conv(temp);
			int n;
			if (conv >> n) {
				no_data = false;
				break;
			}
		}
		if (no_data) {
			cout << name << endl;
		}

	}

	//Zadatak 6
	/*
	vector<Country> v;
	string line;
	getline(in, line);
	while (getline(in, line))
	{
		stringstream ss(line);
		string name;
		getline(ss, name, ';');
		Country c(name);

		for (int i = 0; i < 10; i++)
		{
			string temp;
			getline(ss, temp, ';');
			stringstream conv(temp);
			int x;
			if (conv >> x) {
				c.add_scientists(x);
			}
		}
		v.push_back(c);
	}
	*/

	in.close();

	//Zadatak 6
	/*
	for (int i = 0; i < v.size(); i++)
	{
		Country c = v[i];
		cout << c.get_name() << ":" << c.average() << endl;
	}
	*/

	return 0;
}