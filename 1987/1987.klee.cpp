#include <iostream>
#include <ostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

struct point
{
    uint  val;
    short type;
    int   number;
    uint  size;

    bool operator<(const point& other) const
    {
        if (val == other.val)
            return type < other.type;
        return val < other.val;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    int n, m;
    uint a, b;

    cin >> n;

    vector<point> v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        v.push_back(point{a, 0, i, b - a + 1});
        v.push_back(point{b, 2, i, b - a + 1});
    }

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a;
        v.push_back(point{a, 1, -1, 0});
    }

    sort(v.begin(), v.end());

    map<uint, uint> s;
    for(auto p: v)
    {
        // cout << p.val << ", " << p.type << ", " << p.number << endl;
        switch (p.type)
        {
            case 0:
                s[p.size] = p.number; // this is hack (actualy with row 71)
                break;
            case 1:
                if (s.size() == 0)
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << s.begin()->second << endl;
                }
                break;
            case 2:
                s.erase(p.size);
                break;
        }
    }

    return 0;
}