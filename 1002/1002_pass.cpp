#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;

const string noSolution = "No solution.";

void printArray(string arr[], int size, bool printEndl = false)
{
	for (int i = 0; i < size - 1; ++i)
		cout << arr[i] << ' ';
	cout << arr[size - 1];
	if (printEndl)
		cout << endl;
}

string convertWord(string word)
{
	std::ostringstream stm;
	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
	{
		switch (*it) {
		case 'i':
		case 'j':
			stm << 1;
			break;

		case 'a':
		case 'b':
		case 'c':
			stm << 2;
			break;

		case 'd':
		case 'e':
		case 'f':
			stm << 3;
			break;

		case 'g':
		case 'h':
			stm << 4;
			break;

		case 'k':
		case 'l':
			stm << 5;
			break;

		case 'm':
		case 'n':
			stm << 6;
			break;

		case 'p':
		case 'r':
		case 's':
			stm << 7;
			break;

		case 't':
		case 'u':
		case 'v':
			stm << 8;
			break;

		case 'w':
		case 'x':
		case 'y':
			stm << 9;
			break;

		case 'o':
		case 'q':
		case 'z':
			stm << 0;
			break;
		}
	}

	return stm.str();
}

struct Solution
{
	int answerSize;
	string *answer;
};

void addWordToSolution(string word, Solution *solution)
{
	string *newAnswer = new string[solution->answerSize + 1];
	for (int i = 0; i < solution->answerSize; ++i)
		newAnswer[i] = solution->answer[i];
	newAnswer[solution->answerSize] = word;
	solution->answerSize++;
	string *old = solution->answer;
	solution->answer = newAnswer;
	//delete[] old;
}

void printSolution(Solution sol, bool printEndl = false)
{
	printArray(sol.answer, sol.answerSize, printEndl);
}

void printSolutionDebug(Solution sol, bool printEndl = false)
{
	cout << "{size: " << sol.answerSize << ", answer: [";
	printSolution(sol, false);
	cout << "]}";
	if (printEndl)
		cout << endl;
}

int getMaxKeyLength(map<string, string> map)
{
	int maxValue = 0;
	for (std::map<string, string>::iterator i = map.begin(); i != map.end(); ++i)
	{
		int size = (i->first).size();
		if (size > maxValue)
			maxValue = size;
	}
	return maxValue;
}

int getMinKeyLength(map<string, string> map)
{
	int minValue = 9999999;
	for (std::map<string, string>::iterator i = map.begin(); i != map.end(); ++i)
	{
		int size = (i->first).size();
		if (size < minValue)
			minValue = size;
	}
	return minValue;
}

Solution findSolution(string number, map<string, string> dictionary, int dictionarySize)
{
	map<string, Solution> resolvation;
	map<string, Solution>::iterator it;
	map<string, string>::iterator wordIt;
	map<string, string>::iterator dictionaryEnd = dictionary.end();

	for (int i = 1; i <= number.size(); ++i)
	{
		string resolvingWord = number.substr(0, i);
		// cout << endl << "resolvingWord:" << resolvingWord << endl;

		int maxKeyLenght = getMaxKeyLength(dictionary);
		int minKeyLenght = getMinKeyLength(dictionary);
		for (int s = minKeyLenght; s <= maxKeyLenght; ++s)
		{
			if (i - s < 0 || s > resolvingWord.size())
				break;

			string prefix = resolvingWord.substr(0, i - s);
			string suffix = resolvingWord.substr(i - s, s);
			
			// cout << "(" << prefix << "|" << suffix << ")" << endl;

			wordIt = dictionary.find(suffix);
			if (wordIt != dictionaryEnd)
			{
				if (prefix == "")
				{
					Solution tmp = { 0, new string[0] };
					addWordToSolution((wordIt->second), &tmp);

					it = resolvation.find(suffix);
					if (it == resolvation.end())
					{
						resolvation.insert(pair<string, Solution>(suffix, tmp));
						// cout << "resolvation insert: " << suffix << " : ";
						// printSolutionDebug(resolvation[suffix], true);
					}
					else
					{
						if ((it->second).answerSize + 1 > tmp.answerSize)
						{
							// cout << "resolvation(" << it->first << ") change: ";
							// printSolutionDebug(it->second);
							it->second = tmp;
							// cout << " with ";
							// printSolutionDebug(it->second, true);
						}
					}
				}
				else
				{
					it = resolvation.find(prefix);
					if (it != resolvation.end())
					{
						Solution tmp = it->second;
						// cout << "Solution for prefix is: ";
						// printSolutionDebug(tmp, true);
						addWordToSolution((wordIt->second), &tmp);

						it = resolvation.find(resolvingWord);
						if (it != resolvation.end())
						{
							if ((it->second).answerSize + 1 > tmp.answerSize)
							{
								// cout << "change resolvation(" << resolvingWord << ") from ";
								// printSolutionDebug(it->second);
								// cout << " to ";
								it->second = tmp;
								// printSolutionDebug(it->second);
							}
						}
						else
						{
							resolvation.insert(pair<string, Solution>(resolvingWord, tmp));
							// cout << "resolvation(" << resolvingWord << ") insert: ";
							// printSolutionDebug(resolvation[resolvingWord], true);
						}
					}
				}
			}
		}
	}

	it = resolvation.find(number);
	if (it == resolvation.end())
	{
		Solution answer = { 0, new string[0] };
		return answer;
	}
	else
	{
		return it->second;
	}
}


void printSolution(string number, map<string, string> dictionary, int dictionarySize)
{
	// cout << endl << endl;
	// for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	// 	cout << (it->second) << " ";
	// cout << endl;
	// for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	// 	cout << (it->first) << " ";
	// cout << endl;

	Solution sol = findSolution(number, dictionary, dictionarySize);

	if (sol.answerSize == 0)
		cout << noSolution;
	else
		printSolution(sol);
}

int main()
{
	bool needEndl = false;
	string number;
	do{
		cin >> number;
		if (number == "-1")
			break;

		int dictionarySize;
		cin >> dictionarySize;
		map<string, string> dictionary;
		for (int i = 0; i < dictionarySize; ++i)
		{
			string word;
			cin >> word;
			dictionary.insert(pair<string, string>(convertWord(word), word));
		}
		if (needEndl)
			cout << endl;
		printSolution(number, dictionary, dictionarySize);
		needEndl = true;
	} while (true);
	return 0;
}