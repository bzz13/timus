#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int count, i;
	unsigned int tmp;
	scanf("%d", &count);
	priority_queue<unsigned int> q;
	for (i = 0; i < count / 2 + 1; ++i)
	{
		scanf("%d", &tmp);
		q.push(tmp);
	}
	for (i = count/2 + 1; i < count; ++i)
	{
		scanf("%d", &tmp);
		q.push(tmp);
		q.pop();
	}
	if (count%2 == 1)
	{
		double a = q.top(); 
		printf("%.1f", a);
	}
	else
	{
		double a, b;
		a = q.top();
		q.pop();
		b = q.top();
		printf("%.1f", (a+b)/2.0);
	}
}