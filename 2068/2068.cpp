#include <iostream>
using namespace std;

int main()
{
    unsigned int n, k;
    k = 0;
    cin >> n;
    while(n --> 0)
    {
        unsigned int m;
        cin >> m;
        k += (m - 1)/2;
    }
    if (k % 2 == 1)
        cout << "Daenerys" << endl;
    else
        cout << "Stannis" << endl;
    return 0;
}