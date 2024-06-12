/*
Example:
==========
Input: N = 5
A[] = {3,1,3,3,2}
Output: 3
Explanation: Since, 3 is present more than N/2 times, so it is the majority element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        int candidate = findCandidate(a, size);
        if (isMajority(a, size, candidate))
        {
            return candidate;
        }
        else
        {
            return -1;
        }
    }

private:
    int findCandidate(int a[], int size)
    {
        int count = 0, candidate = -1;

        for (int i = 0; i < size; i++)
        {
            if (count == 0)
            {
                candidate = a[i];
                count = 1;
            }
            else if (a[i] == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }

    bool isMajority(int a[], int size, int candidate)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == candidate)
            {
                count++;
            }
        }
        return count > size / 2;
    }
};

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    int *A = new int[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    Solution sol;
    int result = sol.majorityElement(A, N);

    if (result != -1)
    {
        cout << "The majority element is: " << result << endl;
    }
    else
    {
        cout << "There is no majority element in the array." << endl;
    }

    delete[] A;
    return 0;
}
