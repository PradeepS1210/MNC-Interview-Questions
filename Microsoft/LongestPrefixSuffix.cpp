#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lps(string str)
    {
        int n = str.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps[n - 1];
    }
};

int main()
{
    Solution solution;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    int result = solution.lps(str);
    cout << "Length of the longest proper prefix which is also a suffix: " << result << endl;

    return 0;
}
