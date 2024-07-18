/*
Example:
==========
Input:
Enter the number of nodes: 8
Enter node data and its left and right children indices (use -1 for NULL):
20 1 2
8 3 4
22 -1 5
5 -1 -1
3 6 7
25 -1 -1
10 -1 -1
14 -1 -1

Output: Bottom view of the tree is: 5 10 3 14 25
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        map<int, int> hdNodeMap;
        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            Node *node = p.first;
            int hd = p.second;

            hdNodeMap[hd] = node->data;

            if (node->left != NULL)
            {
                q.push(make_pair(node->left, hd - 1));
            }

            if (node->right != NULL)
            {
                q.push(make_pair(node->right, hd + 1));
            }
        }

        for (auto it : hdNodeMap)
        {
            result.push_back(it.second);
        }

        return result;
    }
};

Node *newNode(int data)
{
    Node *node = new Node(data);
    return node;
}

Node *buildTree()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n == 0)
        return NULL;

    map<int, Node *> nodes;
    int data, left, right;
    cout << "Enter node data and its left and right children indices (use -1 for NULL):\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> data >> left >> right;
        if (nodes.find(i) == nodes.end())
        {
            nodes[i] = newNode(data);
        }
        else
        {
            nodes[i]->data = data;
        }

        if (left != -1)
        {
            nodes[left] = newNode(0);
            nodes[i]->left = nodes[left];
        }
        if (right != -1)
        {
            nodes[right] = newNode(0);
            nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

int main()
{
    Node *root = buildTree();

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom view of the tree is: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
