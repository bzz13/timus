#include <iostream>
#include <deque>
#include <string>
using namespace std;

void printQ(deque<char>& q)
{
	while (q.size() > 0)
	{
		cout << q.front();
		q.pop_front();
	}
}
void printS(deque<char>& s)
{
	while (s.size() > 0)
	{
		cout << s.front();
		s.pop_front();
	}
}
void print(deque<char>& q, deque<char>& s)
{
	printQ(q);
	printS(s);
}

void resolve(deque<char>& q, deque<char>& s)
{
	int tmp;
	deque<char> replaced;
	do
	{
		if (q.size() > 0)
		{
			tmp = q.back() - '0' + 1;
			q.pop_back();
			s.pop_front();
		}
		else
			tmp = '0';

		if (tmp > 9)
			replaced.push_front('0');
		else
		{
			replaced.push_front(tmp + '0');
			break;
		}
	} while (true);

	while (replaced.size() > 0)
	{
		tmp = replaced.front();
		q.push_back(tmp);
		s.push_front(tmp);
		replaced.pop_front();
	}
}

int main()
{
	string str;
	cin >> str;
	int i = 0, size = str.size(), tmp, count;
	deque<char> q;
	deque<char> s;

	bool correctChanged = false, changed = false, chet = size % 2 == 0;
	count = chet ? size / 2 : size / 2 + 1;

	for (int i = 0; i < count; ++i)
	{
		q.push_back(str[i]);
		s.push_front(str[i]);
		if (str[i] != str[size - 1 - i])
		{
			changed = true;
			correctChanged = str[i] > str[size - 1 - i];
		}
	}

	if (!changed || correctChanged)
	{
		if (!chet)
			s.pop_front();
		print(q, s);
	}
	else
	{
		resolve(q, s);
		if (!chet)
			s.pop_front();
		print(q, s);
	}

	return 0;
}