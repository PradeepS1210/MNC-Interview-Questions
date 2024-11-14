/*
Example:
===========
Enter the number of elements in the array: 6
Enter the elements of the array: 6 5 3 2 8 10
Enter the value of k: 2
Sorted array: 2 3 5 6 8 10
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        vector<int> result;

        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

        for (int i = k + 1; i < arr.size(); i++) {
            result.push_back(minHeap.top());
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        arr = result;
    }
};


int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    solution.nearlySorted(arr, k);

    cout << "Sorted array: ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
