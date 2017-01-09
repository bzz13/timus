#include <iostream>
#include <ostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

struct part
{
    uint a;
    uint b;
    uint n;

    bool operator<(const part& other) const
    {
        return (other.b - other.a) < (b - a);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    uint n, a, b, minA, maxB, col, answer;

    cin >> n;

    vector<part> v;
    for (uint y = 0; y < n; ++y)
    {
        cin >> a >> b;
        if (y == 0)
        {
            minA = a;
            maxB = b;
        }
        if(b > maxB)
            maxB = b;
        v.push_back(part{a, b, y + 1});
    }

    sort(v.begin(), v.end());

    uint* matr = new uint[maxB - minA + 1];

    for(auto p: v)
    {
        for (uint x = p.a - minA; x <= p.b - minA; ++x)
        {
            matr[x] = p.n;
        }
    }

    cin >> n;
    for (uint i = 0; i < n; ++i)
    {
        cin >> col;
        if (col < minA || col > maxB)
            cout << -1 << endl;
        else
            cout << matr[col-minA] << endl;
    }

    delete[] matr;

    return 0;
}