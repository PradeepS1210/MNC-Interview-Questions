/*
Example 1:
============
Enter elements of the binary tree in level order (use -1 for null nodes): 10 20 30 40 60 -1 -1
The tree is balanced.

Input:
       10
     /   \
    20   30
  /   \
 40   60

Explanation: The max difference in height of left subtree and right subtree is 1. Hence balanced.

Example 2:
============
Enter elements of the binary tree in level order (use -1 for null nodes): 1 2 -1 -1 3
The tree is not balanced.

Input:
      1
    /
   2
    \
     3

Explanation: The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced
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
    int checkHeight(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1)
            return -1;

        if (std::abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return std::max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(Node *root)
    {
        return checkHeight(root) != -1;
    }
};

Node *insertLevelOrder(std::vector<int> &arr, int i, int n)
{
    Node *root = nullptr;
    if (i < n && arr[i] != -1)
    {
        root = new Node(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main()
{
    Solution sol;
    std::string input;

    std::cout << "Enter elements of the binary tree in level order (use -1 for null nodes): ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<int> arr;
    int number;
    while (iss >> number)
    {
        arr.push_back(number);
    }

    Node *root = insertLevelOrder(arr, 0, arr.size());

    if (sol.isBalanced(root))
    {
        std::cout << "The tree is balanced." << std::endl;
    }
    else
    {
        std::cout << "The tree is not balanced." << std::endl;
    }

    return 0;
}
