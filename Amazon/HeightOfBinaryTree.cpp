/*
Example 1:
============

Input: Enter the tree in level order (space-separated, use 'N' for NULL nodes): 1 2 3 N N 4 5
Output: Height of the tree: 3
Explanation:
     1
    / \
   2   3
      / \
     4   5

Example 2:
============

Input: Enter the tree in level order (space-separated, use 'N' for NULL nodes): 2 N 1 3
Output: Height of the tree: 3

Explanation:
     2
      \
       1
      /
     3

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int height(struct Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    string treeString;
    cout << "Enter the tree in level order (space-separated, use 'N' for NULL nodes): ";
    getline(cin, treeString);
    Node *root = buildTree(treeString);

    Solution sol;
    int treeHeight = sol.height(root);
    cout << "Height of the tree: " << treeHeight << endl;

    return 0;
}
