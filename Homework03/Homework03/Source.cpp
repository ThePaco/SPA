#include <iostream>
#include "Dijakrsta.h"
using namespace std;

int main()
{
    bool isWalls = true;

    cout << "Map size is 20x40" << endl;

    int rowS;
    int columnS;

    cout << "Source coordinates" << endl;
    cout << "RowS: ";
    cin >> rowS;
    cout << "ColumnS: ";
    cin >> columnS;

    int rowD;
    int columnD;

    cout << "Destination coordinates" << endl;
    cout << "RowD: ";
    cin >> rowD;
    cout << "ColumnD: ";
    cin >> columnD;

    Dijakrsta path(rowS, columnS, rowD, columnD);

    return 0;
}
