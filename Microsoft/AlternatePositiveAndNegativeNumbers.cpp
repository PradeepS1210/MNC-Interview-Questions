#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rearrange(vector<int> &arr)
    {
        vector<int> pos, neg;

        for (int num : arr)
        {
            if (num >= 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        int i = 0, p = 0, n = 0;
        bool turnPos = true;

        while (p < pos.size() && n < neg.size())
        {
            if (turnPos)
            {
                arr[i++] = pos[p++];
            }
            else
            {
                arr[i++] = neg[n++];
            }
            turnPos = !turnPos;
        }

        while (p < pos.size())
        {
            arr[i++] = pos[p++];
        }

        while (n < neg.size())
        {
            arr[i++] = neg[n++];
        }
    }
};

int main()
{
    Solution solution;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solution.rearrange(arr);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
