#include <stdio.h>
#include <stack>
#include <deque> 
#include <math.h>

using namespace std;

int main()
{
	std::deque<double> deque (0, 10000000);
	std::stack<double> roots(deque);
	double val;
	while (scanf("%lf", &val) != EOF)
		roots.push(sqrt(val));	

	while (!roots.empty())
	{
		printf("%.4lf\n", roots.top());
		roots.pop();
	}
	return 0;
}