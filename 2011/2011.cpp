#include <iostream>
#include <map>
using namespace std;

int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void FactorMlt(int count, std::map<int, int, std::greater<int> >* f)
{
	int tmp, pos;
	for (int i = 2; i <= count; ++i)
	{
		tmp = i;
		pos = 0;
		while(tmp > 1)
		{
			if (tmp % primes[pos] == 0)
			{
				(*f)[primes[pos]] ++;
				tmp /= primes[pos];
			}
			else
				pos++;
		}
	}
}

void FactorDv(int count, std::map<int, int, std::greater<int> >* f)
{
	int tmp, pos;
	for (int i = 2; i <= count; ++i)
	{
		tmp = i;
		pos = 0;
		while(tmp > 1)
		{
			if (tmp % primes[pos] == 0)
			{
				(*f)[primes[pos]] --;
				tmp /= primes[pos];
			}
			else
				pos++;
		}
	}
}

int main()
{
	int count, tmp, limit = 6;
	int nums[3] = {0, 0, 0};

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> tmp;
		nums[tmp - 1]++;
	}

	map<int, int, std::greater<int> > f;

	FactorMlt(count, &f);	

	for (int i = 0; i < 3; ++i)
		FactorDv(nums[i], &f);

	int g = 1;

	// for (std::map<int, int>::iterator it = f.begin(); it != f.end(); ++it)		
	// 	cout << it->first << ": " << it->second << endl;

	for (std::map<int, int>::iterator it = f.begin(); it != f.end(); ++it)
	{
		for (int i = 1; i <= it->second; ++i)
		{
			g *= it->first;
			if (g >= limit)
			{
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";
	return 0;
}