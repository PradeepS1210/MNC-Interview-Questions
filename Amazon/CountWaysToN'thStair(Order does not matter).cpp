/*
Examples:
===========
Input: n = 4
Output: 3
Explanation: Three ways to reach at 4th stair. They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.

Input: n = 5
Output: 3
Explanation: Three ways to reach at 5th stair. They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and {1, 2, 2}.
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int nthStair(int n)
    {
        return (n / 2) + 1;
    }
};

int main()
{
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    Solution sol;
    int result = sol.nthStair(n);

    cout << "The number of distinct ways to reach the " << n << "th stair is: " << result << endl;

    return 0;
}
