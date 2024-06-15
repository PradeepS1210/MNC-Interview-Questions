/*
Example 1:
============
Input:
   1
 /  \
3    2
Output: 1 3
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void dfs(Node *root, int level, int &maxLevel, vector<int> &result)
{
    if (!root)
        return;

    if (level > maxLevel)
    {
        result.push_back(root->data);
        maxLevel = level;
    }

    dfs(root->left, level + 1, maxLevel, result);
    dfs(root->right, level + 1, maxLevel, result);
}

vector<int> leftView(Node *root)
{
    vector<int> result;
    int maxLevel = -1;
    dfs(root, 0, maxLevel, result);
    return result;
}

Node *buildTree(int &nodeCount)
{
    cout << "Enter number of elements in the binary tree: ";
    cin >> nodeCount;

    if (nodeCount == 0)
    {
        return NULL;
    }

    cout << "Enter the root data: ";
    int rootData;
    cin >> rootData;

    Node *root = new Node(rootData);
    nodeCount--;

    queue<Node *> q;
    q.push(root);

    while (!q.empty() && nodeCount > 0)
    {
        Node *curr = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter left child of " << curr->data << " (-1 if no left child): ";
        cin >> leftData;
        if (leftData != -1)
        {
            curr->left = new Node(leftData);
            q.push(curr->left);
            nodeCount--;
        }

        cout << "Enter right child of " << curr->data << " (-1 if no right child): ";
        cin >> rightData;
        if (rightData != -1)
        {
            curr->right = new Node(rightData);
            q.push(curr->right);
            nodeCount--;
        }
    }

    return root;
}

int main()
{
    int nodeCount = 0;
    Node *root = buildTree(nodeCount);

    vector<int> result = leftView(root);

    cout << "Left view of the binary tree: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
