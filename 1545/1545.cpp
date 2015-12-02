#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int count;
	cin >> count;

	std::map<char, vector<string> > dictionary;
	string str;
	for (int i = 0; i < count; ++i)
	{
		cin >> str;
		char s = str[0];
		dictionary[s].push_back(str);
	}

	char c;
	cin >> c;
	for (std::vector<string>::iterator i = dictionary[c].begin(); i != dictionary[c].end(); ++i)
	{
		cout << (*i) << endl;
	}
}