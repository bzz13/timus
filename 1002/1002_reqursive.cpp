#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const string noSolution = "No solution.";

void printArray(string arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
		cout << arr[i] << ' ';
	cout << arr[size - 1];
}

string convertWord(string word)
{
	std::ostringstream stm;
	for ( std::string::iterator it = word.begin(); it != word.end(); ++it)
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

string* convertDictionary(string origin[], int originSize)
{
	string *dictionary = new string[originSize];
	for (int i = 0; i < originSize; ++i)
		dictionary[i] = convertWord(origin[i]);
	return dictionary;
}

string* orderDictionaryByWordLength(string origin[], int originSize)
{
	string *dictionary = new string[originSize];
	for (int i = 0; i < originSize; ++i)
		dictionary[i] = origin[i];

	string tmp;
	bool flag = true;
	for (int i = 1; (i < originSize) && flag; ++i)
	{
		flag = false;
		for (int j = 0; j < (originSize - 1); ++j)
		{
			if (dictionary[j+1].length() > dictionary[j].length())
			{
				tmp = dictionary[j];
				dictionary[j] = dictionary[j+1];
				dictionary[j+1] = tmp;
				flag = true;
			}
		}
	}

	return dictionary;
}

struct solution
{
	int answerSize;
	string *answer;
};

void addWordToSolution(string word, solution *solution)
{
	solution->answerSize ++;
	string *newAnswer = new string[solution->answerSize];
	newAnswer[0] = word;
	for (int i = 1; i < solution->answerSize; ++i)
		newAnswer[i] = solution->answer[i - 1];
	string *old = solution->answer;
	solution->answer = newAnswer;
	delete[] old;
}

void printSolution(solution sol)
{
	printArray(sol.answer, sol.answerSize);
}

solution findSolution(string number, string words[], string cnvWords[], int dictionarySize, int currentPosition)
{
	solution solutions[10000];
	int solutionsCount = 0;

	int endPosiotion = number.length();
	bool flag = true;

	for (int i = 0; i < dictionarySize; ++i)
	{
		int findSize = cnvWords[i].size();
		int found = number.find(cnvWords[i].c_str(), currentPosition, findSize);
		if (found == currentPosition)
		{
			size_t newPosition = currentPosition + cnvWords[i].size();
			solution tmp;
			if (newPosition == endPosiotion)
			{	
				tmp.answerSize = 0;
				tmp.answer = new string[0];
				addWordToSolution(words[i], &tmp);
				return tmp;
			}
			tmp = findSolution(number, words, cnvWords, dictionarySize, newPosition);
			if (tmp.answerSize == 0)
				continue;
			addWordToSolution(words[i], &tmp);
			solutions[solutionsCount] = tmp;
			solutionsCount ++;
		}
	}

	int min = 99999999;
	solution answer;
	answer.answerSize = 0;
	answer.answer = new string[0];

	for (int i = 0; i < solutionsCount; ++i)
	{
		// printSolution(solutions[i]);
		if (solutions[i].answerSize < min)
		{
			min = solutions[i].answerSize;
			answer = solutions[i];
		}
	}

	return answer;
}

void printSolution(string number, string dictionary[], int dictionarySize)
{
	string *orderedDictionary = orderDictionaryByWordLength(dictionary, dictionarySize);
	string *convertedDictionary = convertDictionary(orderedDictionary, dictionarySize);

	// cout << endl << endl;
	// printArray(orderedDictionary, dictionarySize);
	// printArray(convertedDictionary, dictionarySize);

	solution sol = findSolution(number, orderedDictionary, convertedDictionary, dictionarySize, 0);
	
	if (sol.answerSize == 0)
		cout << noSolution;
	else
		printSolution(sol);	

	delete[] convertedDictionary;
	delete[] orderedDictionary;
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
		string *dictionary = new string[dictionarySize];
		for (int i = 0; i < dictionarySize; ++i)
			cin >> dictionary[i];
		if (needEndl)
			cout << endl;
		printSolution(number, dictionary, dictionarySize);
		needEndl = true;
		delete[] dictionary;	
	}
	while(true);
}