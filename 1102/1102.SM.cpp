#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct SM
{
	private:
		int state = 0;
	public:
		void Next(char& c)
		{
			switch(state)
			{
				case 0:
					switch(c)
					{
						case 'e':
							state = 1;
							break;
						case 'n':
							state = 3;
							break;
						case 't':
							state = 7;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 1:
					switch(c)
					{
						case 'n':
							state = 2;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 2:
					switch(c)
					{
						case 'o':
							state = 0;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 3:
					switch(c)
					{
						case 'o':
							state = 4;
							break;
						case 'i':
							state = 0;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 4:
					switch(c)
					{
						case 't':
							state = 5;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 5:
					switch(c)
					{
						case 'u':
							state = 6;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 6:
					switch(c)
					{
						case 'p':
							state = 0;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 7:
					switch(c)
					{
						case 'u':
							state = 8;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 8:
					switch(c)
					{
						case 'o':
							state = 0;
							break;
						case 'p':
							state = 9;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 9:
					switch(c)
					{
						case 'n':
							state = 10;
							break;
						case 't':
							state = 11;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 10:
					switch(c)
					{
						case 'i':
							state = 0;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 11:
					switch(c)
					{
						case 'u':
							state = 12;
							break;
						default:
							state = -1;
							break;
					}
					break;
				case 12:
					switch(c)
					{
						case 'o':
							state = 0;
							break;
						default:
							state = -1;
							break;
					}
					break;
				default:
					state = -1;
					break;
			}
		}

		const bool IsCorrect()
		{
			return state != -1;
		}
		const bool IsFinale()
		{
			return state == 0;
		}

		void Reset()
		{
			state = 0;
		}

};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count;
	cin >> count;
	SM sm;

	char line[10000000];
	gets(line);

	for (int i = 0; i < count; ++i)
	{
		gets(line);
		int lenght = strlen(line);

		sm.Reset();
		while (lenght --> 0)
		{
			sm.Next(*(line + lenght));
			if(!sm.IsCorrect())
				break;
		}
		cout << (sm.IsFinale() ? "YES" : "NO" ) << endl;
	}

	return 0;
}