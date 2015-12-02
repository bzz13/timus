#include <iostream>
using namespace std;

bool isPunto(char c)
{
	return c == ' ' || c == '.' || c == ',' || c == '?' || c == '-' || c == ':' || c == '!' || c == '?' || c == '\n' || c == '\r';
}

bool endOfSentense(char c)
{
	return c == '.' || c == '!' || c == '?';
}

int main()
{
	bool begin = true;
	char c;
	while (std::cin.get(c))
	{
		if (isPunto(c))
		{
			if (endOfSentense(c))
				begin = true;
			cout << c;
		}	
		else
		{
			if (begin)
			{
				cout << c;
				begin = false;
			}
			else
				cout << (char)(c - 'A' + 'a');
		}
	}
}