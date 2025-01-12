/*
Examples:
----------
Input: arr[] = [3, 0, 1, 0, 4, 0 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.

Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.

Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides.

Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9
Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        int leftmax = 0, rightmax = 0, maxheight = height[0], index = 0;

        // Find the index of the highest bar
        for(int i = 1; i < n; i++) {
            if(maxheight < height[i]) {
                maxheight = height[i];
                index = i;
            }
        }

        // Calculate water trapped to the left of the highest bar
        for(int i = 0; i < index; i++) {
            if(leftmax > height[i])
                water += leftmax - height[i];
            else 
                leftmax = height[i];
        }

        // Calculate water trapped to the right of the highest bar
        for(int i = n - 1; i > index; i--) {
            if(rightmax > height[i])
                water += rightmax - height[i];
            else 
                rightmax = height[i];
        }
        
        return water;
    }
};

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the bars: ";
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution solution;
    int result = solution.trap(height);

    cout << "The amount of trapped water is: " << result << endl;
    return 0;
}
