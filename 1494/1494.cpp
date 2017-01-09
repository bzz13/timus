#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


int main()
{
    int count;
    bool wasCheat = false;

    cin >> count;
    vector<int> nums(count, 0);
    for (int i = 0; i < count; ++i)
    {
        cin >> nums[i];
    }
    if (count == 1)
    {
        cout << "Not a proof" << endl;
        return 0;
    }

    int stored = 0;
    stack<int> st;

    for (auto num: nums)
    {
        if (num > stored)
        {
            for (int i = stored + 1; i < num; ++i)
            {
                st.push(i);
            }
            stored = num;
        }
        else
        {
            if (num == st.top())
            {
                st.pop();
            }
            else
            {
                wasCheat = true;
                break;
            }
        }
    }


    cout << (wasCheat ? "Cheater" : "Not a proof") << endl;
    return 0;
}