#include <stdio.h>
using namespace std;

int main()
{
	int count, qcount, x, y;
	scanf("%d", &count);
	int *ns = new int[count];
	for (int i = 0; i < count; ++i)
		scanf("%d", ns+i);

	scanf("%d", &qcount);
	for (int i = 0; i < qcount; ++i)
	{
		int sum = 0;
		scanf("%d%d", &x, &y);
		for (int i = x - 1; i < y; ++i)
			sum += ns[i];
		printf("%d\n", sum);
	}

	delete[] ns;
	return 0;
}