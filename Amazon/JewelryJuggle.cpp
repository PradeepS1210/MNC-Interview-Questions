/*
Example 1:
-----------
Input
10 10 10 100

Output
NO

Explanation
No combination of pieces selected will satisfy the condition where the weights of selected pieces are equal to the weights of pieces remaining.
So, print “NO”.

Example 2:
-----------
Input
1 5 8 4

Output
YES

Explanation
Lena selects jewelry: 
A with weight 1
C with weight 8

Remaining jewelry pieces are:
B with weight 5
D with weight 4

Sum of pieces Lena selected = 1+8 =9
Sum of pieces remaining= 5+4 = 9

Thus, such a combination exists where the sum of the pieces Lena has selected is equal to the sum of remaining pieces.

So, print “YES”.
*/

#include <iostream>
using namespace std;

bool canBalance(int A, int B, int C, int D) {
    int weights[] = {A, B, C, D};
    int total_sum = A + B + C + D;
    
    for (int i = 1; i < 16; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                sum += weights[j];
            }
        }
        if (sum == total_sum - sum) {
            return true;
        }
    }
    return false;
}

int main() {
    int A, B, C, D;
    cout << "Enter the weights of the jewelry pieces (A, B, C, D): ";
    cin >> A >> B >> C >> D;

    if (canBalance(A, B, C, D)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
