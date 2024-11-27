/*
Examples:
----------------------
Input: n = 1234
Output: 1
Explanation: Step 1: 1 + 2 + 3 + 4 = 10. Step 2: 1 + 0 = 1

Input: n = 5674
Output: 4
Explanation: Step 1: 5 + 6 + 7 + 4 = 22. Step 2: 2 + 2 = 4

Input: n = 9
Output: 9
Explanation: Since 9 is a single-digit number hence we return 9.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int singleDigit(int n) {
        if (n == 0) return 0;
        return 1 + (n - 1) % 9;
    }
};

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1) {
        cout << "Input must be a positive integer!" << endl;
        return 1; // Exit with error code
    }

    Solution sol;
    int result = sol.singleDigit(n);
    cout << "The single digit obtained is: " << result << endl;

    return 0;
}
