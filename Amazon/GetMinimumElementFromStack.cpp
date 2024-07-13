/*
Example:
=========
Input:
push 2
push 3
pop
getMin
push 1
getMin
pop
getMin

Output:
3
2
1
2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int minEle;
    stack<int> s;
    stack<int> minStack;

public:
    int getMin()
    {
        if (minStack.empty())
        {
            return -1;
        }
        return minStack.top();
    }

    int pop()
    {
        if (s.empty())
        {
            return -1;
        }
        int topElement = s.top();
        s.pop();
        if (topElement == minStack.top())
        {
            minStack.pop();
        }
        return topElement;
    }

    void push(int x)
    {
        s.push(x);
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }
};

int main()
{
    Solution sol;
    string operation;
    int value;

    while (cin >> operation)
    {
        if (operation == "push")
        {
            cin >> value;
            sol.push(value);
        }
        else if (operation == "pop")
        {
            cout << sol.pop() << endl;
        }
        else if (operation == "getMin")
        {
            cout << sol.getMin() << endl;
        }
    }

    return 0;
}
