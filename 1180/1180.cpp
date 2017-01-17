#include <iostream>
using namespace std;
int main()
{
    int s = 0;
    char c;
    while (cin >> c) 
    {
        s += c - '0';
    }
    if (s % 3 == 0)
        cout << 2;
    else
        cout << 1 << endl << s % 3;
    return 0;
}
