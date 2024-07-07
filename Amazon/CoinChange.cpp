/*
Example 1:
============
Input:
Enter the number of coin types: 3
Enter the coin denominations: 1 2 3
Enter the target sum: 4

Output: Number of ways to make the sum 4 is: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.

Example 2:
============
Input:
Enter the number of coin types: 4
Enter the coin denominations: 2 5 3 6
Enter the target sum: 10

Output: Number of ways to make the sum 10 is: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {
        std::vector<long long int> dp(sum + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < N; ++i)
        {
            for (int j = coins[i]; j <= sum; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[sum];
    }
};

int main()
{
    int N, sum;

    std::cout << "Enter the number of coin types: ";
    std::cin >> N;

    int coins[N];
    std::cout << "Enter the coin denominations: ";
    for (int i = 0; i < N; ++i)
    {
        std::cin >> coins[i];
    }

    std::cout << "Enter the target sum: ";
    std::cin >> sum;

    Solution sol;
    long long int ways = sol.count(coins, N, sum);

    std::cout << "Number of ways to make the sum " << sum << " is: " << ways << std::endl;

    return 0;
}
