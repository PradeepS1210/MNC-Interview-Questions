#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> window;

        for (int i = 0; i < arr.size(); i++) {
            if (window.find(arr[i]) != window.end()) {
                return true;
            }
            
            window.insert(arr[i]);

            if (i >= k) {
                window.erase(arr[i - k]);
            }
        }

        return false;
    }
};

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    bool result = solution.checkDuplicatesWithinK(arr, k);

    if (result) {
        cout << "True: The array contains duplicates within " << k << " distance.\n";
    } else {
        cout << "False: The array does not contain duplicates within " << k << " distance.\n";
    }

    return 0;
}
