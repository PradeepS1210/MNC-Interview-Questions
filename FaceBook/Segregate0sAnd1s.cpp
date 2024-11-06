/*
Examples :
============
Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].

Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int start = 0, end = arr.size() - 1;
        
        while (start < end) {
            if (arr[start] == 0)
                start++;
            else {
                if (arr[end] == 0) {
                    swap(arr[start], arr[end]);
                    start++;
                    end--;
                } else {
                    end--;
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements (0s and 1s only): ";
    
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;

        while (element != 0 && element != 1) {
            cout << "Invalid input. Please enter 0 or 1: ";
            cin >> element;
        }
        
        arr[i] = element;
    }
    
    Solution solution;
    solution.segregate0and1(arr);
    
    cout << "Array after segregation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
