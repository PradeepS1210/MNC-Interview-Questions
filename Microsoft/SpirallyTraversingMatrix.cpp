/*
Input:
-------------------------------
Enter the number of rows: 3
Enter the number of columns: 4
Enter the elements of the matrix row by row:
1 2 3 4
5 6 7 8
9 10 11 12

Output:
-------------------------------
Spiral order of the matrix:
1 2 3 4 8 12 11 10 9 5 6 7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> result;
        int n = mat.size();
        int m = mat[0].size();
        
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                result.push_back(mat[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;
    
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix row by row:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    Solution sol;
    vector<int> result = sol.spirallyTraverse(mat);
    cout << "Spiral traversal of the matrix: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
