/*
Example 1:
============
Input:
Enter the number of nodes in the tree: 3
Enter the elements of the tree in level order (use -1 for NULL nodes): 1 2 3

Output: Diameter of the tree is: 3

Example 2:
============
Input:
Enter the number of nodes in the tree: 5
Enter the elements of the tree in level order (use -1 for NULL nodes): 10 20 30 40 60

Output: Diameter of the tree is: 4
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
    int diameter(Node *root)
    {
        int max_diameter = 0;
        height(root, max_diameter);
        return max_diameter;
    }

private:
    int height(Node *node, int &max_diameter)
    {
        if (node == NULL)
        {
            return 0;
        }

        int left_height = height(node->left, max_diameter);
        int right_height = height(node->right, max_diameter);

        max_diameter = max(max_diameter, left_height + right_height + 1);

        return max(left_height, right_height) + 1;
    }
};

Node *insertLevelOrder(int arr[], int i, int n)
{
    Node *root = nullptr;
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
    cout << "Enter the elements of the tree in level order (use -1 for NULL nodes): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int validElements = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            validElements++;
        }
    }

    int newArr[validElements];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            newArr[j++] = arr[i];
        }
    }

    Node *root = insertLevelOrder(newArr, 0, validElements);

    Solution solution;
    int diameter = solution.diameter(root);
    cout << "Diameter of the tree is: " << diameter << endl;

    return 0;
}
