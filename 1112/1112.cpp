#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int min(int a, int b)
{
    return a > b ? b : a;
}
int max(int a, int b)
{
    return a < b ? b : a;
}

struct segment
{
    int A;
    int B;

    friend istream& operator>>(istream& is, segment& s)
    {
        is >> s.A >> s.B;
        if (s.A > s.B)
        {
            int tmp = s.A;
            s.A = s.B;
            s.B = tmp;
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, segment& s)
    {
        return (os << s.A << " " << s.B << endl);
    }

    bool IsIntersectWith(segment& other)
    {
        bool result = min(B, other.B) - max(A, other.A) > 0;
        // cout << *this << " V " << other << " = " << result << endl;
        return result;
    }

    bool operator==(segment& other)
    {
        return A == other.A && B == other.B;
    }
};

bool ByBegin(segment& a, segment& b)
{
    return a.A < b.A;
}

unordered_map<int, vector<segment>> cache;

vector<segment> bestSolution(vector<segment>& initial, int position)
{
    if(cache.find(position) == cache.end())
    {
        vector<segment> result;
        result.push_back(initial[position]);

        vector<segment> tmp;
        for (int i = position + 1; i < initial.size(); ++i)
        {
            if(!initial[position].IsIntersectWith(initial[i]))
            {
                auto bestForI = bestSolution(initial, i);
                if (bestForI.size() > tmp.size())
                {
                    tmp = bestForI;
                }
            }
        }

        result.insert(result.end(), tmp.begin(), tmp.end());
        cache[position] = result;
    }
    return cache[position];
}

int main()
{
    int count;
    cin >> count;
    vector<segment> v;
    for (int i = 0; i < count; ++i)
    {
        segment s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), ByBegin);

    vector<segment> result;
    for (int i = 0; i < v.size(); ++i)
    {
        vector<segment> current = bestSolution(v, i);
        if (current.size() > result.size())
        {
            result = current;
        }
    }

    cout << result.size() << endl;
    for(auto s: result)
        cout << s;
}