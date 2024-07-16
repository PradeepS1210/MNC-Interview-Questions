/*
Example:
==========
Input:
Enter the number of elements in the array: 9
Enter the elements of the array: 34 8 10 3 2 80 30 33 1

Output: The maximum index difference is: 6

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIndexDiff(std::vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        std::vector<int> LMin(n);
        LMin[0] = arr[0];
        for (int i = 1; i < n; ++i)
        {
            LMin[i] = std::min(arr[i], LMin[i - 1]);
        }

        std::vector<int> RMax(n);
        RMax[n - 1] = arr[n - 1];
        for (int j = n - 2; j >= 0; --j)
        {
            RMax[j] = std::max(arr[j], RMax[j + 1]);
        }

        int i = 0, j = 0, maxDiff = -1;
        while (j < n && i < n)
        {
            if (LMin[i] <= RMax[j])
            {
                maxDiff = std::max(maxDiff, j - i);
                ++j;
            }
            else
            {
                ++i;
            }
        }

        return maxDiff;
    }
};

int main()
{
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    Solution solution;
    int result = solution.maxIndexDiff(arr);
    std::cout << "The maximum index difference is: " << result << std::endl;

    return 0;
}
