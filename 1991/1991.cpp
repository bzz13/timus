#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int unused = 0, alive = 0, tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if (tmp < m)
			alive += (m - tmp);
		else
			unused += (tmp - m);
	}

	cout << unused << " " << alive << endl;
}