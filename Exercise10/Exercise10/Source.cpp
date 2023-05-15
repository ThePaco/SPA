#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int gen_rnd(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

vector<int> fill(int n, int min, int max)
{
    srand(time(nullptr));
    vector<int> v;
    for (size_t i = 0; i < n; i++)
    {
        v.push_back(gen_rnd(min, max));
    }
    return v;
}

void print(vector<int>& v)
{
    for (auto& n : v)
    {
        cout << n << " ";
    }
    cout << endl;
}

void insert(vector<int>& v)
{
    bool again;
    do
    {
        int n;
        cout << "n: ";
        cin >> n;
        v.push_back(n);
        push_heap(v.begin(), v.end());
        cout << "again(0/1)?";
        cin >> again;
    } while (again);
}

int main()
{
    vector<int> v = fill(10, 1, 100);
    print(v);
    make_heap(v.begin(), v.end());
    print(v);

    insert(v);
    print(v);

    while (!v.empty())
    {
        print(v);
        pop_heap(v.begin(), v.end());
        v.pop_back();
    }
    return 0;
}
