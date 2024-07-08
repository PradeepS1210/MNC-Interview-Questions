/*
Example:
==========
Input:
Enter the number of rows: 4
Enter the number of columns: 4
Enter the matrix elements (0s and 1s):
0 1 1 1
0 0 1 1
1 1 1 1
0 0 0 0

Output: The index of the first row with the maximum number of 1s is: 2

Explanation:
Row 0 has 3 ones.
Row 1 has 2 ones.
Row 2 has 4 ones (maximum).
Row 3 has 0 ones.
So, the row with the maximum number of 1s is row 2 (0-based index).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int max_row_index = -1;
        int j = m - 1;

        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && arr[i][j] == 1)
            {
                j--;
                max_row_index = i;
            }
        }
        return max_row_index;
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    cout << "Enter the matrix elements (0s and 1s):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solution sol;
    int result = sol.rowWithMax1s(arr, n, m);
    if (result != -1)
    {
        cout << "The index of the first row with the maximum number of 1s is: " << result << endl;
    }
    else
    {
        cout << "No row with 1s found." << endl;
    }

    return 0;
}
