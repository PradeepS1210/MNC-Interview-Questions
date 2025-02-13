/*
Examples:
-----------
Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
Output: True

Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
Output: False
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    bool findTarget(Node *root, int target) {
        unordered_set<int> set;
        return find(root, set, target);
    }

  private:
    bool find(Node* node, unordered_set<int>& set, int target) {
        if (!node) return false;
        if (set.count(target - node->data)) return true;
        set.insert(node->data);
        return find(node->left, set, target) || find(node->right, set, target);
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* buildBST() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node* root = nullptr;
    cout << "Enter node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }
    return root;
}

int main() {
    Node* root = buildBST();
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    Solution solution;
    if (solution.findTarget(root, target)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}
