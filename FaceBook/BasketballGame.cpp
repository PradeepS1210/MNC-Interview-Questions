/*
Example 1:
------------
Input
8
1 2 + C D 8 D +

Output
55

Explanation
- Aniket records 1: [1]
- Aniket records 2: [1, 2]
- Aniket records the sum of the last two scores (1 + 2): [1, 2, 3]
- Aniket invalidates the previous score: [1, 2]
- Aniket records double the previous score (2 * 2): [1, 2, 4]
- Aniket records 8: [1, 2, 4, 8]
- Aniket records double the previous score (8 * 2): [1, 2, 4, 8, 16]
- Aniket records the sum of the last two scores (8 + 16): [1, 2, 4, 8, 16, 24]

Total score: 1 + 2 + 4 + 8 + 16 + 24 = 55

Example 2:
------------
Input
7
3 4 + D C D +

Output
49

Explanation
- Aniket records 3: [3]
- Aniket records 4: [3, 4]
- Aniket records the sum of the last two scores (3 + 4): [3, 4, 7]
- Aniket records double the previous score (7 * 2): [3, 4, 7, 14]
- Aniket invalidates the previous score: [3, 4, 7]
- Aniket records double the previous score (7 * 2): [3, 4, 7, 14]
- Aniket records the sum of the last two scores (7 + 14): [3, 4, 7, 14, 21]

Total score: 3 + 4 + 7 + 14 + 21 = 49
*/

#include <bits/stdc++.h>
using namespace std;

int calculateScore(int n, vector<string>& ops) {
    vector<int> scores;

    for (const string& op : ops) {
        if (op == "+") {
            int last = scores.back();
            int secondLast = scores[scores.size() - 2];
            scores.push_back(last + secondLast);
        } else if (op == "D") {
            scores.push_back(2 * scores.back());
        } else if (op == "C") {
            scores.pop_back();
        } else {
            scores.push_back(stoi(op));
        }
    }

    int totalScore = 0;
    for (int score : scores) {
        totalScore += score;
    }

    return totalScore;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> ops(n);
    for (int i = 0; i < n; ++i) {
        cin >> ops[i];
    }

    int result = calculateScore(n, ops);
    cout << result << endl;

    return 0;
}
