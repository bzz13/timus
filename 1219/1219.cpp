#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main()
{
	int i=1;
	srand((unsigned)time(0));
	char random_integer;
	while(i<=1000000)
	{
		random_integer = (rand() % 'z') + 1;
		if(random_integer >= 'a' && random_integer <= 'z')
		{
			cout << random_integer;
			i++;
		}
	}
	cout<<endl;
	return 0;
}