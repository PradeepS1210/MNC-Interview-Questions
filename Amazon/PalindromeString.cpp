/*

Example 1:
Input: Enter a string: abba
Output: The string is a palindrome

Example 2:
Input: Enter a string: abc
Output: The string is not a palindrome

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPalindrome(string S)
    {
        int left = 0;
        int right = S.length() - 1;

        while (left < right)
        {
            if (S[left] != S[right])
            {
                return 0;
            }
            left++;
            right--;
        }

        return 1;
    }
};

int main()
{
    Solution solution;
    string S;

    cout << "Enter a string: ";
    cin >> S;

    int result = solution.isPalindrome(S);

    if (result == 1)
    {
        cout << "The string is a palindrome" << endl;
    }
    else
    {
        cout << "The string is not a palindrome" << endl;
    }

    return 0;
}
