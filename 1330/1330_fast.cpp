#include <stdio.h>
using namespace std;

int main()
{
	int count, qcount, x, y, tmp;
	scanf("%d", &count);
	int *answers = new int[count + 1];
	answers[0] = 0;
	for (int i = 1; i <= count; ++i)
	{
		scanf("%d", &tmp);
		answers[i] = answers[i - 1] + tmp;
	}

	scanf("%d", &qcount);
	for (int i = 0; i < qcount; ++i)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", answers[y] - answers[x-1]);
	}

	delete[] answers;
	return 0;
}