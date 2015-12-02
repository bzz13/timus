#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, size, tmp, popCount = 0;
	scanf("%d", &count);
	std::vector<int> v, o(count);
	for (int i = 0; i < count; ++i)
	{
		scanf("%d", &tmp);
		o[i] = tmp;
		if (o[i] == -1)
			popCount++;
	}

	for (auto i: o)
	{
		if (popCount == 0)
			break;
		switch(i)
		{
			case -1:
				printf("%d\n", v.back() );
				v.pop_back();
				popCount --;
				break;
			case 0:
				size = v.size();
				if (popCount > size)
					for (int j = 0; j < size; ++j)
						v.push_back(v[j]);
				break;
			default:
				v.push_back(i);
				break;
		}
	}
}