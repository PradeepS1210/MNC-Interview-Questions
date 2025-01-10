/*
Examples:
----------
Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output:  [3, 4, 4, 3]
Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.

Input: arr[] = [4, 1, 1], k = 2
Output: [2, 1]
Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2. 
Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1. 

Input: arr[] = [1, 1, 1, 1, 1], k = 3
Output: [1, 1, 1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> result;
        unordered_map<int, int> freq;
        int distinctCount = 0;

        for (int i = 0; i < k; i++) {
            if (freq[arr[i]] == 0) {
                distinctCount++;
            }
            freq[arr[i]]++;
        }
        result.push_back(distinctCount);

        for (int i = k; i < arr.size(); i++) {
            if (freq[arr[i - k]] == 1) {
                distinctCount--;
            }
            freq[arr[i - k]]--;

            if (freq[arr[i]] == 0) {
                distinctCount++;
            }
            freq[arr[i]]++;
            
            result.push_back(distinctCount);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int n, k;
    
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    arr.resize(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the window size: ";
    cin >> k;

    vector<int> result = sol.countDistinct(arr, k);

    cout << "Count of distinct elements in each window: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
