#include <iostream>
#include <stdio.h>
#include <string>
#include <cctype>
using namespace std;

const string tram = "tram";
const string troll = "trolleybus";

int main()
{	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int tramCount = 0, trollCount = 0;

	string str = "";
	char c;
	while(cin >> noskipws >> c)
	{
		// cout << "'" << c << "'" << endl;
		if (isalpha(c))
		{
			str += c;
			continue;
		}
		
		if (str == tram)
			tramCount ++;
		else if (str == troll)
			trollCount ++;
		// cout << str << endl;
		str = "";
	}

	if (tramCount == trollCount)
		cout << "Bus driver";
	else
		if (tramCount > trollCount)
			cout << "Tram driver";
		else
			cout << "Trolleybus driver";
	return 0;
}