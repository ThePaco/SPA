#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int menu()
{
	cout << "1 - open" << endl;
	cout << "2 - deposit" << endl;
	cout << "3 - withdraw" << endl;
	cout << "4 - print" << endl;
	cout << "5 - print all" << endl;
	cout << "6 - exit" << endl;
	int c;
	cin >> c;
	cin.ignore();
	return c;
}

void open(unordered_map<string, double>& m)
{
	cout << "iban:";
	string key;
	getline(cin, key);
	if (m.find(key) != m.end())
	{
		cout << "existing" << endl;
		return;
	}
	m[key] = 0;
}

void deposit(unordered_map<string, double>& m)
{
	cout << "iban:";
	string key;
	getline(cin, key);
	if (m.find(key) == m.end())
	{
		cout << "non existing" << endl;
		return;
	}
	double amount;
	cout << "amount:";
	cin >> amount;
	cin.ignore();
	m[key] += amount;

}

void withdraw(unordered_map<string, double>& m)
{
	cout << "iban:";
	string key;
	getline(cin, key);
	if (m.find(key) == m.end())
	{
		cout << "non existing" << endl;
		return;
	}
	double amount;
	cout << "amount:";
	cin >> amount;
	cin.ignore();
	m[key] -= amount;

}

void print(unordered_map<string, double>& m)
{
	cout << "iban:";
	string key;
	getline(cin, key);
	if (m.find(key) == m.end())
	{
		cout << "non existing" << endl;
		return;
	}
	cout << m[key] << endl;
}

void print_all(unordered_map<string, double>& m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << ":" << it->second << endl;
	}
}

int main()
{
	unordered_map<string, double> m;
	int choice;
	do
	{
		system("cls");
		choice = menu();
		switch (choice)
		{
		case 1:
			open(m);
			break;
		case 2:
			deposit(m);
			break;
		case 3:
			withdraw(m);
			break;
		case 4:
			print(m);
			break;
		case 5:
			print_all(m);
			break;
		}
		cout << "press enter to continue" << endl;
		cin.ignore();
	} while (choice != 6);

	return 0;
}