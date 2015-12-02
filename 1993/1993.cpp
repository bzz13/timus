#include <iostream>
#include <stdio.h>
#include <string>
#include <cctype>
using namespace std;

const int UndefState = 0;
const int SubjState = 1;
const int ObjState = 2;
const int VerbState = 3;
const int SentanceBeginState = 4;

bool isFirst = true;

void toU(string& str)
{
	str[0] = toupper(str[0]);
}
void toL(string& str)
{
	str[0] = tolower(str[0]);
}

void printYodaSentance(int &c, string& subj, string& obj, string& verb)
{
	if (c == 3)
	{
		if (isFirst)
		{
			toU(obj);
			toL(subj);
			toL(verb);
			isFirst = false;
		}
		
		cout << obj << ' ' << subj << ' ' << verb;
		subj = "";
		obj = "";
		verb = "";
		c = 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int state = UndefState, count = 0;
	string subj = "", obj = "", verb = "";
	char c;
	while (cin >> noskipws >> c)
	{
		switch (state)
		{
			case SubjState:
			{
				if (c == ')')
				{
					state = UndefState;
					printYodaSentance(++count, subj, obj, verb);
				}
				else
					subj += c;
				break;
			}
			case ObjState:
			{
				if (c == '}')
				{
					state = UndefState;
					printYodaSentance(++count, subj, obj, verb);
				}
				else
					obj += c;
				break;
			}
			case VerbState:
			{
				if (c == ']')
				{
					state = UndefState;
					printYodaSentance(++count, subj, obj, verb);
				}
				else
					verb += c;
				break;
			}
			case SentanceBeginState:
			{
				if (c == '(')
					state = SubjState;
				else if (c == '{')
					state = ObjState;
				else if (c == '[')
					state = VerbState;
				else cout << c;
				break;
			}
			default:
			{
				if (c == '(')
					state = SubjState;
				else if (c == '{')
					state = ObjState;
				else if (c == '[')
					state = VerbState;
				else if (ispunct(c))
					{
						state = SentanceBeginState;
						cout << c;
					}
				break;
			}
		}
	}

	return 0;
}