#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrime(int N)
    {
        if (N <= 1)
            return 0;
        if (N <= 3)
            return 1;

        if (N % 2 == 0 || N % 3 == 0)
            return 0;

        for (int i = 5; i * i <= N; i += 6)
        {
            if (N % i == 0 || N % (i + 2) == 0)
                return 0;
        }

        return 1;
    }
};

int main()
{
    Solution solution;
    int N;
    cout << "Enter a number: ";
    cin >> N;
    int result = solution.isPrime(N);
    if (result == 1)
    {
        cout << N << " is a prime number." << endl;
    }
    else
    {
        cout << N << " is not a prime number." << endl;
    }
    return 0;
}
