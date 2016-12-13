#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

const int maxLenght = 64;

class Team
{
	int _id;
	int _weight;
	bitset<maxLenght> _pl;

public:
	Team(const int& n, const bitset<maxLenght>& players) : _id(n), _pl(players), _weight(0) { }
	~Team(){ }

	void CheckAndIncreaseWeight(Team& other)
	{
		auto count = IntersectionCount(other);
		_weight += count;
		other._weight += count;
	}

	void CheckAndDecreaseWeight(Team& other)
	{
		auto count = IntersectionCount(other);
		_weight -= count;
		other._weight -= count;
	}

	int IntersectionCount(const Team& other) const
	{
		return (_pl & other.Players()).count();
	}

	int Weight() const
	{
		return _weight;
	}
	bitset<maxLenght> Players() const 
	{
		return _pl;
	}

	void Print() const { cout << _weight << " id " << _id << ": " << _pl << endl; }
};

class Intersector
{
	unordered_map<string, int> players;

	int findOrInsertAndGetId(string a)
	{
		auto it = players.find(a);
		if (it == players.end())
		{
			int id = players.size();
			players.insert( {{a, id}} );
			return id;
		}
		return it->second;
	}

public:
	Intersector() { };
	~Intersector() { };

	bitset<maxLenght> GetPlayersIds(string a, string b, string c)
	{
		bitset<maxLenght> result;
		result.set(findOrInsertAndGetId(a));
		result.set(findOrInsertAndGetId(b));
		result.set(findOrInsertAndGetId(c));
		return result;
	}
};

bool sorter (const Team& a, const Team& b) { return a.Weight() > b.Weight(); };

void printTeams(const vector<Team>& teams)
{
	for(auto team: teams)
	{
		team.Print();
	}
	cout << endl;
}


template<size_t N> bitset<N> operator++ (bitset<N>& lhs) noexcept
{
	bool p = true;
	for (int i = 0; i < N; ++i)
	{
		if(lhs[i])
		{
			lhs.set(i, false);
		}
		else
		{
			lhs.set(i, true);
			break;
		}
	}
	return lhs;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif

	int count;
	cin >> count;
	vector<Team> teams;
	Intersector intersector;

	for (int i = 0; i < count; ++i)
	{
		string a,b,c;
		cin >> a >> b >> c;

		auto t = Team(i+1, intersector.GetPlayersIds(a, b, c));
		for(auto& team: teams)
			team.CheckAndIncreaseWeight(t);
		teams.push_back(t);
	}

	printTeams(teams);
	sort(teams.begin(), teams.end(), sorter);
	printTeams(teams);

	while(teams.size() > 0 && teams[0].Weight() > 0)
	{
		auto t = teams[0];
		teams.erase(teams.begin());

		for(auto& team: teams)
			team.CheckAndDecreaseWeight(t);
		sort(teams.begin(), teams.end(), sorter);

		printTeams(teams);
		count --;
	}
	cout << count;
}