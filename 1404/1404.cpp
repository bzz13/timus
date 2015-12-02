#include <iostream>
#include <string>
using namespace std;

void printArray(int arr[], int count, bool asChar = true)
{
	for (int i = 0; i < count; ++i)
	{
		if (asChar)
			cout << (char)arr[i] << " ";
		else
			cout << arr[i] << " ";
	}
	cout << endl;
}

void printAnswerArray(int arr[], int count)
{
	for (int i = 0; i < count; ++i)
		cout << (char)arr[i];
}

int main()
{
	string encrypted, decrypted;
	cin >> encrypted;
	int count = encrypted.size();
	int *symbols = new int[count];

	for (int i = 0; i < count; ++i)
		symbols[i] = encrypted[i];
	// printArray(symbols, count);

	for (int i = 0; i < count; ++i)
		symbols[i] -= 'a';
	// printArray(symbols, count, false);

	for (int i = 0; i < count - 1; ++i)
		if (symbols[i] > symbols[i+1])
			for (int j = i+1; j < count; ++j)
				symbols[j] += 26;
	// printArray(symbols, count, false);

	for (int i = count - 1; i > 0; --i)
		symbols[i] = symbols[i] - symbols[i-1];
	if ((symbols[0] -= 5) < 0)
		symbols[0] += 26;
	// printArray(symbols, count, false);

	for (int i = 0; i < count; ++i)
		symbols[i] += 'a';
	// printArray(symbols, count);
	printAnswerArray(symbols, count);

	delete[] symbols;
}