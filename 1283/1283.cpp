#include <iostream>
using namespace std;

int main()
{
	int answer = 0;
	float amount, limit, percent, remain;
	cin >> amount >> limit >> percent;
	remain = 1 - percent / 100;
	while(amount > limit)
	{
		amount *= remain;
		answer ++;
	}
	cout << answer;
}