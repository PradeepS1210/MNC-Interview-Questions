/*
Example 1:
------------
Input
2

Output
0 1 1

Explanation
Decimal       Binary Representation
0 ------------->0
1 ------------->1
2 ------------->10

Example 2:
------------
Input
5

Output
0 1 1 2 1 2

Explanation
Decimal       Binary Representation
0 ------------->0
1 ------------->1
2 ------------->10
3------------->11
4------------->100
5------------->101
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int N) {
    vector<int> result(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> result = countBits(N);
    for (int i = 0; i <= N; ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
