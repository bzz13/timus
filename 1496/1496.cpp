#include <iostream>
#include <string>
#include <map>
using namespace std;


int main()
{
	int count;
	cin >> count;

	map<string, int> submits;
	string name;
	for (int i = 0; i < count; ++i)
	{
		cin >> name;
		submits[name] ++;
	}

	for (std::map<string, int>::iterator it = submits.begin(); it != submits.end(); ++it)
	{

		if ( (it->second) > 1)
			cout << it->first << endl;
	}
}