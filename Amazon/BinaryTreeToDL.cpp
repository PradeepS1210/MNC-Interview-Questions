/*
Example:
===========
Input:
Enter node data (-1 for no node): 10
Enter left child of 10
Enter node data (-1 for no node): 20
Enter left child of 20
Enter node data (-1 for no node): 40
Enter left child of 40
Enter node data (-1 for no node): -1
Enter right child of 40
Enter node data (-1 for no node): -1
Enter right child of 20
Enter node data (-1 for no node): 60
Enter left child of 60
Enter node data (-1 for no node): -1
Enter right child of 60
Enter node data (-1 for no node): -1
Enter right child of 10
Enter node data (-1 for no node): 30
Enter left child of 30
Enter node data (-1 for no node): -1
Enter right child of 30
Enter node data (-1 for no node): -1

Output:
DLL in forward order: 40 20 60 10 30
DLL in reverse order: 30 10 60 20 40
*/

#include <iostream>
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
    Node *head = NULL;
    Node *prev = NULL;

    Node *bToDLL(Node *root)
    {
        if (root == NULL)
            return NULL;

        bToDLL(root->left);

        if (prev == NULL)
        {
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }

        prev = root;

        bToDLL(root->right);

        return head;
    }
};

void printList(Node *head)
{
    Node *last = NULL;
    cout << "DLL in forward order: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        last = head;
        head = head->right;
    }
    cout << endl;

    cout << "DLL in reverse order: ";
    while (last != NULL)
    {
        cout << last->data << " ";
        last = last->left;
    }
    cout << endl;
}

Node *buildTree()
{
    int data;
    cout << "Enter node data (-1 for no node): ";
    cin >> data;
    if (data == -1)
        return NULL;

    Node *newNode = new Node(data);
    cout << "Enter left child of " << data << endl;
    newNode->left = buildTree();
    cout << "Enter right child of " << data << endl;
    newNode->right = buildTree();
    return newNode;
}

int main()
{
    Solution sol;

    cout << "Build your binary tree:" << endl;
    Node *root = buildTree();

    Node *head = sol.bToDLL(root);

    printList(head);

    return 0;
}
