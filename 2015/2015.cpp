#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Friend
{
	int Id;
	float MaxSum;
	int Benifit;
};

struct Apart
{
	int Id;
	int RoomsCount;
	float Cost;
	int Benifit;
};

bool apartmentsSorter(const Apart& ap1, const Apart& ap2)
{
	// if (ap1.Benifit == ap2.Benifit)
	// 	return ap1.Cost > ap2.Cost;
	return ap1.Benifit > ap2.Benifit;
}

bool friendsSorter(const Friend& f1, const Friend& f2)
{
	return f1.Benifit < f2.Benifit;
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	float myMaxSum;	int myOneBenifit, myTwoBenifit;
	cin >> myMaxSum >> myOneBenifit >> myTwoBenifit;

	int friendsCount;
	cin >> friendsCount;
	vector<Friend> friends(friendsCount);
	for (int i = 0; i < friendsCount; ++i)
	{
		friends[i].Id = i+1;
		cin >> friends[i].MaxSum >> friends[i].Benifit;
	}
	// sort(friends.begin(), friends.end(), friendsSorter);
	// for(auto f: friends)
	// 	cout << f.Id << endl;

	int apartCount;
	cin >> apartCount;
	vector<Apart> apartments(apartCount);
	for (int i = 0; i < apartCount; ++i)
	{
		apartments[i].Id = i+1;
		cin >> apartments[i].RoomsCount >> apartments[i].Cost >> apartments[i].Benifit;
	}
	// sort(apartments.begin(), apartments.end(), apartmentsSorter);
	// for(auto a: apartments)
	// 	cout << a.Id << endl;


	int benifit = -1;
	int liveWithFrend = -1;
	int liveInApart = -1;

	for(auto a: apartments)
	{	
		if (a.Cost / 2 > myMaxSum)
			continue;

		if (a.RoomsCount == 1)
		{
			if (a.Cost > myMaxSum)
				continue;
			if (benifit < myOneBenifit + a.Benifit)
			{
				benifit = myOneBenifit + a.Benifit;
				liveInApart = a.Id;
				liveWithFrend = -1;
			}
		}
		else
		{
			if (a.Cost <= myMaxSum)
			{
				if (benifit < myTwoBenifit + a.Benifit)
				{
					benifit = myTwoBenifit + a.Benifit;
					liveInApart = a.Id;
					liveWithFrend = -1;
				}
			}
			for(auto f: friends)
			{
				if (a.Cost / 2 > f.MaxSum)
					continue;
				if (benifit < a.Benifit + f.Benifit)
				{
					benifit = a.Benifit + f.Benifit;
					liveInApart = a.Id;
					liveWithFrend = f.Id;
				}
			}
		}
	}
	// cout << benifit << endl;

	if (benifit == -1)
		cout << "Forget about apartments. Live in the dormitory.";
	else
		if (liveWithFrend == -1)
			cout << "You should rent the apartment #" << liveInApart << " alone.";
		else
			cout << "You should rent the apartment #" << liveInApart << " with the friend #" << liveWithFrend << ".";

	return 0;
}
