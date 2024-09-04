#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    int N;
    cin >> N;

    int totalSetBits = 0;

    for (int i = 1; i <= N; ++i)
    {
        totalSetBits += countSetBits(i);
    }

    cout << totalSetBits << endl;

    return 0;
}