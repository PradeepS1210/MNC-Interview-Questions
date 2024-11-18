#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;
    if (d == 0) return;
    
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n, d;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the number of rotations (d): ";
    cin >> d;

    rotateArray(arr, d);

    cout << "Array after " << d << " rotations: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
