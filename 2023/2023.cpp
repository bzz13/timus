#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

std::map<string, int> box;

int main()
{
	box[""] =
	box["Alice"] = box["Ariel"] = box["Aurora"] = 
	box["Phil"] = box["Peter"] = box["Olaf"] = 
	box["Phoebus"] = box["Ralph"] = box["Robin"] = 1;

	box["Bambi"] = box["Belle"] = box["Bolt"] = 
	box["Mulan"] = box["Mowgli"] = box["Mickey"] = 
	box["Silver"] = box["Simba"] = box["Stitch"] = 2;

	box["Dumbo"] = box["Genie"] = box["Jiminy"] = 
	box["Kuzko"] = box["Kida"] = box["Kenai"] = 
	box["Tarzan"] = box["Tiana"] = box["Winnie"] = 3;


	int count, result = 0;
	string previousName = "", tmpName;
	cin >> count;
	while(count --> 0)
	{
		cin >> tmpName;
		result += abs(box[tmpName] - box[previousName]);
		previousName = tmpName;
	}
	cout << result;
}