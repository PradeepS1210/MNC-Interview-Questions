/*
Example:
===========
Input:
Enter the number of elements in the array: 6
Enter the elements of the array: 5 20 3 2 5 80
Enter the absolute difference x: 78

Output: There exists a pair with absolute difference 78.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPair(int n, int x, std::vector<int> &arr)
    {
        std::sort(arr.begin(), arr.end());

        int left = 0, right = 1;
        while (right < n)
        {
            int diff = arr[right] - arr[left];
            if (diff == x)
            {
                return 1;
            }
            else if (diff < x)
            {
                right++;
            }
            else
            {
                left++;
                if (left == right)
                {
                    right++;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n, x;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter the absolute difference x: ";
    std::cin >> x;

    Solution solution;
    int result = solution.findPair(n, x, arr);
    if (result == 1)
    {
        std::cout << "There exists a pair with absolute difference " << x << "." << std::endl;
    }
    else
    {
        std::cout << "No such pair exists with absolute difference " << x << "." << std::endl;
    }

    return 0;
}
