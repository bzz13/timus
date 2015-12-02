#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

unsigned long long min(const unsigned long long  &i , const unsigned long long  &j)
{
	return i < j ? i : j;
}

unsigned long long getMinDiff(std::vector<unsigned long long> v, unsigned long long add)
{
	unsigned long long answer = ULLONG_MAX;
	for (std::vector<unsigned long long>::iterator i = v.begin(); i != v.end(); ++i)
		answer = min(answer, add > (*i) ? add-(*i) : (*i)-add);
	return answer;
}

void printV(std::vector<unsigned long long> v)
{
	for (std::vector<unsigned long long>::iterator i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

int main()
{
	unsigned long long x1, x2, x3, tmp1, tmp2, x, y, answer = 1;
	cin >> x1 >> x2 >> x3;
	vector<unsigned long long> v;
	v.push_back(x1);

	tmp1 = getMinDiff(v, x2);
	v.push_back(x2);
	// cout << "tmp1: " << tmp1 << endl; 
	// printV(v);


	tmp2 = getMinDiff(v, x3);
	v.push_back(x3);
	// cout << "tmp2: " << tmp2 << endl;
	// printV(v);


	x = min(tmp1, tmp2);
	// cout << "x: " << x << endl;

	while(x != 0)
	{
		y = min(x, getMinDiff(v, x));
		v.push_back(x);
		// printV(v);
		// cout << "(x ,y) = (" << x << ',' << y << ")" << endl;
		x = y;
		answer++;
	}
	cout << answer;
	return 0;
}