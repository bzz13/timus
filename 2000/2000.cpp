#include <iostream>
#include <vector>
using namespace std;

long sum(vector<int>& v, int begin, int end)
{
    long s = 0;
    for (int i = begin; i < end; ++i)
        s += v[i];
    return s;
}

int main()
{
    int count, startA, startB;
    long total = 0;
    cin >> count;
    vector<int> v(count, 0);
    for (int i = 0; i < count; ++i)
    {
        cin >> v[i];
        total += v[i];
    }
    cin >> startA >> startB;
    startA --;
    startB --;


    if (startA == startB)
    {
        long sa = sum(v, 0, startA);
        long max = sa > (total - sa) ? sa : (total - sa);
        cout << max << " " << (total - max);
    }
    else
    {

        if (startB - startA == 1 || startA - startB == 1)
        {
            long sa = startA < startB ? sum(v, 0, startA + 1) : sum(v, startA, count);
            cout << sa << " " << total - sa;
        }
        else
        {
            int m = (startA + startB) / 2;
            long sa = startA < startB ? sum(v, 0, m + 1) : sum(v, m, count);
            cout << sa << " " << total - sa;
        }
    }
}