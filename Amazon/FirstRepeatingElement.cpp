/*
Example 1:
===========
Input:
Enter the number of elements in the array: 7
Enter the elements of the array: 1 5 3 4 3 5 6

Output: Position of first repeating element (1-based index): 2

Example 2:
===========
Input:
Enter the number of elements in the array: 4
Enter the elements of the array: 1 2 3 4

Output: No repeating element found.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstRepeated(vector<int> &arr)
    {
        unordered_map<int, int> firstIndex;
        int minIndex = numeric_limits<int>::max();

        for (int i = 0; i < arr.size(); ++i)
        {
            if (firstIndex.find(arr[i]) != firstIndex.end())
            {
                minIndex = min(minIndex, firstIndex[arr[i]]);
            }
            else
            {
                firstIndex[arr[i]] = i + 1;
            }
        }

        return (minIndex == numeric_limits<int>::max()) ? -1 : minIndex;
    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int result = sol.firstRepeated(arr);

    if (result == -1)
    {
        cout << "No repeating element found.\n";
    }
    else
    {
        cout << "Position of first repeating element (1-based index): " << result << endl;
    }

    return 0;
}
