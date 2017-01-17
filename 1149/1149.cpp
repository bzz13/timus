#include <iostream>
#include <string>
using namespace std;

static const string str_minus("-");
static const string str_plus("+");

string get_next_a(const int n, const int c)
{
    if (n == c)
        return "sin(" + to_string(n) + ")";
    return "sin(" + to_string(c) + (c & 1 ? str_minus : str_plus ) + get_next_a(n, c + 1) + ")";
}

string get_a(const int n)
{
    return get_next_a(n, 1);
}

string get_s(const int n)
{
    string result;
    for (int i = 0; i < n - 1; ++i)
        result += "(";
    for (int i = 0; i < n; ++i)
        result += get_a(i+1) + "+" + to_string(n-i) + ( n-i != 1 ? ")" : "");
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << get_s(n) << endl;
}