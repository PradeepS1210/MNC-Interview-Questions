/*
Example 1:
-----------
Input
. . . . . . . . 
. . . p . . . .
. . . R . . . p
. . . . . . . . 
. . . . . . . . 
. . . p . . . .
. . . . . . . . 
. . . . . . . p

Output
3

Example 2:
-----------
Input
. . . . . . . . 
. . . p . . . .
. . . R . . . p
. . . . . . . . 
. . . . . . . . 
. . . p . . . .
. . . . . . . . 
. . . . . . . . 

Output
3

Explanation: In this example, the rook is attacking all the pawns.
*/

#include <bits/stdc++.h>
using namespace std;

int numRookCaptures(vector<vector<char>>& board) {
    int rookRow, rookCol;
    // Find the rook's position
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                rookRow = i;
                rookCol = j;
                break;
            }
        }
    }
    
    int captures = 0;
    // North
    for (int i = rookRow - 1; i >= 0; i--) {
        if (board[i][rookCol] == 'B') break;
        if (board[i][rookCol] == 'p') {
            captures++;
            break;
        }
    }
    // South
    for (int i = rookRow + 1; i < 8; i++) {
        if (board[i][rookCol] == 'B') break;
        if (board[i][rookCol] == 'p') {
            captures++;
            break;
        }
    }
    // West
    for (int j = rookCol - 1; j >= 0; j--) {
        if (board[rookRow][j] == 'B') break;
        if (board[rookRow][j] == 'p') {
            captures++;
            break;
        }
    }
    // East
    for (int j = rookCol + 1; j < 8; j++) {
        if (board[rookRow][j] == 'B') break;
        if (board[rookRow][j] == 'p') {
            captures++;
            break;
        }
    }

    return captures;
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    cout << numRookCaptures(board) << endl;

    return 0;
}
