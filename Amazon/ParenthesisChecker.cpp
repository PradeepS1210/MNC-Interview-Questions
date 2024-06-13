/*
Example 1:
============
Input: {([])}
Output: true
Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.

Example 2:
============
Input: ()
Output: true
Explanation: (). Same bracket can form balanced pairs, and here only 1 type of bracket is present and in balanced way.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> st;

        for (char c : x)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution sol;
    string input;

    cout << "Enter a string with brackets: ";
    cin >> input;

    if (sol.ispar(input))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not balanced" << endl;
    }

    return 0;
}
