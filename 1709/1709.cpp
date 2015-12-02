#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
using namespace std;

const int maxSize = 102;
const int white = 0;
const int gray = 1;
const int black = 2;

const char Zero = '0';
const char Exist = '1';
const char Deleted = 'd';
const char Added = 'a';

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, d, a, tmp;
	long long answer = 0;
	char ch;
	cin >> count >> d >> a;

	char c[maxSize][maxSize] = {Zero};
	int color[maxSize] = {white};
	
	for (int i = 0; i < count; ++i)
		for (int j = 0; j < count; ++j)
			cin >> c[i][j];


	queue<int> q;
	for(int i = 0; i < count; ++i)
	{
		if (color[i] != white)
			continue;
		if (i != 0)
		{
			c[0][i] = Added;
			c[i][0] = Added;
			answer += a;
		}

		q.push(i);
		while(q.size() > 0)
		{
			tmp = q.front();
			q.pop();
			color[tmp] = gray;
			for (int j = 0; j < count; ++j)
			{
				if (c[tmp][j] == Exist || c[tmp][j] == Added)
				{
					switch(color[j])
					{
						case white:
						{
							color[j] = gray;
							q.push(j);
							break;
						}
						case gray:
						{
							c[tmp][j] = Deleted;
							c[j][tmp] = Deleted;
							answer += d;
							break;
						}
						case black:
							if (c[tmp][j] == Exist)
							{
								c[tmp][j] = Zero;
								c[j][tmp] = Zero;
							}
						default:
							break;
					}
				}
			}
			color[tmp] = black;
		}
	}

	cout << answer << endl;
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
			cout << (c[i][j]);
		cout << endl;
	}

	return 0;
}
