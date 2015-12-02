#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int limit = 10001;

int f(const int& N)
{
	int answer = 1;
	for (int i = 2; i <= sqrt(N); ++i)
		if (N % i == 0)
			answer ++;
	return answer;
}

vector<int> getArguments(const map<int, int>& f, const int& val, const int& add = 0)
{
	vector<int> answer;
	for(auto p: f)
		if (p.second == val)
			answer.push_back(p.first + add);
	return answer;
}

int main()
{
	int m, n, k, answer = 0;
	cin >> m >> n >> k;
	
	map<int, int> function;
	for(int i = 1; i < limit; ++i)
		function[i] = f(i);
	
	vector<int> daN = getArguments(function, n);
	vector<int> daM = getArguments(function, m, k);
	vector<int> v(max(daN.size(), daM.size()));

	vector<int>::iterator it = set_intersection (daN.begin(), daN.end(), daM.begin(), daM.end(), v.begin());
	v.resize(it - v.begin()); 
	
	cout << (v.size() == 0 ? 0 : v[0]);

	return 0;
}