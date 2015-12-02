#include <iostream>
#include <stdio.h>
#include <cctype>
#include <deque>
#include <vector>
using namespace std;

bool isPolyndrom(deque<char>::iterator begin, deque<char>::iterator end, bool caseSensative = false)
{
	while (begin < end - 1)
	{
		if (caseSensative)
		{
			if (*begin != *(end - 1))
				return false;
		}
		else
		{
			if (toupper(*begin) != toupper(*(end - 1)))
				return false;
		}

		begin++;
		end--;
	}
	return true;
}

bool isSequenceEqual(deque<char> s1, deque<char> s2)
{
	if (s1.size() != s2.size())
		return false;
	else
	{
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[1])
				return false;
		}
	}
	return true;
}

void printPolyndrom(deque<char>::iterator begin, deque<char>::iterator end)
{
	while (begin != end)
		cout << (*(begin++));
	cout << endl;
}

bool solve(deque<char>& sequence, int& hb, int& he, int& gb, int& ge, vector<int>& caught)
{
	while (sequence.size() > 0)
	{
		char
			f = sequence[0],
			s = sequence[1],
			p = sequence[sequence.size() - 2],
			b = sequence[sequence.size() - 1];
		if ((isupper(f) && tolower(f) == s) || (islower(f) && toupper(f) == s))
		{
			caught[hb++] = gb++;
			sequence.pop_front();
			sequence.pop_front();
			continue;
		}
		if ((isupper(p) && tolower(p) == b) || (islower(p) && toupper(p) == b))
		{
			caught[he--] = ge--;
			sequence.pop_back();
			sequence.pop_back();
			continue;
		}
		if (isupper(f) && tolower(f) == b)
		{
			caught[hb++] = ge--;
			sequence.pop_front();
			sequence.pop_back();
			continue;
		}
		if (islower(f) && toupper(f) == b)
		{
			caught[he--] = gb++;
			sequence.pop_front();
			sequence.pop_back();
			continue;
		}

		int polyndromLength = sequence.size();

		while (!isPolyndrom(sequence.begin(), sequence.begin() + polyndromLength))
		{
			polyndromLength -= 2;
			if (polyndromLength == 0)
			{
				return false;
			}
		}
		// printPolyndrom(sequence.begin(), sequence.begin() + polyndromLength);

		deque<char> subsequence(polyndromLength);
		for (int i = 0; i < polyndromLength; ++i)
			subsequence[i] = sequence[i];

		vector<int> subcaught(polyndromLength/2);
		int shb = 0, she = polyndromLength/2 - 1, sgb = 0, sge = polyndromLength/2 - 1;
		if (!solve(subsequence, shb, she, sgb, sge, subcaught))
			return false;

		for(auto g: subcaught)
			caught[hb++] = g + gb;
		gb += polyndromLength/2;

		for (int i = 0; i < polyndromLength; ++i)
			sequence.pop_front();
	}
	return true;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	char c, hunter, ghost;
	cin >> count;

	vector<int> caught(count);
	deque<char> sequence(2 * count);

	for (int i = 0; i < 2 * count; ++i)
	{
		cin >> c;
		sequence[i] = c;
	}

	int hb = 0, he = count - 1, gb = 1, ge = count;
	if (!solve(sequence, hb, he, gb, ge, caught))
	{
		cout << "Impossible";
	}
	else
	{
		for (auto i : caught)
			cout << i << ' ';
	}

	return 0;
}
