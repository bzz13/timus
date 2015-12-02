#include <iostream>
#include <string>
#include <map>
using namespace std;

std::map<char, int> costs;

int main()
{
	costs['a'] = costs['d'] = costs['g'] = costs['j'] = costs['m'] = costs['p'] = costs['s'] = costs['v'] = costs['y'] = costs['.'] = costs[' '] = 1;
	costs['b'] = costs['e'] = costs['h'] = costs['k'] = costs['n'] = costs['q'] = costs['t'] = costs['w'] = costs['z'] = costs[',']              = 2;
	costs['c'] = costs['f'] = costs['i'] = costs['l'] = costs['o'] = costs['r'] = costs['u'] = costs['x'] =              costs['!']              = 3;

	char input[1002];
	cin.getline(input, sizeof(input));
	string s(input);
	int sum = 0;
	for (int i = 0; i < s.size(); ++i)
	{	
		sum += costs[s[i]];
		// cout << s[i] << ": " << costs[s[i]] << " = " << sum << endl;
	}
	cout << sum;
}