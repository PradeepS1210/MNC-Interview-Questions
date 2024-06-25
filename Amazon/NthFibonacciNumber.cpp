/*
Examples:
==========

Enter the value of n: 2
The 2nd Fibonacci number is: 1

Enter the value of n: 5
The 5th Fibonacci number is: 5

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthFibonacci(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        const int MOD = 1000000007;
        vector<int> fib(n + 1);
        fib[1] = 1;
        fib[2] = 1;

        for (int i = 3; i <= n; ++i)
        {
            fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        }

        return fib[n];
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = solution.nthFibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;

    return 0;
}
