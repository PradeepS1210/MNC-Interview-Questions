/*
Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.

Input: prices[] = [7, 6, 4, 3, 1]
Output: 0 
Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.

Input: prices[] = [1, 3, 6, 9, 11]
Output: 10 
Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].
*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main() {
    cout << "Enter the number of days (size of the array): ";
    int n;
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the prices of the stock on " << n << " days: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maximumProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}


