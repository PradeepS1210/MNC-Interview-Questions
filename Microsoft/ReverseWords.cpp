#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string str)
    {
        vector<string> words;
        string word = "";

        for (char c : str)
        {
            if (c == '.')
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += c;
            }
        }

        if (!word.empty())
        {
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        string result = "";
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i != words.size() - 1)
            {
                result += ".";
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string input;

    cout << "Enter a string with words separated by dots: ";
    cin >> input;

    string result = sol.reverseWords(input);

    cout << "Reversed string: " << result << endl;

    return 0;
}
