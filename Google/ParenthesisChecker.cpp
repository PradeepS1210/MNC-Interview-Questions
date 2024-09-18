/*
Example 1:
==========
Enter a string of brackets: {[()]}
Balanced

Example 2:
==========
Enter a string of brackets: {(])
Not Balanced
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> st;

        for (char ch : x)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
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

    cout << "Enter a string of brackets: ";
    cin >> input;

    if (sol.ispar(input))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
