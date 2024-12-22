/*
Examples:
------------
Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
Output: false
Explanation: 62 is not present in the matrix, so output is false.

Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
Output: true
Explanation: 55 is present in the matrix.

Input: mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3
Output: true
Explanation: 3 is present in the matrix.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int i = 0, j = m - 1;
        
        while (i < n && j >= 0) {
            if (mat[i][j] == x) {
                return true;
            } else if (mat[i][j] > x) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};

int main() {
    int n, m, x;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter the number to search (x): ";
    cin >> x;

    Solution sol;
    if (sol.matSearch(mat, x)) {
        cout << "true" << endl; // x is found in the matrix
    } else {
        cout << "false" << endl; // x is not found in the matrix
    }

    return 0;
}
