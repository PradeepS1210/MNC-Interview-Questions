#include <bits/stdc++.h>
using namespace std;

bool canCrossRiver(const vector<int> &stones)
{
    int n = stones.size();
    int maxReach = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i > maxReach)
        {
            return false;
        }
        maxReach = max(maxReach, i + stones[i]);
        if (maxReach >= n - 1)
        {
            return true;
        }
    }
    return maxReach >= n - 1;
}

int main()
{
    int N;
    cin >> N;
    vector<int> stones(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> stones[i];
    }

    if (canCrossRiver(stones))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
