/*
Examples:
----------
Input: root[] = [1, 2, 3]
Output: 2
Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

Input: root[] = [5, 8, 6, 3, 7, 9]
Output: 4
Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(struct Node* node, int* diameter) {
    if (node == NULL) {
        return 0;
    }
    
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);
    
    *diameter = fmax(*diameter, leftHeight + rightHeight);
    
    return 1 + fmax(leftHeight, rightHeight);
}

int diameter(struct Node* root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    printf("Diameter of the given tree is: %d\n", diameter(root));
    return 0;
}
