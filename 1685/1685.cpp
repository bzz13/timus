#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void decode(string::iterator begin, int size)
{
	if (size < 3)
	{
		for (int i = 0; i < size; ++i)
			cout << *(begin + i);
		return;
	}

	int c = (size - 1) % 2;
	decode(begin + 1, (size - c) / 2);
	cout << *begin;
	decode(begin + 1 + (size - c) / 2, size / 2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	string phrase;
	getline(cin, phrase);

	decode(phrase.begin(), phrase.size());
	cout << endl;
}