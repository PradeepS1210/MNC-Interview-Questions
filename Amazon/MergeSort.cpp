/*
Example:
=========
Input:
Enter the number of elements: 5
Enter the elements of the array: 4 1 3 9 7

Output Sorted array: 1 3 4 7 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int left[n1], right[n2];

        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];

        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
};

int main()
{
    Solution sol;
    int N;

    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sol.mergeSort(arr, 0, N - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
