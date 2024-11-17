#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 4, 3, 2, 6, 5};
    sol.reverseArray(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
