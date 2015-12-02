#include <iostream>
using namespace std;


int main()
{
	int n10, n50, n100, n500, n1000, n5000;
	cin >> n10 >> n50 >> n100 >> n500 >> n1000 >> n5000;
	int price;
	cin >> price;

	int sum = n10*10 + n50*50 + n100*100 + n500*500 + n1000*1000 + n5000*5000;
	int maxCount = sum / price;
	int minCount = 0;
	
	if (n10 != 0)
		minCount = (sum - 10) / price + 1;
	else
		if (n50 != 0)
			minCount = (sum - 50) / price + 1;
		else
			if (n100 != 0)
				minCount = (sum - 100) / price + 1;
			else
				if (n500 != 0)
					minCount = (sum - 500) / price + 1;
				else
					if (n1000 != 0)
						minCount = (sum - 1000) / price + 1;
					else								
						if (n5000 != 0)
							minCount = (sum - 5000) / price + 1;

	cout << maxCount - minCount + 1 << endl;
	for (int i = minCount; i <= maxCount; ++i)
	{
		if (i != minCount)
			cout << " ";
		cout << i;
	}

}