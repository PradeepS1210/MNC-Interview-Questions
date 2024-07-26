#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isRotated(string str1, string str2)
    {
        if (str1.length() != str2.length())
        {
            return false;
        }

        string clock_rot = "";
        string anti_clock_rot = "";
        int len = str2.length();

        clock_rot = clock_rot + str2[len - 2] + str2[len - 1] + str2.substr(0, len - 2);

        anti_clock_rot = anti_clock_rot + str2.substr(2) + str2[0] + str2[1];

        return (str1 == clock_rot || str1 == anti_clock_rot);
    }
};

int main()
{
    Solution sol;
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    if (sol.isRotated(str1, str2))
    {
        cout << "The second string can be obtained by rotating the first string by exactly 2 places." << endl;
    }
    else
    {
        cout << "The second string cannot be obtained by rotating the first string by exactly 2 places." << endl;
    }

    return 0;
}
