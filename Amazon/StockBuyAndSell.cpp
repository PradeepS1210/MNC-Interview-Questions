/*
Example 1:
============
Input:
Enter the number of days: 7
Enter the stock prices for each day: 100 180 260 310 40 535 695

Output:
Buy and sell days:
(0 3) (4 6)

Explanation:
One possible solution is (0 3) (4 6) We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit. Now, we buy stock on day 4 and sell it on day 6.

Example 2:
============
Input:
Enter the number of days: 5
Enter the stock prices for each day: 4 2 2 2 4

Output:
Buy and sell days:
(3 4)

Explanation:
There are multiple possible solutions. one of them is (3 4) We can buy stock on day 3, and sell it on 4th day, which will give us maximum profit.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> result;

        if (n == 1)
            return result;

        int i = 0;
        while (i < n - 1)
        {
            while ((i < n - 1) && (A[i + 1] <= A[i]))
            {
                i++;
            }

            if (i == n - 1)
                break;

            int buy = i++;

            while ((i < n) && (A[i] >= A[i - 1]))
            {
                i++;
            }

            int sell = i - 1;

            result.push_back({buy, sell});
        }

        return result;
    }
};

int main()
{
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.stockBuySell(A, n);

    if (result.empty())
    {
        cout << "No Profit" << endl;
    }
    else
    {
        cout << "Buy and sell days: " << endl;
        for (const auto &pair : result)
        {
            cout << "(" << pair[0] << " " << pair[1] << ") ";
        }
        cout << endl;
    }

    return 0;
}
