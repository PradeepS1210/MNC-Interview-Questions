#include <bits/stdc++.h>
using namespace std;

int countUniqueBSTs(int N)
{
    if (N == 0)
        return 1;
    if (N == 1)
        return 1;

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    return dp[N];
}

int main()
{
    int N;
    cin >> N;
    cout << countUniqueBSTs(N) << endl;
    return 0;
}