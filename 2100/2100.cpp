#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, count = 2;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string guest;
        cin >> guest;
        count += 1;
        if (guest[guest.size() - 1 - 3] == '+')
            count += 1;
    }
    if (count == 13)
        count++;
    cout << count*100;
    return 0;
}