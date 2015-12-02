#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	int answer = (B - A) / 2;
	if ( ((A % 2) + (B % 2)) >= 1)
		answer ++;
	cout << answer;
}