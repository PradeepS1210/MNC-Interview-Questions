/*
Examples:
-------------
Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16.

Input: arr[] = [1, 2, 4, 3, 6], target = 11
Output: false
Explanation: None of the pair makes a sum of 11.
*/

#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (numMap.find(complement) != numMap.end()) {
            return true;
        }
        numMap[arr[i]] = i; 
    }
    return false;
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    if (twoSum(arr, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
