#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
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
void printArray(int arr[], int size, bool printEndl = false)
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
	int size;
	string *words;
};

void debugPrint(int dp[], int ind[], string path[], int count)
{
	printArray(dp, count, true);
	printArray(ind, count, true);
	printArray(path, count, true);
	cout<<endl;	
}

void printSolution(Solution sol)
{
	for (int i = 0; i < sol.size - 1; ++i)
		cout << sol.words[i] << ' ';
	cout << sol.words[sol.size - 1];
}


Solution findSolution(string number, map<string, string> dictionary, int dictionarySize)
{
	int count = number.size();
	int *dp = new int[count];
	int *ind = new int[count];
	string *path = new string[count];
	
	//initial
	{
		for (int i = 0; i < count; ++i)
		{
			dp[i] = -1;
			ind[i] = -1;
			path[i] = "~";
		}
		for (std::map<string, string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
		{
			string word = i->first;
			int wordSize = word.size();
			if (number.substr(0, wordSize) == word)
			{
				dp[wordSize - 1] = 1;
				ind[wordSize - 1] = 0;
				path[wordSize - 1] = i->second;
			}
		}
		debugPrint(dp, ind, path, count);
	}

	for (int i = 0; i < count; ++i)
	{
		string word = number.substr(0, i);
		for (int j = 0; j < i; ++j)
		{
			if (dp[j] > 0)
			{
				string word_ji = number.substr(j + 1, i - j);
				std::map<string, string>::iterator position = dictionary.find(word_ji);
				if (position != dictionary.end())
				{
					if (dp[j] + 1 < (dp[i] == -1 ? 9999999 : dp[i]) )
					{
						dp[i] = dp[j] + 1;
						ind[i] = j;
						path[i] = position->second;

						debugPrint(dp, ind, path, count);
					}
				}
			}
		}
	}

	Solution solution = { dp[count - 1] };

	// conclusion
	{
		if (solution.size != -1)
		{
			string *answer = new string[solution.size];
			int prev = count - 1;
			for (int i = solution.size - 1; i >= 0; --i)
			{
				// cout << "w(" << path[prev] << ") p(" << ind[prev] << ")" << endl;  
				answer[i] = path[prev];
				prev = ind[prev];
			}
			solution.words = answer;
		}
	}

	delete[] path;
	delete[] ind;
	delete[] dp;

	return solution;
}


void printSolution(string number, map<string, string> dictionary, int dictionarySize)
{
	Solution sol = findSolution(number, dictionary, dictionarySize);

	if (sol.size == -1)
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