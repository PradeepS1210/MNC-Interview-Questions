/*
Example 1:
-----------
Input
3 2
10 11 12

Output
6765

Explanation
The replaced array after the 1st step will be {10,10,10}.
There would be two partitions {10, 10} and {10} with the sum 20 and 10, respectively.
20 is smaller than 100, so the 20th Fibonacci number will be 6765.
Hence 6765 will be the peculiar number as per the given condition.

Example 2:
-----------
Input
4 2
5 8 6 10

Output
144

Explanation
Replace each element in the array with the absolute difference between the element and its index, resulting in [5, 7, 4, 7].

Partition the array into 2 parts, minimizing the maximum sum, which gives a maximum sum of 12.

Since 12 is less than 100, the 12th Fibonacci number 144 is returned as the peculiar number.
*/

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

bool canPartition(vector<int>& arr, int K, int mid) {
    int count = 1, sum = 0;
    for (int num : arr) {
        if (sum + num > mid) {
            count++;
            sum = num;
            if (count > K) return false;
        } else {
            sum += num;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        arr[i] = abs(arr[i] - i);
    }

    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPartition(arr, K, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (result < 100) {
        cout << fibonacci(result) << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
