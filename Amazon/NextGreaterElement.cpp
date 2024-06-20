/*
Example 1:
============
Input:
N = 4, arr[] = [1 3 2 4]
Output: 3 4 4 -1
Explanation: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist, it is -1.

Example 2:
============
Input:
N = 5, arr[] [6 8 0 1 3]
Output: 8 -1 1 3 -1
Explanation: In the array, the next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> result(n, -1);
        stack<long long> s;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                result[i] = s.top();
            }
            s.push(arr[i]);
        }
        return result;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<long long> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    vector<long long> result = sol.nextLargerElement(arr, n);

    cout << "The next greater elements are: ";
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
