#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IntervalTree
{
	int power;
	int *nums;
	int length;
public:
	IntervalTree(const std::vector<int>& v)
	{
		int n = 0, pos, size = v.size();
		do
		{
			n++;
			size /= 2;
		} while (size > 0);

		power = n;
		length = 1 << n;
		nums = new int[2 * length];

		for (int i = 0; i < 2 * length; ++i)
			nums[i] = 0;
		for (int i = 0; i < v.size(); ++i)
			changeValueAt(i, v[i]);
	};
	~IntervalTree()
	{
		delete[] nums;
	};

	int findResultOnInterval(const int& left, const int& right)
	{
		return count(1, 0, length-1, left, right);
	}

	int count(const int& v, const int& L, const int& R, const int& l, const int& r)
	{
		if (L == l && R == r)
			return nums[v];
		int tm = (L + R) / 2;
		if (r <= tm)
			return count(2 * v, L, tm, l, r);
		if (l > tm)
			return count(2 * v + 1, tm + 1, R, l, r);

		int vl = count(2 * v, L, tm, l, tm);
		int vr = count(2 * v + 1, tm + 1, R, tm + 1, r);
		return f(vl, vr);
	}

	int f(const int& vl, const int & vr)
	{
		return max(vl, vr);
	}

	void changeValueAt(const int& index, const int& val)
	{
		if (index >= length)
			throw 1;
		int pos = length + index;
		nums[pos] = val;

		while (pos)
		{
			pos /= 2;
			nums[pos] = f(nums[2 * pos], nums[2 * pos + 1]);
		}
	}

	void print()
	{
		int tmp = 0;
		cout << endl;
		for (int i = 0; i <= power; ++i)
		{
			for (int j = 0; j < (1 << i); ++j)
			{
				tmp++;
				cout << nums[tmp] << ' ';
			}
			cout << endl;
		}
	}
};


int main()
{
	int M, N, tmp = 0;
	cin >> M;
	std::vector<int> measurement;
	while (true)
	{
		cin >> tmp;
		if (tmp == -1)
			break;
		measurement.push_back(tmp);
	}


	IntervalTree tree(measurement);
	//tree.print();
	for (int i = 0; i <= measurement.size() - M; i++)
		cout << tree.findResultOnInterval(i, i + M - 1) << endl;

	return 0;
}