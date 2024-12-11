/*
Examples:
----------
Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10

Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 5 10 12 18 20.

Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = ceil((double)(n + m) / 2);

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < n) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
                i++;
                j++;
            }

            j = j - n;
            while (i < n && j < m) {
                if (a[i] > b[j]) {
                    swap(a[i], b[j]);
                }
                i++;
                j++;
            }

            i = 0;
            while (j < m) {
                if (b[i] > b[j]) {
                    swap(b[i], b[j]);
                }
                i++;
                j++;
            }

            if (gap == 1) {
                gap = 0;
            } else {
                gap = ceil((double)gap / 2);
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter size of array a: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of array a: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter size of array b: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of array b: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    Solution sol;
    sol.mergeArrays(a, b);

    cout << "Array a after merging: ";
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Array b after merging: ";
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
