/*
Example:
=========
Input:
Enter the number of nodes in the tree: 7
Enter the value for the root node: 1
Enter the values for the remaining 6 nodes: 2 3 4 5 6 7

Output: Level order traversal: 1 2 3 4 5 6 7
Explanation:
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

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
    vector<int> levelOrder(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            result.push_back(node->data);

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }

        return result;
    }
};

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = new Node(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = new Node(data);
            return root;
        }
    }

    return root;
}

int main()
{
    Solution solution;

    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Tree is empty." << endl;
        return 0;
    }

    int rootData;
    cout << "Enter the value for the root node: ";
    cin >> rootData;

    Node *root = new Node(rootData);

    cout << "Enter the values for the remaining " << (n - 1) << " nodes: ";
    for (int i = 0; i < n - 1; ++i)
    {
        int data;
        cin >> data;
        insertNode(root, data);
    }

    vector<int> result = solution.levelOrder(root);

    cout << "Level order traversal: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
