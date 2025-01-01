/*
Examples:
----------
Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.

Input: arr[] = ["no", "on", "is"]
Output: [["is"], ["no", "on"]]
Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.

Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
Output: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
Explanation: 
Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& word : arr) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            anagramGroups[sortedWord].push_back(word);
        }
        
        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input;
    string word;
    
    cout << "Enter words (type 'end' to stop):" << endl;
    
    while (true) {
        cin >> word;
        if (word == "end") {
            break;
        }
        input.push_back(word);
    }
    
    vector<vector<string>> result = solution.anagrams(input);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
