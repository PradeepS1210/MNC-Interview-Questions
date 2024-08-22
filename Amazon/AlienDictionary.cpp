/*
Example:
===========
Enter the number of words (N): 5
Enter the number of characters in the language (K): 4
Enter the words in the dictionary:
baa
abcd
abca
cab
cad
The order of characters in the alien language is: bdac
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            for (int j = 0; j < min(word1.length(), word2.length()); j++)
            {
                if (word1[j] != word2[j])
                {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> inDegree(K, 0);

        for (int u = 0; u < K; u++)
        {
            for (int v : adj[u])
            {
                inDegree[v]++;
            }
        }

        // Queue for BFS
        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        string result;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result += (char)(u + 'a');

            for (int v : adj[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        if (result.length() != K)
            return "";

        return result;
    }
};

int main()
{
    int N, K;
    cout << "Enter the number of words (N): ";
    cin >> N;
    cout << "Enter the number of characters in the language (K): ";
    cin >> K;

    string dict[N];
    cout << "Enter the words in the dictionary:" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> dict[i];
    }

    Solution obj;
    string order = obj.findOrder(dict, N, K);

    if (order == "")
    {
        cout << "No valid order of characters found (possible cycle in graph)." << endl;
    }
    else
    {
        cout << "The order of characters in the alien language is: " << order << endl;
    }

    return 0;
}
