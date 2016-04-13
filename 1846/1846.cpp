#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

int gcdr(int a, int b)
{
	return a == 0 ? b : gcdr(b % a, a);
}

struct Node
{
	Node(const int& v, Node* p = NULL) : Value(v), GCD(v)
	{
		next = NULL;
		prev = p;
		if (prev)
			GCD = gcdr(v, prev->GCD);
	}

	int Value;
	int GCD;
	Node * next, *prev;
};

class Store
{
	void RecalcGCD(Node * node)
	{
		Node * tmp = node;
		while (tmp->next)
		{
			int v = gcdr(tmp->GCD, tmp->next->Value);
			if (v != tmp->next->GCD)
			{
				tmp->next->GCD = v;
				tmp = tmp->next;
			}
			else
				break;
		}
	}

	map<int, vector<Node*> > Map;

	void AddToMap(const int& v, Node* n)
	{
		map<int, vector<Node*> >::iterator it = Map.find(v);
		if (it != Map.end())
			it->second.push_back(n);
		else
			Map.insert(pair<int, vector<Node*> >(v, vector<Node*>(1, n)));
	}

	Node* FindInMap(const int& v)
	{
		map<int, vector<Node*> >::iterator it = Map.find(v);
		return it != Map.end() && it->second.size() ? it->second.back() : NULL;
	}

	void removeFromMap(const int& v)
	{
		map<int, vector<Node*> >::iterator it = Map.find(v);
		if (it != Map.end() && it->second.size())
			it->second.pop_back();
	}

public:
	Store()
	{
		head = tail = NULL;
	};

	~Store()
	{
		Node *tmp = head, *n;
		while (tmp)
		{
			n = tmp->next;
			delete tmp;
			tmp = n;
		}
		Map.clear();
	};

	Node * head, *tail;

	void Add(const int& v)
	{
		Node * n = new Node(v, tail);
		if (tail)
		{
			tail->next = n;
			tail->next->GCD = gcdr(tail->GCD, v);
			tail = tail->next;
		}
		else
		{
			head = tail = n;
		}
		AddToMap(v, n);
	}

	void Remove(const int& v)
	{
		Node * tmp = FindInMap(v);
		if (!tmp) return;
		removeFromMap(v);

		if (head == tail)
		{
			head = tail = NULL;
			delete tmp;
			return;
		}

		if (tmp == head)
		{
			head = head->next;
			delete tmp;
			head->GCD = head->Value;
			RecalcGCD(head);
		}
		else
		{
			if (tmp == tail)
			{
				tail = tail->prev;
				tail->next = NULL;
				delete tmp;
			}
			else
			{
				Node * n = tmp->next, *p = tmp->prev;
				delete tmp;
				p->next = n;
				n->prev = p;
				RecalcGCD(p);
			}
		}
	}

	const void Traverse()
	{
		Node* tmp = head;
		while (tmp)
		{
			cout << "{ v: " << tmp->Value << ", gcd: " << tmp->GCD << " } -> ";
			tmp = tmp->next;
		}
		cout << "NULL" << endl;
	}

	const int GetGCD()
	{
		return tail ? tail->GCD : 1;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	// freopen("output.txt", "wt", stdout);
#endif
	int count, operand;
	char operation;
	Store s = Store();

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cin >> operation >> operand;
		switch (operation)
		{
		case '+':
			s.Add(operand);
			cout << s.GetGCD() << endl;
			break;
		case '-':
			s.Remove(operand);
			cout << s.GetGCD() << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}