/*
Example:
===========
Input: Enter a string: ABC

Output: Unique permutations in lexicographical order: ABC ACB BAC BCA CAB CBA

Explanation: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        vector<string> result;
        string current = "";
        vector<bool> used(S.length(), false);

        sort(S.begin(), S.end());

        generatePermutations(S, current, used, result);

        return result;
    }

private:
    void generatePermutations(const string &S, string &current, vector<bool> &used, vector<string> &result)
    {
        if (current.length() == S.length())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < S.length(); ++i)
        {
            if (used[i] || (i > 0 && S[i] == S[i - 1] && !used[i - 1]))
            {
                continue;
            }

            current.push_back(S[i]);
            used[i] = true;

            generatePermutations(S, current, used, result);

            used[i] = false;
            current.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    vector<string> permutations = sol.find_permutation(input);

    cout << "Unique permutations in lexicographical order:" << endl;
    for (const string &perm : permutations)
    {
        cout << perm << " ";
    }
    cout << endl;

    return 0;
}
