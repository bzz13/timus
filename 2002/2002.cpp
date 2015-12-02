#include <iostream>
#include <string>
#include <map>
using namespace std;

string RegisterUser(map<string, string> *users, map<string, bool> *usersState, string name, string pass)
{
	std::map<string, string>::iterator it = users->find(name);
	if (it == users->end())
	{
		(*users)[name] = pass;
		(*usersState)[name] = false;
		return "success: new user added";
	}
	return "fail: user already exists";
}

string LoginUser(map<string, string> *users, map<string, bool> *usersState, string name, string pass)
{
	std::map<string, string>::iterator it = users->find(name);
	if (it == users->end())
	{
		return "fail: no such user";
	}
	if (it->second != pass)
		return "fail: incorrect password";
	if ((*usersState)[name])
		return "fail: already logged in";
	(*usersState)[name] = true;
	return "success: user logged in";
}


string LogoutUser(map<string, string> *users, map<string, bool> *usersState, string name)
{
	std::map<string, string>::iterator it = users->find(name);
	if (it == users->end())
	{
		return "fail: no such user";
	}
	if (!((*usersState)[name]))
		return "fail: already logged out";
	(*usersState)[name] = false;
	return "success: user logged out";
}

int main()
{
	int count;
	cin >> count;
	string command, arg1, arg2;
	map<string, string> users;
	map<string, bool> usersState;

	for (int i = 0; i < count; ++i)
	{
		cin >> command;
		if (command == "register")
		{
			cin >> arg1 >> arg2;
			cout << RegisterUser(&users, &usersState, arg1, arg2) << endl;
		}
		else 
		{
			if (command == "login")
			{
				cin >> arg1 >> arg2;
				cout << LoginUser(&users, &usersState, arg1, arg2) << endl;
			}
			else
			{
				if (command == "logout")
				{
					cin >> arg1;
					cout << LogoutUser(&users, &usersState, arg1) << endl;
				}
			}
		}
	}
}