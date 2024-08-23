/*
Example:
=========
Input:
Enter the main string (s): GeeksForGeeks,
Enter the substring to search for (x): For

Output: The substring "for" is found at index:  5

Explanation: For is present as substring in GeeksForGeeks from index 5 (0 based indexing).
*/

#include <bits/stdc++.h>>
using namespace std;

int strstr(string s, string x)
{
    int n = s.length();
    int m = x.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (s[i + j] != x[j])
            {
                break;
            }
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s, x;
    cout << "Enter the main string (s): ";
    getline(cin, s);
    cout << "Enter the substring to search for (x): ";
    getline(cin, x);

    int index = strstr(s, x);
    if (index != -1)
    {
        cout << "The substring \"" << x << "\" is found at index: " << index << endl;
    }
    else
    {
        cout << "The substring \"" << x << "\" is not found in the string \"" << s << "\"" << endl;
    }

    return 0;
}
