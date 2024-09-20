#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBuildings(vector<int> &height)
    {
        int count = 0;
        int maxHeight = 0;

        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] > maxHeight)
            {
                count++;
                maxHeight = height[i];
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cout << "Enter the number of buildings: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the buildings: ";
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    Solution sol;
    int result = sol.countBuildings(height);

    cout << "Number of buildings that can see sunlight: " << result << endl;

    return 0;
}
