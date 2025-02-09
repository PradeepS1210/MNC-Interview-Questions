/*
Examples:
----------
Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
Output: 42

Input: root[] = [-17, 11, 4, 20, -2, 10]
Output: 31
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int findMaxSum(Node* root) {
        int maxSum = INT_MIN;
        findMaxUtil(root, maxSum);
        return maxSum;
    }

  private:
    int findMaxUtil(Node* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftMax = max(findMaxUtil(node->left, maxSum), 0);
        int rightMax = max(findMaxUtil(node->right, maxSum), 0);

        int currentMax = node->data + leftMax + rightMax;

        maxSum = max(maxSum, currentMax);

        return node->data + max(leftMax, rightMax);
    }
};

Node* buildTree() {
    cout << "Enter the value of the node (or -1 to indicate no node): ";
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    cout << "Enter the left child of " << val << endl;
    root->left = buildTree();
    cout << "Enter the right child of " << val << endl;
    root->right = buildTree();
    return root;
}

int main() {
    cout << "Build the binary tree:" << endl;
    Node* root = buildTree();

    Solution solution;
    int maxPathSum = solution.findMaxSum(root);
    cout << "Maximum path sum in the binary tree: " << maxPathSum << endl;

    return 0;
}
