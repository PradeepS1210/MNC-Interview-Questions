/*
Examples:
----------------------------------------------------
Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210. Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.

Input: prices[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2. Maximum Profit = 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }

        return maxProfit;
    }
};

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of days must be greater than 0." << endl;
        return 0;
    }

    vector<int> prices(n);
    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution sol;
    int result = sol.maximumProfit(prices);

    cout << "The maximum profit is: " << result << endl;

    return 0;
}
