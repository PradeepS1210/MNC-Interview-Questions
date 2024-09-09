#include <bits/stdc++.h>
using namespace std;

int findSmallestMaxSplitIndex(const string &S)
{
    int N = S.length();
    if (N == 0)
        return -1;

    vector<int> leftDistinct(N);
    vector<int> rightDistinct(N);

    unordered_set<char> distinctLeft;
    for (int i = 0; i < N; ++i)
    {
        distinctLeft.insert(S[i]);
        leftDistinct[i] = distinctLeft.size();
    }

    unordered_set<char> distinctRight;
    for (int i = N - 1; i >= 0; --i)
    {
        distinctRight.insert(S[i]);
        rightDistinct[i] = distinctRight.size();
    }

    int maxSum = -1;
    int minIndex = -1;
    for (int i = 0; i < N - 1; ++i)
    {
        int currentSum = leftDistinct[i] + rightDistinct[i + 1];
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            minIndex = i;
        }
    }

    return minIndex;
}

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    int result = findSmallestMaxSplitIndex(S);

    cout << result << endl;

    return 0;
}
