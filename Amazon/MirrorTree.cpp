/*
Example:
=========
Input:
Enter the root node value: 1
Enter the left child of 1 (-1 for NULL): 2
Enter the right child of 1 (-1 for NULL): 3
Enter the left child of 2 (-1 for NULL): -1
Enter the right child of 2 (-1 for NULL): -1
Enter the left child of 3 (-1 for NULL): -1
Enter the right child of 3 (-1 for NULL): -1

Output:
Building the binary tree:
Inorder traversal of the original tree: 2 1 3
Inorder traversal of the mirror tree: 3 1 2
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
    void mirror(Node *node)
    {
        if (node == nullptr)
            return;

        mirror(node->left);
        mirror(node->right);

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

void printInorder(Node *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

Node *insertLevelOrder()
{
    int val;
    cout << "Enter the root node value: ";
    cin >> val;

    if (val == -1)
        return nullptr;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter the left child of " << temp->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1)
        {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        cout << "Enter the right child of " << temp->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1)
        {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }
    return root;
}

int main()
{
    cout << "Building the binary tree:\n";
    Node *root = insertLevelOrder();

    cout << "\nInorder traversal of the original tree: ";
    printInorder(root);
    cout << endl;

    Solution solution;
    solution.mirror(root);

    cout << "Inorder traversal of the mirror tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
