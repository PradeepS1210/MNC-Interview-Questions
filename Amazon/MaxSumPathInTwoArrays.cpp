#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;

        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                sum1 += arr1[i++];
            }
            else if (arr1[i] > arr2[j])
            {
                sum2 += arr2[j++];
            }
            else
            {
                result += max(sum1, sum2) + arr1[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }

        while (i < n1)
            sum1 += arr1[i++];
        while (j < n2)
            sum2 += arr2[j++];

        result += max(sum1, sum2);

        return result;
    }
};

int main()
{
    int n1, n2;
    cout << "Enter the size of the first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of the first array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of the second array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    Solution solution;
    int result = solution.maxPathSum(arr1, arr2);
    cout << "Maximum path sum: " << result << endl;

    return 0;
}
