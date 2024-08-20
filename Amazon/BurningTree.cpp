/*
Example:
==========
Enter the number of nodes in the binary tree: 10
Enter the nodes values (use -1 for NULL nodes): 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 -1 -1 10
Enter the target node: 8
Minimum time required to burn the tree: 7 seconds
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    Node *findTarget(Node *root, int target, unordered_map<Node *, Node *> &parentMap)
    {
        queue<Node *> q;
        q.push(root);
        Node *targetNode = nullptr;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
            {
                targetNode = curr;
            }

            if (curr->left)
            {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    int burnTree(Node *targetNode, unordered_map<Node *, Node *> &parentMap)
    {
        queue<Node *> q;
        unordered_map<Node *, bool> visited;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left])
                {
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !visited[curr->right])
                {
                    flag = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if (parentMap[curr] && !visited[parentMap[curr]])
                {
                    flag = true;
                    visited[parentMap[curr]] = true;
                    q.push(parentMap[curr]);
                }
            }

            if (flag)
            {
                time++;
            }
        }

        return time;
    }

    int minTime(Node *root, int target)
    {
        if (!root)
            return 0;

        unordered_map<Node *, Node *> parentMap;
        Node *targetNode = findTarget(root, target, parentMap);

        return burnTree(targetNode, parentMap);
    }
};

Node *newNode(int val)
{
    return new Node(val);
}

Node *insertLevelOrder(int arr[], int i, int n)
{
    Node *root = nullptr;
    if (i < n)
    {
        root = newNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main()
{
    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    int arr[n];
    cout << "Enter the nodes values (use -1 for NULL nodes): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target node: ";
    cin >> target;

    Node *root = insertLevelOrder(arr, 0, n);

    Solution sol;
    int result = sol.minTime(root, target);
    cout << "Minimum time required to burn the tree: " << result << " seconds" << endl;

    return 0;
}
