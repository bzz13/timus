#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;

const int maxLenght = 60;
const int maxTeamCount = 20;

class Team
{
	bitset<maxLenght> _pl;

public:
	Team(const int& n, const bitset<maxLenght>& players) : _pl(players){ }
	~Team(){ }

	int IntersectionCount(const Team& other) const
	{
		return (_pl & other.Players()).count();
	}

	bitset<maxLenght> Players() const
	{
		return _pl;
	}
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

bool hasIntersection(const vector<Team>& teams, const bitset<maxTeamCount>& subset)
{
	for (int i = 0; i < teams.size(); ++i)
	{
		if (!subset[i]) continue;
		for (int j = i + 1; j < teams.size(); ++j)
		{
			if (!subset[j]) continue;

			if (teams[i].IntersectionCount(teams[j]))
				return true;
		}
	}
	return false;
}

int runAlgo(const vector<Team>& teams)
{
	bitset<maxTeamCount> subset, high, resultset;
	high.set(teams.size(), true);

	auto result = 1;
	while((high & (++subset)).count() == 0)
	{
		auto c = subset.count();
		if (c <= result)
			continue;

		if (!hasIntersection(teams, subset))
		{
			if (result < c)
			{
				resultset = subset;
				result = c;
			}
		}
	}
	return result;
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

		teams.push_back(Team(i+1, intersector.GetPlayersIds(a, b, c)));
	}

	cout << runAlgo(teams);
	return 0;
}