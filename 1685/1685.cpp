#include <iostream>
#include <string>
using namespace std;

void decode(string::const_iterator begin, const int& size)
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
	string phrase;
	getline(cin, phrase);
	decode(phrase.cbegin(), phrase.size());
	cout << endl;
}