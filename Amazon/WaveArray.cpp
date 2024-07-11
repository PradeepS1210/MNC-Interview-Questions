/*
Example:
==========
Input:
Enter the size of the array: 5
Enter the elements of the array: 1 2 3 4 5

Output: Array elements after converting to wave-like array:  2 1 4 3 5
Explanation: Array elements after sorting it in the waveform are 2 1 4 3 5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void convertToWave(int n, vector<int> &arr)
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    sol.convertToWave(n, arr);

    cout << "Array elements after converting to wave-like array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
