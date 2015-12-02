#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
	int value;
	Node *left, *right;
	Node(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}

	~Node()
	{
		if (left != NULL)
			delete left;
		if (right != NULL)
			delete right;
	}

	void printLeftToRight()
	{
		if (left != NULL)
			left->printLeftToRight();
		if (right != NULL)
			right->printLeftToRight();
		cout << " " << value;
	}
	void printRightToLeft()
	{
		if (right != NULL)
			right->printRightToLeft();
		if (left != NULL)
			left->printRightToLeft();
		cout << value << endl;
	}

	void InsertNewNode(int v)
	{
		if (v < value)
		{
			if (left != NULL)
				left->InsertNewNode(v);
			else
				left = new Node(v);
		}
		else
		{
			if (right != NULL)
				right->InsertNewNode(v);
			else
				right = new Node(v);
		}
	}

	Node* backInsert(int v)
	{
		Node *node = new Node(v);
		if (v > value)
		{
			node->left = this;
		}
		else
		{
			Node *parent = this, *tmp = left;
			while (tmp != NULL && tmp->value > v)
			{
				parent = tmp;
				tmp = tmp->left;
			}
			node->left = tmp;
			if (node != this)
				parent->left = NULL;
			node->right = this;
		}
		return node;
	}
};

int main()
{
	int count, tmp;
	cin >> count;

	cin >> tmp;
	Node *root = new Node(tmp);

	while (count--> 1)
	{
		cin >> tmp;
		// root->InsertNewNode(tmp);

		root = root->backInsert(tmp);
	}

	// root->printLeftToRight();
	// cout << endl;
	root->printRightToLeft();

	delete root;
}