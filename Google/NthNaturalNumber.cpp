/*
Example:
===========
Input:
Enter the value of n: 8

Output: The 8th number after removing numbers containing '9' is: 8
Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findNth(long long n)
    {
        long long result = 0;
        long long base = 1;

        while (n > 0)
        {
            result += (n % 9) * base;
            n /= 9;
            base *= 10;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    long long n;

    cout << "Enter the value of n: ";
    cin >> n;

    long long nthNumber = solution.findNth(n);
    cout << "The " << n << "th number after removing numbers containing '9' is: " << nthNumber << endl;

    return 0;
}
