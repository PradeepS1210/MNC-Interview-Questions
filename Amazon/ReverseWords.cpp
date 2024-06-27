/*
Example:
==========
Enter a string with words separated by dots: i.like.this.program.very.much
Reversed string: much.very.program.this.like.i
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    std::string reverseWords(std::string S)
    {
        std::vector<std::string> words;
        std::string word;
        std::istringstream stream(S);

        while (std::getline(stream, word, '.'))
        {
            words.push_back(word);
        }

        std::reverse(words.begin(), words.end());

        std::string reversed;
        for (size_t i = 0; i < words.size(); ++i)
        {
            reversed += words[i];
            if (i != words.size() - 1)
            {
                reversed += '.';
            }
        }

        return reversed;
    }
};

int main()
{
    Solution sol;
    std::string input;

    std::cout << "Enter a string with words separated by dots: ";
    std::getline(std::cin, input);

    std::string output = sol.reverseWords(input);
    std::cout << "Reversed string: " << output << std::endl;

    return 0;
}
