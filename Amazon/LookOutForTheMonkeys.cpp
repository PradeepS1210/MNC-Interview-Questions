#include <bits/stdc++.h>
using namespace std;

vector<int> countVisibleMonkeys(vector<int> &heights)
{
    int n = heights.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && heights[i] > heights[s.top()])
        {
            result[i]++;
            s.pop();
        }
        if (!s.empty())
        {
            result[i]++;
        }
        s.push(i);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<int> result = countVisibleMonkeys(heights);

    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}