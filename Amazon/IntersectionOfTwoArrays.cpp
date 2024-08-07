/*
Example:
==========
Input:
Enter the size of the first array: 5
Enter elements of the first array: 89 24 75 11 23
Enter the size of the second array: 3
Enter elements of the second array: 89 2 4

Output: Number of elements in the intersection: 1
Explanation: 89 is the only element in the intersection of two arrays.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        unordered_set<int> elements;

        for (int i = 0; i < n; ++i)
        {
            elements.insert(a[i]);
        }

        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            if (elements.find(b[i]) != elements.end())
            {
                count++;
                elements.erase(b[i]);
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;

    int n, m;

    cout << "Enter the size of the first array: ";
    cin >> n;

    int *a = new int[n];

    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> m;

    int *b = new int[m];

    cout << "Enter elements of the second array: ";
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    int result = solution.NumberofElementsInIntersection(a, b, n, m);

    cout << "Number of elements in the intersection: " << result << endl;

    delete[] a;
    delete[] b;

    return 0;
}
