/*
Example 1:
============
Input:
        2
       /  \
      1    3
            \
             5
Output: true
Explanation: The left subtree of every node contains smaller keys and right subtree of every node contains greater.Hence, the tree is a BST.

Example 2:
============
Input:
        10
       /  \
      5    20
          /  \
          9  25
Output: false
Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isBSTUtil(Node *root, int minValue, int maxValue)
    {
        if (root == nullptr)
            return true;

        if (root->data <= minValue || root->data >= maxValue)
            return false;

        return isBSTUtil(root->left, minValue, root->data) &&
               isBSTUtil(root->right, root->data, maxValue);
    }

    bool isBST(Node *root)
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

Node *buildTree(std::vector<int> &nodes, int idx, int n)
{
    if (idx < n && nodes[idx] != -1)
    {
        Node *root = new Node(nodes[idx]);
        root->left = buildTree(nodes, 2 * idx + 1, n);
        root->right = buildTree(nodes, 2 * idx + 2, n);
        return root;
    }
    return nullptr;
}

void deleteTree(Node *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main()
{
    int n;
    std::cout << "Enter the number of nodes in the binary tree: ";
    std::cin >> n;

    std::vector<int> nodes(n);
    std::cout << "Enter the nodes of the binary tree (enter -1 for null nodes):\n";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nodes[i];
    }

    Node *root = buildTree(nodes, 0, n);

    Solution solution;
    bool isBST = solution.isBST(root);

    if (isBST)
    {
        std::cout << "The binary tree is a Binary Search Tree (BST).\n";
    }
    else
    {
        std::cout << "The binary tree is not a Binary Search Tree (BST).\n";
    }

    deleteTree(root);

    return 0;
}
