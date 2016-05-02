#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int M, N, P;
	cin >> N >> M >> P;
	vector<int> letters(23, 0);

	string word;
	for (int i = 0; i < N; ++i)
	{
		cin >> word;
		for(auto c: word)
			letters[c - 'A'] ++;
	}

	for (int i = 0; i < P; ++i)
	{
		cin >> word;
		for(auto c: word)
			letters[c - 'A'] --;
	}


	for (int i = 0; i < 23; ++i)
	{
		while(letters[i] > 0 )
		{
			cout << (char) (i + 'A');
			letters[i] --;
		}
	}
	return 0;
}
