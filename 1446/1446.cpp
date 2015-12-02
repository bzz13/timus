#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

const string Slytherin = "Slytherin";
const string Hufflepuff = "Hufflepuff";
const string Gryffindor = "Gryffindor";
const string Ravenclaw = "Ravenclaw";

int main()
{
	int count;
	cin >> count;
	string studentName, facultyName;
	std::map<string, std::vector<string> > raspr;
	std::map<string, std::vector<string> >::iterator find;
	std::vector<string>::iterator i;

	getline(cin, studentName);
	for (int i = 0; i < count; ++i)
	{
		getline(cin, studentName);
		getline(cin, facultyName);

		find = raspr.find(facultyName);
		if (find == raspr.end())
		{
			std::vector<string> fac(1, studentName);
			raspr[facultyName] = fac;
		}
		else
			raspr[facultyName].push_back(studentName);
	}

	cout << Slytherin<<":"<<endl;
	for ( i = raspr[Slytherin].begin(); 
		  i != raspr[Slytherin].end(); 
		  ++i)
	{
		cout << *i << endl;
	}
	cout << endl;
	cout << Hufflepuff<<":"<<endl;
	for ( i = raspr[Hufflepuff].begin(); 
		  i != raspr[Hufflepuff].end(); 
		  ++i)
	{
		cout << *i << endl;
	}
	cout << endl;
	cout << Gryffindor<<":"<<endl;
	for ( i = raspr[Gryffindor].begin(); 
		  i != raspr[Gryffindor].end(); 
		  ++i)
	{
		cout << *i << endl;
	}
	cout << endl;
	cout << Ravenclaw<<":"<<endl;
	for ( i = raspr[Ravenclaw].begin(); 
		  i != raspr[Ravenclaw].end(); 
		  ++i)
	{
		cout << *i << endl;
	}

	return 0;
}