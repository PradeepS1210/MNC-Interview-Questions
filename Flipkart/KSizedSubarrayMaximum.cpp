/*
Example:
==========
Input:
Enter the size of the array: 9
Enter the elements of the array: 1 2 3 1 4 5 2 3 6
Enter the size of the subarray (k): 3

Output: Maximums of each subarray of size 3: 3 3 4 5 5 5 6

Explanation:
1st contiguous subarray = [1 2 3] max = 3
2nd contiguous subarray = [2 3 1] max = 3
3rd contiguous subarray = [3 1 4] max = 4
4th contiguous subarray = [1 4 5] max = 5
5th contiguous subarray = [4 5 2] max = 5
6th contiguous subarray = [5 2 3] max = 5
7th contiguous subarray = [2 3 6] max = 6
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> max_of_subarrays(int k, vector<int> &arr)
    {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < arr.size(); ++i)
        {

            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the size of the subarray (k): ";
    cin >> k;

    Solution sol;

    vector<int> result = sol.max_of_subarrays(k, arr);

    cout << "Maximums of each subarray of size " << k << ": ";
    for (int max_val : result)
    {
        cout << max_val << " ";
    }
    cout << endl;

    return 0;
}
