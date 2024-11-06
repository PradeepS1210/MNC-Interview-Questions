#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int treePathsSumUtil(Node* node, int currentSum) {
        if (node == NULL)
            return 0;

        currentSum = currentSum * 10 + node->data;

        if (node->left == NULL && node->right == NULL)
            return currentSum;

        int leftSum = treePathsSumUtil(node->left, currentSum);
        int rightSum = treePathsSumUtil(node->right, currentSum);

        return leftSum + rightSum;
    }

    int treePathsSum(Node* root) {
        return treePathsSumUtil(root, 0);
    }
};

Node* buildTree() {
    int data;
    cout << "Enter root value (or -1 for NULL): ";
    cin >> data;

    if (data == -1) return NULL;

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter left child of " << current->data << " (or -1 for NULL): ";
        cin >> leftData;
        if (leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (or -1 for NULL): ";
        cin >> rightData;
        if (rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }
    
    return root;
}

int main() {
    Node* root = buildTree();

    Solution solution;
    int result = solution.treePathsSum(root);
    cout << "Sum of all numbers formed from root to leaf paths: " << result << endl;

    return 0;
}
