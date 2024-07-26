#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }

        long long int low = 1, high = x / 2, ans;

        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            long long int midSquared = mid * mid;

            if (midSquared == x)
            {
                return mid;
            }
            else if (midSquared < x)
            {
                low = mid + 1;
                ans = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    long long int x;

    cout << "Enter an integer: ";
    cin >> x;

    cout << "Floor of the square root of " << x << " is " << sol.floorSqrt(x) << endl;

    return 0;
}
