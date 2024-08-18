/*
Example:
=========
Input:
Enter the number of nodes in the tree: 7
Enter the node values in level order: 1 2 3 4 5 6 7
Enter the first node value: 4
Enter the second node value: 5

Output: LCA of 4 and 5 is: 2
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        Node *leftLCA = lca(root->left, n1, n2);
        Node *rightLCA = lca(root->right, n1, n2);

        if (leftLCA != NULL && rightLCA != NULL)
            return root;

        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }
};

Node *insertLevelOrder(int arr[], int i, int n)
{
    Node *root = NULL;
    if (i < n)
    {
        root = new Node(arr[i]);

        root->left = insertLevelOrder(arr, 2 * i + 1, n);

        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main()
{
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    int arr[n];
    cout << "Enter the node values in level order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = insertLevelOrder(arr, 0, n);

    int n1, n2;
    cout << "Enter the first node value: ";
    cin >> n1;
    cout << "Enter the second node value: ";
    cin >> n2;

    Solution sol;
    Node *lcaNode = sol.lca(root, n1, n2);

    if (lcaNode != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lcaNode->data << endl;
    else
        cout << "LCA does not exist (one or both nodes are not in the tree)" << endl;

    return 0;
}
