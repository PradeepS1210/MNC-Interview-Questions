/*
Examples:
-----------
Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].

Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if (arr.empty()) return {};
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> merged;
        vector<int> current = arr[0];
        
        for (const auto& interval : arr) {
            if (interval[0] <= current[1]) {
                current[1] = max(current[1], interval[1]);
            } else {
                merged.push_back(current);
                current = interval;
            }
        }
        
        merged.push_back(current);
        
        return merged;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    
    cout << "Enter intervals (start end):\n";
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    
    vector<vector<int>> result = solution.mergeOverlap(intervals);

    cout << "Merged intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
