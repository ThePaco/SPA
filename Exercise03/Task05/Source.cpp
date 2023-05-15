#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

void init_array(ifstream &in, vector<string> &arr) {

	string s;
	while (in >> s)
	{
		arr.push_back(s);
	}
}

void print(string& s) {
	cout << s << endl;
}

int main() {
	
	ifstream in("NekiTekst.txt");
	
	if (!in) {
		cout << "404" << endl;
		return 1;
	}

	vector<string> arr;
	init_array(in, arr);
	in.close();

	//for_each(arr.begin(), arr.end(), print);
	//cout << count(arr.begin(), arr.end(), "the") << endl;

	auto it = find(arr.begin(), arr.end(), "the");
	int n = 0;
	if (it != arr.end()) {
		n++;
	}
	cout << n << endl;

	return 0;
}