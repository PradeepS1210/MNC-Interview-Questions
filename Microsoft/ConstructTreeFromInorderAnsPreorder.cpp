/*
Examples:
----------
Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]

Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [3, 4, 1, 5, 2, 0]

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [2, 5, 4, 3, 1]
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> inorderMap;

    Node* buildTreeUtil(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return NULL;
        }

        int curr = preorder[preIndex++];
        Node* node = new Node(curr);

        if (inStart == inEnd) {
            return node;
        }

        int inIndex = inorderMap[curr];

        node->left = buildTreeUtil(inorder, preorder, inStart, inIndex - 1);
        node->right = buildTreeUtil(inorder, preorder, inIndex + 1, inEnd);

        return node;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeUtil(inorder, preorder, 0, inorder.size() - 1);
    }

    void printPostorder(Node* node) {
        if (node == NULL) {
            return;
        }
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    Solution solution;

    vector<int> inorder = {2, 5, 4, 1, 3};
    vector<int> preorder = {1, 4, 5, 2, 3};

    Node* root = solution.buildTree(inorder, preorder);

    cout << "Postorder traversal of the constructed tree is: ";
    solution.printPostorder(root);
    cout << endl;

    return 0;
}
