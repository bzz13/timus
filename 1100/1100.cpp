#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Result
{
	int index;
	int id;
	int solved;
};

bool vectorSortFunc(const Result &a, const Result &b)
{
	if (a.solved == b.solved)
		return a.index < b.index;
	return a.solved > b.solved;
}

void printAnswer(std::vector<Result> v)
{
	for (std::vector<Result>::iterator it = v.begin(); it != v.end(); ++it)
		printf("%d %d\n", it->id, it->solved);
}

int main()
{
	int count;
	scanf("%d", &count);

	Result dflt;	
	std::vector<Result> resultVector(count, dflt);

	for (int i = 0; i < count; ++i)
	{
		Result tmp = {i, -1, -1};
		scanf("%d%d", &(tmp.id), &(tmp.solved));
		resultVector[i] = tmp;
	}

	std::sort (resultVector.begin(), resultVector.end(), vectorSortFunc); 
	printAnswer(resultVector);
}