#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const string inconsistent = "Inconsistent",
				hungry = "hungry",
			satisfied = "satisfied";

int main()
	{
	int n, answer;
	cin >> n;

	int _min=10;
	int _max=-10000;

	for (int i = 0; i < n; i++) {
		int x;
		string s;
		cin >> x >> s;
		if(s == hungry)
			_max = max(x, _max);
		else 
			_min = min(_min, x);
	}
	if(_max < _min) 
		cout << _min;
	else
		cout << inconsistent;
}