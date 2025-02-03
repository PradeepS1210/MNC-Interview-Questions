/*
Examples:
----------
Input: root[] = [12, 8, 18, 5, 11] 
Output: 2
Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.

Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]
Output: 3
Explanation: The longest path from the root (node 1) to a leaf node 6 with 3 edge.
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

int height(struct Node* node) {
    if (node == NULL) {
        return -1;
    }
    
    int left_height = height(node->left);
    int right_height = height(node->right);
    
    return (left_height > right_height ? left_height : right_height) + 1;
}

struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    if (i < n) {
        root = newNode(arr[i]);
        
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the values of nodes in level order (use -1 for NULL nodes):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = insertLevelOrder(arr, 0, n);
    printf("Height of the tree is: %d\n", height(root));
    return 0;
}
