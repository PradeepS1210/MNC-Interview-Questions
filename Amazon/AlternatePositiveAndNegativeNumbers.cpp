/*
Example:
==========
Enter the size of the array: 9
Enter the elements of the array: 9 4 -2 -1 5 0 -5 -3 2
Rearranged array: 9 -2 4 -1 5 -5 0 -3 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> pos, neg;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }

        int i = 0, j = 0, k = 0;

        while (i < pos.size() && j < neg.size())
        {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }

        while (i < pos.size())
        {
            arr[k++] = pos[i++];
        }

        while (j < neg.size())
        {
            arr[k++] = neg[j++];
        }
    }
};

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    sol.rearrange(arr, n);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
