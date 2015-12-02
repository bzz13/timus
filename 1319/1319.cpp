#include <iostream>
using namespace std;

int main()
{
	int count;
	cin >> count;
	
	int** mx = new int*[count];
	for (int i = 0; i < count; ++i)
	{
		mx[i] = new int[count];
		for (int j = 0; j < count; ++j)
			mx[i][j] = 0;
	}

	int current = 1;
	for (int i = 1; i <= count; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			mx[j][count - i + j] = current;
			current ++;
		}
	}
	for (int i = count - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			mx[count - i + j][j] = current;
			current++;
		}
	}



	for (int i = 0; i < count; ++i)
	{
		if (i) cout << endl;
		for (int j = 0; j < count; ++j)
			cout << mx[i][j] << " ";
	}


	for(int i = 0; i < count; ++i)
		delete [] mx[i];
	delete [] mx;
}