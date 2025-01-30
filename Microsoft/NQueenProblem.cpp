/*
Examples:
----------
Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.

Input: n = 4
Output: [[2 4 1 3 ] [3 1 4 2 ]]
Explaination: There are 2 possible solutions for n = 4.

Input: n = 2
Output: []
Explaination: There are no possible solutions for n = 2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> results;

    void solve(int n, int row, vector<int>& placement) {
        if (row == n) {
            results.push_back(placement);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(placement, row, col)) {
                placement[row] = col + 1;
                solve(n, row + 1, placement);
                placement[row] = 0;
            }
        }
    }

    bool isValid(const vector<int>& placement, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (placement[i] == col + 1 || 
                abs(placement[i] - (col + 1)) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<int>> nQueen(int n) {
        results.clear();
        vector<int> placement(n, 0);
        solve(n, 0, placement);
        return results;
    }
};

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    Solution solution;
    vector<vector<int>> solutions = solution.nQueen(n);

    if (solutions.empty()) {
        cout << "No solutions found for n = " << n << endl;
    } else {
        cout << "Solutions for n = " << n << ":" << endl;
        for (const auto& solution : solutions) {
            for (int pos : solution) {
                cout << pos << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
