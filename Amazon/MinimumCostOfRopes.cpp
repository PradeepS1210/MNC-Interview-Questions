/*
Example:
=============
Input:
Enter the number of ropes: 4
Enter the lengths of the ropes: 4 3 2 6

Output: Minimum cost to connect all ropes: 29

Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array {4, 5, 6}. Cost of this operation 2+3 = 5.
2) Now connect ropes of lengths 4 and 5. Which makes the array {9, 6}. Cost of this operation 4+5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9+6 =15

Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes.
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2). Finally we connect 13 and 2.
Total cost in this way is 10 + 13 + 15 = 38.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for (long long i = 0; i < n; ++i)
        {
            minHeap.push(arr[i]);
        }

        long long totalCost = 0;

        while (minHeap.size() > 1)
        {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();

            long long cost = first + second;
            totalCost += cost;

            minHeap.push(cost);
        }

        return totalCost;
    }
};

int main()
{
    long long n;
    cout << "Enter the number of ropes: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the lengths of the ropes: ";
    for (long long i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    long long result = sol.minCost(arr, n);

    cout << "Minimum cost to connect all ropes: " << result << endl;

    return 0;
}
