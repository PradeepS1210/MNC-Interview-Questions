/*
Example 1:
============
Input: Enter an IPv4 address: 222.111.111.111
Output: The IPv4 address is valid.

Example 2:
============
Input: Enter an IPv4 address: 256.100.100.100
Output: The IPv4 address is not valid.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(string s)
    {
        int dotCount = 0;
        for (char c : s)
        {
            if (c == '.')
                dotCount++;
        }

        if (dotCount != 3)
            return 0;

        stringstream ss(s);
        string segment;
        while (getline(ss, segment, '.'))
        {
            if (segment.empty())
                return 0;

            if (segment.size() > 1 && segment[0] == '0')
                return 0;

            for (char c : segment)
            {
                if (!isdigit(c))
                    return 0;
            }

            int num = stoi(segment);
            if (num < 0 || num > 255)
                return 0;
        }

        return 1;
    }
};

int main()
{
    Solution sol;
    string ipAddress;

    cout << "Enter an IPv4 address: ";
    cin >> ipAddress;

    int result = sol.isValid(ipAddress);
    if (result == 1)
    {
        cout << "The IPv4 address is valid." << endl;
    }
    else
    {
        cout << "The IPv4 address is not valid." << endl;
    }

    return 0;
}
