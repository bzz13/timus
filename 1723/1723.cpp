#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int full_size = input.size();
	map<char, int> powers;
	
	const char *cstr = input.c_str();
	for (int i = 0; i < full_size; ++i)
	{
		char c = cstr[i];
		powers[c]++;
	}
	
	int maxPow = 0;
	char maxPowWord;
	for (std::map<char, int>::iterator it = powers.begin(); it != powers.end(); ++it)
	{
		// cout << it->first << ": " << it->second << endl;
		if (it->second > maxPow)
		{
			maxPow = it->second;
			maxPowWord = it->first;
		}
	}
	cout << maxPowWord;
}