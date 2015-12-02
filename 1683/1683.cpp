#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int length;
	cin >> length;
	vector<int> steps;
	while(length > 1)
	{
		steps.push_back(length / 2);
		length = length / 2 + length % 2;
	}
	cout << steps.size() << endl;
	for (std::vector<int>::iterator step = steps.begin(); step != steps.end(); ++step)
		cout << *step << ' ';
}