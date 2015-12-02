#include <iostream>
#include <list>
#include <cmath>
using namespace std;


int main()
{
	list<int> answer;
	int N, M, Y;
	cin >> N >> M >> Y;

	for (int x = 0; x < M; ++x)
	{
		int r = 1;
		for (int i = 0; i < N; ++i)
			r = (r * x) % M;
		if (r == Y)
			answer.push_back(x);
	}
	if (answer.size() == 0)
		cout << -1;
	else
		for (std::list<int>::iterator it = answer.begin(); it != answer.end(); ++it)
			cout << (*it) << ' ';
}