#include <iostream>
#include <string>
using namespace std;

const string few = "few";
const string several = "several";
const string pack = "pack";
const string lots = "lots";
const string horde = "horde";
const string throng = "throng";
const string swarm = "swarm";
const string zounds = "zounds";
const string legion = "legion";

string translate(int count)
{
	if (count >= 1000)
		return legion;
	if (count >= 500) 
		return zounds;
	if (count >= 250) 
		return swarm;
	if (count >= 100)
		return throng;
	if (count >= 50) 
		return horde;
	if (count >= 20) 
		return lots;
	if (count >= 10)
		return pack;
	if (count >= 5) 
		return several;
	if (count >= 1) 
		return few;

	return "undef";
}

int main()
{
	int count;
	cin >> count;
	cout << translate(count);
}