#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Vertex
{
	int Id;
	vector<int> parents;
	bool operator<(const Vertex& other) const
	{
		return size() < other.size();
	}

	int size() const
	{
		return parents.size();
	}

	void removeParent(const int& p)
	{
		vector<int>::iterator idx = find(parents.begin(), parents.end(), p);
		if (idx != parents.end())
			parents.erase(idx);
	}

	void print()
	{
		cout << Id + 1 << ": ";
		for (vector<int>::iterator p = parents.begin(); p != parents.end(); ++p)
			cout << *p + 1 << ' ';
		cout << endl;
	}
};

void PrintArrayOfVector(vector<Vertex> v, int count)
{
	for (std::vector<Vertex>::iterator i = v.begin(); i != v.end(); ++i)
		i->print();
}

Vertex getFirstEmptyAvNotInP(vector<Vertex> &A, vector<int> &P)
{
	for (std::vector<Vertex>::iterator v = A.begin(); v != A.end(); ++v)
	{
		if (v->size() == 0)
		{
			vector<int>::iterator idx = find(P.begin(), P.end(), v->Id);
			if (idx == P.end())
				return *v;
		}
	}
	throw - 1;
}

void removeFromAllAv(vector<Vertex> &A, const int& p)
{
	for (std::vector<Vertex>::iterator v = A.begin(); v != A.end(); ++v)
	{
		if (v->Id != p)
		{
			v->removeParent(p);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, tmp;
	cin >> count;
	vector<Vertex> A(count);
	for (int i = 0; i < count; ++i)
		A[i].Id = i;

	vector<int> P;

	for (int i = 0; i < count; ++i)
	{
		while (true)
		{
			cin >> tmp;
			if (tmp == 0)
				break;
			A[tmp - 1].parents.push_back(i);
		}
	}

	sort(A.begin(), A.end());

	while (P.size() < count)
	{
		Vertex v = getFirstEmptyAvNotInP(A, P);
		P.push_back(v.Id);
		removeFromAllAv(A, v.Id);
	}

	for (std::vector<int>::iterator i = P.begin(); i != P.end(); ++i)
		cout << *i + 1 << ' ';

	return 0;
}
