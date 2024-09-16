#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(string str)
    {
        stack<int> s;
        s.push(-1);
        int maxLen = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
            }
            else
            {
                s.pop();
                if (s.empty())
                {
                    s.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - s.top());
                }
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    string str;

    cout << "Enter the string of parentheses: ";
    cin >> str;

    int result = solution.maxLength(str);
    cout << "The length of the longest valid parentheses substring is: " << result << endl;

    return 0;
}
