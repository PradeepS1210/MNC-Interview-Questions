/*
Example
==========

Input:
Enter the number of trains: 3
Enter the arrival times (in HHMM format): 0900 1100 1235
Enter the departure times (in HHMM format): 1000 1200 1240

Output: Minimum number of platforms required: 1

Explanation:
At 09:00, the first train arrives, so 1 platform is needed.
At 10:00, the first train departs, so 0 platforms are needed.
At 11:00, the second train arrives, so 1 platform is needed.
At 12:00, the second train departs, so 0 platforms are needed.
At 12:35, the third train arrives, so 1 platform is needed.
At 12:40, the third train departs, so 0 platforms are needed.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int platforms_needed = 1, max_platforms = 1;
        int i = 1, j = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms_needed++;
                i++;
            }
            else
            {
                platforms_needed--;
                j++;
            }
            if (platforms_needed > max_platforms)
            {
                max_platforms = platforms_needed;
            }
        }

        return max_platforms;
    }
};

int main()
{
    Solution sol;
    int n;

    cout << "Enter the number of trains: ";
    cin >> n;

    int arr[n], dep[n];

    cout << "Enter the arrival times (in HHMM format): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the departure times (in HHMM format): ";
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }

    int result = sol.findPlatform(arr, dep, n);
    cout << "Minimum number of platforms required: " << result << endl;

    return 0;
}
