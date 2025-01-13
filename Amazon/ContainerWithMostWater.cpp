/*
Examples:
----------
Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: 5 and 3 are 2 distance apart. So the size of the base is 2. Height of container = min(5, 3) = 3. So, total area to hold water = 3 * 2 = 6.

Input: arr[] = [3, 1, 2, 4, 5]
Output: 12
Explanation: 5 and 3 are 4 distance apart. So the size of the base is 4. Height of container = min(5, 3) = 3. So, total area to hold water = 4 * 3 = 12.

Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
Output: 25 
Explanation: 8 and 5 are 5 distance apart. So the size of the base is 5. Height of container = min(8, 5) = 5. So, the total area to hold water = 5 * 5 = 25.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1, maxWater = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            maxWater = max(maxWater, height * width);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.maxWater(arr);
    cout << "The maximum amount of water that can be contained is: " << result << endl;

    return 0;
}
