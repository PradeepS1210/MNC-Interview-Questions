/*
Example 1:
============
Input: N = 5,
arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
============
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already
sorted so there is no inversion count.
*/

#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversions = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right)
{
    long long inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(arr, temp, left, mid);
        inversions += mergeSortAndCount(arr, temp, mid + 1, right);
        inversions += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversions;
}

long long countInversions(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main()
{
    int N;
    cout << "Enter the size of array N: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter " << N << " integers for the array:\n";
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    long long inversionCount = countInversions(arr);
    cout << "Inversion count is: " << inversionCount << endl;

    return 0;
}
