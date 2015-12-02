#include <iostream>
#include <deque>
using namespace std;

int main()
{
	string encrypted;
	cin >> encrypted;
	deque<char> decrypted;

	for(std::string::iterator it = encrypted.begin(); it != encrypted.end(); ++it) 
	{
		if (decrypted.size() == 0)
			decrypted.push_back(*it);
		else
		{
			if (decrypted.back() == *it)
				decrypted.pop_back();
			else
				decrypted.push_back(*it);
		}
	}

	for (std::deque<char>::iterator it = decrypted.begin(); it != decrypted.end(); ++it)
		cout << *it;
}