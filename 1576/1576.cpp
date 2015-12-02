#include <iostream>
#include <ios>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

class Time
{
	int billTime;
	string time;
public:
	Time(string str)
	{
		int sec;
		char c;

		time = str;
		stringstream s(str);
		s.flags(std::ios::dec);
		s >> billTime; // read minutes
		// cout << billTime << " min and ";
		s >> c; // read ':'
		s >> sec; // read seconds
		// cout << sec << " sec => ";
		if (sec != 0 && (billTime > 0 || sec > 6))
			billTime ++;
		// cout << billTime << endl;
	}

	int GetBillingTime() const
	{
		return billTime;
	}

	void Print(ostream& stream)
	{
		stream << time << " eq " << GetBillingTime();
	}
};

class Tarif
{
	unsigned int abon, limit, cost, totalTime;
	string name;

public:
	Tarif(string name, int abonCost, int minutCost = 0, int freeMinutLimit = 0) 
	{ 
		this->totalTime = 0;
		this->abon = abonCost;
		this->limit = freeMinutLimit;
		this->cost = minutCost;
		this->name = name;
	}
	~Tarif()
	{ 
	}

	void AddTime(Time t)
	{
		totalTime += t.GetBillingTime();
	}

	int GetCost() const
	{
		return abon + (totalTime > limit ? totalTime - limit : 0) * cost;
	}

	void Print(ostream& stream) const
	{
		stream << name << GetCost() << endl;
	}

};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	int abon, minutLimit, minutCost, count;
	string timeStr;

	cin >> abon >> minutCost;
	Tarif bsc("Basic:     ", abon, minutCost);
	cin >> abon >> minutLimit >> minutCost;
	Tarif cmb("Combined:  ", abon, minutCost, minutLimit);
	cin >> abon;
	Tarif unl("Unlimited: ", abon);

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> timeStr;
		Time t(timeStr);
		// t.Print(cout);

		bsc.AddTime(t);
		cmb.AddTime(t);
		unl.AddTime(t);
	}

	bsc.Print(cout);
	cmb.Print(cout);
	unl.Print(cout);
}