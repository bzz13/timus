#include <iostream>
#include <string>
using namespace std;

int main()
{
	int h, w, count, answer = 1;
	cin >> h >> w >> count;
	string word;

	int positionInLine = 0,
		positionInPage = 0;

	for (int i = 0; i < count; ++i)
	{
		cin >> word;
		int wordSize = word.size();
		if (positionInLine == 0)
		{
			// cout << word;
			positionInLine = wordSize;
		}
		else
		{
			if (positionInLine + 1 + wordSize > w)
			{
				positionInLine = wordSize;

				if (positionInPage == h - 1)
				{
					// cout << endl << "---------------" << endl << word;
					answer++;
					positionInPage = 0;
				}
				else
				{
					// cout << endl << word;
					positionInPage++;
				}
			}
			else
			{
				positionInLine += (1 + wordSize);
				// cout << " " << word;
			}
		}
	}
	cout << answer;
}