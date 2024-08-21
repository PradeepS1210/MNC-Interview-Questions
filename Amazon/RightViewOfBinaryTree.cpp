/*
Example:
=========
          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Output: Right View of the Binary Tree: 1 3 7 8
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
    vector<int> rightView(Node *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (i == n)
                    result.push_back(temp->data);

                if (temp->left != NULL)
                    q.push(temp->left);

                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }

        return result;
    }
};

Node *newNode(int data)
{
    Node *node = new Node(data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->right = newNode(8);

    Solution ob;
    vector<int> rightViewResult = ob.rightView(root);

    cout << "Right View of the Binary Tree: ";
    for (int i : rightViewResult)
        cout << i << " ";
    cout << endl;

    return 0;
}
