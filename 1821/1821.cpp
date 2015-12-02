#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Biathlonist
{
public:
	string surname;
	unsigned int runningTime;
	unsigned int finishTime;

	Biathlonist(string surname, string time, int startOffset)
	{
		this->surname = surname;
		stringstream s(time);
		unsigned int  result, t;
		char c;
		s >> t;
		result = t * 600; // minutes
		// cout << surname << ": " << result << " from min; ";
		s >> c; // read ':'
		s >> t;
		result += t*10; // seconds
		// cout << result << " from sec; ";
		s >> c; // read '.'
		s >> t;
		result += t; // milisec
		// cout << result << " from ms" << endl;
		runningTime = result;
		result += startOffset * 300;
		finishTime = result;
	}

	bool operator <(const Biathlonist& other) const
	{
		return finishTime < other.finishTime;
	}

	void print()
	{
		cout << surname << " - rnt: " << runningTime << " fnt: " << finishTime << endl;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	int count;
	string s, t;
	cin >> count;
	std::vector<Biathlonist> v;
	for (int i = 0; i < count; ++i)
	{
		cin >> s >> t;
		Biathlonist b(s,t, i);
		v.push_back(b);
	}

	// for (std::vector<Biathlonist>::iterator b = v.begin(); b != v.end(); ++b)
	// 	b->print();
	// cout << endl;
	sort(v.begin(), v.end());
	// for (std::vector<Biathlonist>::iterator b = v.begin(); b != v.end(); ++b)
	// 	b->print();

	count = 1;
	std::vector<string> surnames;
	surnames.push_back(v[0].surname);
	unsigned int bestRunningTime = v[0].runningTime;

	for (std::vector<Biathlonist>::iterator b = v.begin() + 1; b != v.end(); ++b)
	{
		if ( (b->runningTime) < bestRunningTime )
		{
			count ++;
			bestRunningTime = b->runningTime;
			surnames.push_back(b->surname);
		}
	}
	cout << count;
	sort(surnames.begin(), surnames.end());
	for (std::vector<string>::iterator surname = surnames.begin(); surname != surnames.end(); ++surname)
		cout << endl << *surname;

}