#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	long long count, tmp, answer = -1;
	scanf("%lld", &count);

	std::map<long long, long long> monies;
	for (int i = 0; i < count; ++i)
	{
		scanf("%lld", &tmp);
		std::map<long long, long long>::iterator find = monies.find(tmp);
		if (find == monies.end())
		{
			monies[tmp] = 1;
			if (answer == -1)
				answer = tmp;
		}
		else	
		{
			monies[tmp]++;
			if (monies[tmp] > count / 2)
				answer = tmp;
		}
	}

	printf("%lld", answer);
}