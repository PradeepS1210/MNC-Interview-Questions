#include <bits/stdc++.h>
using namespace std;

bool matches(const unordered_map<char, int> &count1, const unordered_map<char, int> &count2)
{
    if (count1.size() != count2.size())
        return false;
    for (const auto &pair : count1)
    {
        if (count2.find(pair.first) == count2.end() || count2.at(pair.first) != pair.second)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    if (lenB > lenA)
    {
        cout << "Empty Array" << endl;
        return 0;
    }

    unordered_map<char, int> countB;
    for (char c : B)
    {
        countB[c]++;
    }

    unordered_map<char, int> countWindow;
    vector<int> result;

    for (int i = 0; i < lenB; i++)
    {
        countWindow[A[i]]++;
    }

    if (matches(countWindow, countB))
    {
        result.push_back(0);
    }

    for (int i = lenB; i < lenA; i++)
    {
        countWindow[A[i]]++;

        char oldChar = A[i - lenB];
        if (countWindow[oldChar] == 1)
        {
            countWindow.erase(oldChar);
        }
        else
        {
            countWindow[oldChar]--;
        }

        if (matches(countWindow, countB))
        {
            result.push_back(i - lenB + 1);
        }
    }

    if (result.empty())
    {
        cout << "Empty Array" << endl;
    }
    else
    {
        for (int index : result)
        {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
