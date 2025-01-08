/*
Examples:
----------
Input: arr[] = [4, 6, 3, 7]
Output: 3
Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.  

Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6
Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]

Input: arr[] = [1, 2, 3]
Output: 0
Explanation: No triangles are possible.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int count = 0;

        for (int i = n-1; i >= 2; i--) {
            int left = 0, right = i-1;
            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
                    count += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.countTriangles(arr);
    cout << "Number of possible triangles: " << result << endl;

    return 0;
}
