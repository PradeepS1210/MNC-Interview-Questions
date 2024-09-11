#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(std::vector<long long> &arr)
    {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(arr.begin(), arr.end());

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
    int n;
    std::cout << "Enter the number of ropes: ";
    std::cin >> n;

    std::vector<long long> arr(n);
    std::cout << "Enter the lengths of the ropes: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    Solution sol;
    long long result = sol.minCost(arr);
    std::cout << "The minimum cost to connect all the ropes is: " << result << std::endl;

    return 0;
}
