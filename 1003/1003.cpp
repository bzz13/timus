#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <queue>
using namespace std;


class Answer
{
public:
	int begin;
	int end;
	int value;

	bool operator ==(const Answer& answer)
	{
		return begin == answer.begin && end == answer.end && value == answer.value;
	}
};

const string evenString = "even";
const string oddString = "odd";

void printAnswer(const Answer& answer)
{

	printf("{ begin: %i, end: %i, value: %i }", answer.begin, answer.end, answer.value);
}

void debugPrintAnswers(Answer answers[], int count, bool needEndl = false)
{
	for (int i = 0; i < count; ++i)
	{
		printAnswer(answers[i]);
		cout << " ";
	}
	if (needEndl)
		cout << endl;
}

void debugPrintAnswers(list<Answer>* answers, bool needEndl = false)
{
	for (std::list<Answer>::iterator i = answers->begin(); i != answers->end(); ++i)
		printAnswer(*i);

	if (needEndl)
		cout << endl;
}

bool CanConstructCorrected(const Answer& answer, list<Answer> answers)
{
	list<bool> checking;
	for (std::list<Answer>::iterator i = answers.begin(); i != answers.end(); ++i)
	{
		Answer tmp = *i;
		if (tmp.begin == answer.begin)
		{
			if (tmp.end == answer.end)
				return tmp.value == answer.value;
			list<Answer> pretend(answers);
			pretend.remove(tmp);
			Answer next = { tmp.end + 1, answer.end, ((answer.value + tmp.value) % 2) };
			checking.push_back(CanConstructCorrected(next, pretend));
		}
	}

	for (std::list<bool>::iterator i = checking.begin(); i != checking.end(); ++i)
		if (!(*i))
			return false;
	return true;
}

bool FindItem(list<Answer> l, const Answer& item)
{
	bool result = false;
	for (std::list<Answer>::iterator it = l.begin(); it != l.end(); ++it)
	{
		if ((*it) == item)
		{
			result = true;
			break;
		}
	}
	return result;
}

list<Answer> Generate(list<Answer> answers, const Answer& answer)
{
	list<Answer> result;
	queue<Answer> queue;
	queue.push(answer);
	while (queue.size() > 0)
	{
		Answer tmp = queue.front();
		queue.pop();


		bool found = FindItem(answers, tmp) || FindItem(result, tmp);
		if (!found)
			result.push_back(tmp);

		for (std::list<Answer>::iterator it = answers.begin(); it != answers.end(); ++it)
		{
			Answer composed;
			if (it->end + 1 == tmp.begin)
			{
				composed.begin = it->begin;
				composed.end = tmp.end;
				composed.value = (it->value + tmp.value) % 2;
				queue.push(composed);
			}
			else
				if (tmp.end + 1 == it->begin)
				{
					composed.begin = it->begin;
					composed.end = tmp.end;
					composed.value = (it->value + tmp.value) % 2;
					queue.push(composed);
				}
		}
	}


	return result;
}

bool IsCorrect(const Answer& answer, list<Answer>* correctAnswers)
{
	list<Answer> pretend;
	for (std::list<Answer>::iterator it = correctAnswers->begin(); it != correctAnswers->end(); ++it)
	{
		if (it->begin == answer.begin && it->end == answer.end)
			return it->value == answer.value;
		if (it->begin >= answer.begin && it->end <= answer.end)
			pretend.push_back(*it);
	}

	if (CanConstructCorrected(answer, pretend))
	{

		// correctAnswers->push_back(answer);

		list<Answer> generated = Generate(*correctAnswers, answer);
		for (std::list<Answer>::iterator it = generated.begin(); it != generated.end(); ++it)
			correctAnswers->push_back(*it);

		// debugPrintAnswers(correctAnswers);
		// cout << endl << endl;

		return true;
	}
	else
		return false;
}

int findSolution(Answer answers[], int count)
{
	int incorrect = count;

	list<Answer> correctAnswers;

	for (int i = 0; i < count; ++i)
	{
		if (!IsCorrect(answers[i], &correctAnswers))
		{
			incorrect = i;
			break;
		}
	}

	return incorrect;
}

int main()
{
	int chainLength;
	int questionsCount;
	bool needEndl = false;
	do{
		cin >> chainLength;
		if (chainLength == -1)
			break;

		cin >> questionsCount;

		Answer *answers = new Answer[questionsCount];
		//reading
		{
			for (int i = 0; i < questionsCount; ++i)
			{
				Answer answer;
				string word;
				int begin, end;
				cin >> answer.begin >> answer.end >> word;
				answer.begin--;
				answer.end--;
				answer.value = word == evenString ? 0 : 1;
				answers[i] = answer;
			}
		}

		// debugPrintAnswers(answers, questionsCount);

		if (needEndl)
			cout << endl;
		cout << findSolution(answers, questionsCount);
		needEndl = true;

		delete[] answers;
	} while (true);
	return 0;
}