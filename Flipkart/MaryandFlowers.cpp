#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, t;
    cin >> N >> t;

    vector<int> flowers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> flowers[i];
    }

    int left = 0, right = N - 1;
    while (left < right)
    {
        int sum = flowers[left] + flowers[right];
        if (sum == t)
        {
            cout << left << " " << right << endl;
            return 0;
        }
        else if (sum < t)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return 0;
}
