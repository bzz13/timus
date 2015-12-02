#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	M = M % N;

	int *ns = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> ns[i];

	for (int i = M; i < M + 10; ++i)
		cout << ns[i % N];
	delete[] ns;
}