/*
Example:
==========
Input:
Building Tree 1
Enter node value (-1 for NULL): 1
Enter left child of 1
Enter node value (-1 for NULL): 2
Enter left child of 2
Enter node value (-1 for NULL): -1
Enter right child of 2
Enter node value (-1 for NULL): -1
Enter right child of 1
Enter node value (-1 for NULL): 3
Enter left child of 3
Enter node value (-1 for NULL): -1
Enter right child of 3
Enter node value (-1 for NULL): -1

Building Tree 2
Enter node value (-1 for NULL): 1
Enter left child of 1
Enter node value (-1 for NULL): 2
Enter left child of 2
Enter node value (-1 for NULL): -1
Enter right child of 2
Enter node value (-1 for NULL): -1
Enter right child of 1
Enter node value (-1 for NULL): 3
Enter left child of 3
Enter node value (-1 for NULL): -1
Enter right child of 3
Enter node value (-1 for NULL): -1

Output: Yes

Explanation:
For Tree 1:
    1
   / \
  2   3

For Tree 2:
    1
   / \
  2   3

Both trees have the same structure and the same node values, so they are identical.
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
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;

        if (r1 == NULL || r2 == NULL)
            return false;

        return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};

Node *buildTree()
{
    int data;
    cout << "Enter node value (-1 for NULL): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *newNode = new Node(data);
    cout << "Enter left child of " << data << endl;
    newNode->left = buildTree();
    cout << "Enter right child of " << data << endl;
    newNode->right = buildTree();

    return newNode;
}

int main()
{
    cout << "Building Tree 1" << endl;
    Node *root1 = buildTree();

    cout << "Building Tree 2" << endl;
    Node *root2 = buildTree();

    Solution sol;
    if (sol.isIdentical(root1, root2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
