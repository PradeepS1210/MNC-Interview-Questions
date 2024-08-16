/*
Example:
===========
Input:
Enter the number of days: 7
Enter the stock prices: 100 80 60 70 60 75 85

Output: Stock spans for the given prices are: 1 1 1 2 1 4 6

Explanation:
Traversing the given input span
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6.
Hence the output will be 1 1 1 2 1 4 6.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> span(n);

        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && price[st.top()] <= price[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                span[i] = i + 1;
            }
            else
            {
                span[i] = i - st.top();
            }

            st.push(i);
        }

        return span;
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of days: ";
    cin >> n;

    int price[n];

    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    vector<int> result = sol.calculateSpan(price, n);

    cout << "Stock spans for the given prices are: ";
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
