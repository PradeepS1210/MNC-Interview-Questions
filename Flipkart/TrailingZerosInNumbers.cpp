/*
Example 1:
-----------
Input
3 4
4 2 3

Output
0

Explanation
Calculate the factorial of the numbers:
4! = 24
2! = 2
3! = 6
There is no trailing zeroes.

Example 2:
-----------
Input
8 15
1 2 3 4 5 6 10 15

Output
7

Explanation
Calculate the factorial of the numbers
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120 (1 trailing zero)
6! = 720 (1 trailing zero)
10! = 3628800 (2 trailing zeroes)
15! = 1307674368000 (3 trailing zeroes)
Sum of trailing zeroes = 7.
*/

#include <iostream>
#include <vector>
using namespace std;

int trailingZeros(int num) {
    int count = 0;
    for (int i = 5; num / i >= 1; i *= 5) {
        count += num / i;
    }
    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    int totalTrailingZeros = 0;
    
    for (int i = 0; i < N; ++i) {
        if (arr[i] <= M) {
            totalTrailingZeros += trailingZeros(arr[i]);
        }
    }
    
    cout << totalTrailingZeros << endl;
    
    return 0;
}
