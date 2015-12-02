#include <iostream>
using namespace std;

unsigned long int Answers[100];

int main()
{
	Answers[0] = 2;
	Answers[1] = 2;
	for (int i = 2; i < 46; ++i)
		Answers[i] = Answers[i-1] + Answers[i-2];

	int N;
	cin >> N;
	cout << Answers[N-1];
} 