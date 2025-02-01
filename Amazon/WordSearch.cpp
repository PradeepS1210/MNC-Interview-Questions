/*
Example 1:
-----------
Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: true

Example 2:
-----------
Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: false

Example 3:
-----------
Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
Output: true
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) return false;
        
        char temp = mat[i][j];
        mat[i][j] = '*';
        
        bool found = dfs(mat, word, i-1, j, index+1) || dfs(mat, word, i+1, j, index+1) || 
                     dfs(mat, word, i, j-1, index+1) || dfs(mat, word, i, j+1, index+1);
        
        mat[i][j] = temp;
        return found;
    }
    
public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    
    vector<vector<char>> mat(n, vector<char>(m));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    
    string word;
    cout << "Enter the word to search: ";
    cin >> word;
    
    Solution sol;
    bool result = sol.isWordExist(mat, word);
    
    if (result) {
        cout << "The word \"" << word << "\" exists in the matrix." << endl;
    } else {
        cout << "The word \"" << word << "\" does not exist in the matrix." << endl;
    }
    
    return 0;
}
